package memory

import (
	"container/list"
	"login_example/internal/app/server/session"
	"sync"
	"time"
)

type SessionStore struct {
	sid          string                      //session id唯一标示
	timeAccessed time.Time                   //最后访问时间
	value        map[interface{}]interface{} //session里面存储的值
}

func (st *SessionStore) Set(key, value interface{}) error {
	st.value[key] = value
	err := providers.SessionUpdate(st.sid)
	if err != nil {
		return err
	}
	return nil
}
func (st *SessionStore) Get(key interface{}) interface{} {
	err := providers.SessionUpdate(st.sid)
	if err != nil {
		return nil
	}
	if v, ok := st.value[key]; ok {
		return v
	} else {
		return nil
	}
}
func (st *SessionStore) Delete(key interface{}) error {
	delete(st.value, key)
	err := providers.SessionUpdate(st.sid)
	if err != nil {
		return err
	}
	return nil
}
func (st *SessionStore) SessionID() string {
	return st.sid
}

type Provider struct {
	lock     sync.Mutex               // 用来锁
	sessions map[string]*list.Element // 用来存储在内存
	list     *list.List               // 用来做gc
}

func (providers *Provider) SessionInit(sid string) (session.Session, error) {
	providers.lock.Lock()
	defer providers.lock.Unlock()
	v := make(map[interface{}]interface{}, 0)
	newSession := &SessionStore{
		sid:          sid,
		timeAccessed: time.Now(),
		value:        v,
	}
	element := providers.list.PushBack(newSession)
	providers.sessions[sid] = element
	return newSession, nil
}
func (providers *Provider) SessionRead(sid string) (session.Session, error) {
	if element, ok := providers.sessions[sid]; ok {
		return element.Value.(*SessionStore), nil
	} else {
		sess, err := providers.SessionInit(sid)
		return sess, err
	}
}
func (providers *Provider) SessionDestroy(sid string) error {
	if element, ok := providers.sessions[sid]; ok {
		delete(providers.sessions, sid)
		providers.list.Remove(element)
		return nil
	}
	return nil
}
func (providers *Provider) SessionGC(maxLifeTime int64) {
	providers.lock.Lock()
	defer providers.lock.Unlock()

	for {
		element := providers.list.Back()
		if element == nil {
			break
		}
		if (element.Value.(*SessionStore).timeAccessed.Unix() + maxLifeTime) < time.Now().Unix() {
			providers.list.Remove(element)
			delete(providers.sessions, element.Value.(*SessionStore).sid)
		} else {
			break
		}
	}
}
func (providers *Provider) SessionUpdate(sid string) error {
	providers.lock.Lock()
	defer providers.lock.Unlock()
	if element, ok := providers.sessions[sid]; ok {
		element.Value.(*SessionStore).timeAccessed = time.Now()
		providers.list.MoveToFront(element)
		return nil
	}
	return nil
}

var providers = &Provider{list: list.New()}

func init() {
	providers.sessions = make(map[string]*list.Element, 0)
	session.Register("memory", providers)
}
