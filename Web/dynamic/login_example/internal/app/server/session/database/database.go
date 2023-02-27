package database

import (
	"database/sql"
	"login_example/internal/app/server/session"
	"sync"
	"time"
)

type SessionStore struct {
	sid          string
	timeAccessed time.Time
	value        map[interface{}]interface{}
}

func (st *SessionStore) Set(Key, Value interface{}) error {

}
func (st *SessionStore) Get(Key interface{}) interface{} {

}
func (st *SessionStore) Delete(Key interface{}) error {

}
func (st *SessionStore) SessionID() string {

}

type Provider struct {
	lock sync.Mutex // 用来锁
	db   *sql.DB    // 用来访问数据库
}

func (providers *Provider) SessionInit(sid string) (session.Session, error) {
	providers.lock.Lock()
	defer providers.lock.Unlock()

}
func (providers *Provider) SessionRead(sid string) (session.Session, error) {
	providers.lock.Lock()
	defer providers.lock.Unlock()
}
func (providers *Provider) SessionDestroy(sid string) error {

}
func (providers *Provider) SessionGC(maxLifeTime int64) {

}
func (providers *Provider) SessionUpdate(sid string) error {

}

var providers = &Provider{}

func init() {
	db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1:3306)/test_db?charset=utf8mb4&parseTime=true&loc=Asia%2FShanghai")
	if err != nil {
		panic("数据库连接失败")
	}
	session.Register("database", _)
}
