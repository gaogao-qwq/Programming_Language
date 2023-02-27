const registerSwitch = document.getElementById('register-switch')
const loginSwitch = document.getElementById('login-switch')
const backSwitch = document.getElementById('back-switch')
const forgetSwitch = document.getElementById('forget-switch')

const registerForm = document.getElementById('register-form')
const loginForm = document.getElementById('login-form')
const forgetForm = document.getElementById('forget-form')

registerSwitch.addEventListener('click', ()=>{
	const registerSwitchTop = registerSwitch.getBoundingClientRect().top -
							  loginForm.getBoundingClientRect().top +
							  registerSwitch.getBoundingClientRect().height / 2
	const reigsterSwitchLeft = registerSwitch.getBoundingClientRect().left -
							   loginForm.getBoundingClientRect().left +
							   registerSwitch.getBoundingClientRect().width / 2
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
		const loginSwitchTop = loginSwitch.getBoundingClientRect().top -
							   registerForm.getBoundingClientRect().top +
							   loginSwitch.getBoundingClientRect().height / 2
		const loginSwitchLeft = loginSwitch.getBoundingClientRect().left -
								registerForm.getBoundingClientRect().left +
								loginSwitch.getBoundingClientRect().width / 2
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
	const loginSwitchTop = loginSwitch.getBoundingClientRect().top -
						   registerForm.getBoundingClientRect().top +
						   loginSwitch.getBoundingClientRect().height / 2
	const loginSwitchLeft = loginSwitch.getBoundingClientRect().left -
							registerForm.getBoundingClientRect().left +
							loginSwitch.getBoundingClientRect().width / 2
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
		const registerSwitchTop = registerSwitch.getBoundingClientRect().top -
								  loginForm.getBoundingClientRect().top +
								  registerSwitch.getBoundingClientRect().height / 2
		const reigsterSwitchLeft = registerSwitch.getBoundingClientRect().left -
								   loginForm.getBoundingClientRect().left +
								   registerSwitch.getBoundingClientRect().width / 2
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
	const forgetSwitchTop = forgetSwitch.getBoundingClientRect().top -
							loginForm.getBoundingClientRect().top +
							forgetSwitch.getBoundingClientRect().height / 2
	const forgetSwitchLeft = forgetSwitch.getBoundingClientRect().left -
							 loginForm.getBoundingClientRect().left +
							 forgetSwitch.getBoundingClientRect().width / 2
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
		const backSwitchTop = backSwitch.getBoundingClientRect().top -
							  forgetForm.getBoundingClientRect().top +
							  backSwitch.getBoundingClientRect().height / 2
		const backSwitchLeft = backSwitch.getBoundingClientRect().left -
							   forgetForm.getBoundingClientRect().left +
							   backSwitch.getBoundingClientRect().width / 2
		fadeSpan.style.top = backSwitchTop + 'px'
		fadeSpan.style.left = backSwitchLeft + 'px'
		fadeSpan.style.animation = 'circle-fade .25s ease-out farwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})

backSwitch.addEventListener('click', ()=>{
	const backSwitchTop = backSwitch.getBoundingClientRect().top -
						  forgetForm.getBoundingClientRect().top +
						  backSwitch.getBoundingClientRect().height / 2
	const backSwitchLeft = backSwitch.getBoundingClientRect().left -
						   forgetForm.getBoundingClientRect().left +
						   backSwitch.getBoundingClientRect().width / 2
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
		const forgetSwitchTop = loginSwitch.getBoundingClientRect().top -
							  loginForm.getBoundingClientRect().top +
							  backSwitch.getBoundingClientRect().height / 2
		const backSwitchLeft = loginSwitch.getBoundingClientRect().left -
							   loginForm.getBoundingClientRect().left +
							   backSwitch.getBoundingClientRect().width / 2
		fadeSpan.style.top = backSwitchTop + 'px'
		fadeSpan.style.left = backSwitchLeft + 'px'
		fadeSpan.style.animation = 'circle-fade .25s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})
