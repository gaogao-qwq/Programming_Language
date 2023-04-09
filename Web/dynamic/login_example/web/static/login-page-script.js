const registerSwitch = document.getElementById('register-switch')
const loginSwitch = document.getElementById('login-switch')
const backSwitch = document.getElementById('back-switch')
const forgetSwitch = document.getElementById('forget-switch')

const registerForm = document.getElementById('register-form')
const loginForm = document.getElementById('login-form')
const forgetForm = document.getElementById('forget-form')

function getSwitchTop(form, switcher) {
	return switcher.getBoundingClientRect().top - form.getBoundingClientRect().top + switcher.getBoundingClientRect().height / 2
}

function getSwitchLeft(form, switcher) {
	return switcher.getBoundingClientRect().left - form.getBoundingClientRect().left + switcher.getBoundingClientRect().width / 2
}

registerSwitch.addEventListener('click', ()=>{
	const registerSwitchTop = getSwitchTop(loginForm, registerSwitch)
	const reigsterSwitchLeft = getSwitchLeft(loginForm, registerSwitch)
	let fillSpan = document.createElement('span')
	let fadeSpan = document.createElement('span')

	loginForm.appendChild(fillSpan)
	registerForm.appendChild(fadeSpan)
	fillSpan.style.top = registerSwitchTop + 'px'
	fillSpan.style.left = reigsterSwitchLeft + 'px'
	fillSpan.style.animation = 'circle-fill .25s ease-out forwards'

	fillSpan.addEventListener('animationend', ()=>{
		registerForm.style.display = 'flex'
		loginForm.style.display = 'none'
		const loginSwitchTop = getSwitchTop(registerForm, loginSwitch)
		const loginSwitchLeft = getSwitchLeft(registerForm, loginSwitch)
		fadeSpan.style.top = loginSwitchTop + 'px'
		fadeSpan.style.left = loginSwitchLeft + 'px'
		fadeSpan.style.animation = 'circle-fade .25s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})

loginSwitch.addEventListener('click', ()=>{
	const loginSwitchTop = getSwitchTop(registerForm, loginSwitch)
	const loginSwitchLeft = getSwitchLeft(registerForm, loginSwitch)
	let fillSpan = document.createElement('span')
	let fadeSpan = document.createElement('span')
	
	loginForm.appendChild(fadeSpan)
	registerForm.appendChild(fillSpan)
	fillSpan.style.top = loginSwitchTop + 'px'
	fillSpan.style.left = loginSwitchLeft + 'px'
	fillSpan.style.animation = 'circle-fill .25s ease-out forwards'

	fillSpan.addEventListener('animationend', ()=>{
		registerForm.style.display = 'none'
		loginForm.style.display = 'flex'
		const registerSwitchTop = getSwitchTop(loginForm, registerSwitch)
		const reigsterSwitchLeft = getSwitchLeft(loginForm, registerSwitch)
		fadeSpan.style.top = registerSwitchTop + 'px'
		fadeSpan.style.left = reigsterSwitchLeft + 'px'
		fadeSpan.style.animation = 'circle-fade .25s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})

forgetSwitch.addEventListener('click', ()=>{
	const forgetSwitchTop = getSwitchTop(loginForm, forgetSwitch)
	const forgetSwitchLeft = getSwitchLeft(loginForm, forgetSwitch)
	let fillSpan = document.createElement('span')
	let fadeSpan = document.createElement('span')
	
	forgetForm.appendChild(fadeSpan)
	loginForm.appendChild(fillSpan)
	fillSpan.style.top = forgetSwitchTop + 'px'
	fillSpan.style.left = forgetSwitchLeft + 'px'
	fillSpan.style.animation = 'circle-fill .25s ease-out forwards'

	fillSpan.addEventListener('animationend', ()=>{
		loginForm.style.display = 'none'
		forgetForm.style.display = 'flex'
		const backSwitchTop = getSwitchTop(forgetForm, backSwitch)
		const backSwitchLeft = getSwitchLeft(forgetForm, backSwitch)
		fadeSpan.style.top = backSwitchTop + 'px'
		fadeSpan.style.left = backSwitchLeft + 'px'
		fadeSpan.style.animation = 'circle-fade .25s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})

backSwitch.addEventListener('click', ()=>{
	const backSwitchTop = getSwitchTop(forgetForm, backSwitch)
	const backSwitchLeft = getSwitchLeft(forgetForm, backSwitch)
	let fillSpan = document.createElement('span')
	let fadeSpan = document.createElement('span')

	loginForm.appendChild(fadeSpan)
	forgetForm.appendChild(fillSpan)
	fillSpan.style.top = backSwitchTop + 'px'
	fillSpan.style.left = backSwitchLeft + 'px'
	fillSpan.style.animation = 'circle-fill .25s ease-out forwards'

	fillSpan.addEventListener('animationend', ()=>{
		forgetForm.style.display = 'none'
		loginForm.style.display = 'flex'
		const forgetSwitchTop = getSwitchTop(loginForm, forgetSwitch)
		const forgetSwitchLeft = getSwitchLeft(loginForm, forgetSwitch)
		fadeSpan.style.top = forgetSwitchTop + 'px'
		fadeSpan.style.left = forgetSwitchLeft + 'px'
		fadeSpan.style.animation = 'circle-fade .25s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})
