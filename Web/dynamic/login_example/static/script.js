const registerSwitch = document.getElementById('register-switch')
const loginSwitch = document.getElementById('login-switch')
const registerForm = document.getElementById('register-form')
const loginForm = document.getElementById('login-form')

registerSwitch.addEventListener('click', ()=>{
	const registerSwitchTop = registerSwitch.getBoundingClientRect().top - loginForm.getBoundingClientRect().top + registerSwitch.getBoundingClientRect().height / 2
	const reigsterSwitchLeft = registerSwitch.getBoundingClientRect().left - loginForm.getBoundingClientRect().left + registerSwitch.getBoundingClientRect().width / 2
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
		const loginSwitchTop = loginSwitch.getBoundingClientRect().top - registerForm.getBoundingClientRect().top + loginSwitch.getBoundingClientRect().height / 2
		const loginSwitchLeft = loginSwitch.getBoundingClientRect().left - registerForm.getBoundingClientRect().left + loginSwitch.getBoundingClientRect().width / 2
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
	const loginSwitchTop = loginSwitch.getBoundingClientRect().top - registerForm.getBoundingClientRect().top + loginSwitch.getBoundingClientRect().height / 2
	const loginSwitchLeft = loginSwitch.getBoundingClientRect().left - registerForm.getBoundingClientRect().left + loginSwitch.getBoundingClientRect().width / 2
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
		const registerSwitchTop = registerSwitch.getBoundingClientRect().top - loginForm.getBoundingClientRect().top + registerSwitch.getBoundingClientRect().height / 2
		const reigsterSwitchLeft = registerSwitch.getBoundingClientRect().left - loginForm.getBoundingClientRect().left + registerSwitch.getBoundingClientRect().width / 2
		fadeSpan.style.top = registerSwitchTop + 'px'
		fadeSpan.style.left = reigsterSwitchLeft + 'px'
		fadeSpan.style.animation = 'circle-fade .25s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})