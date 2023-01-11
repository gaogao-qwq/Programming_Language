const registerSwitch = document.getElementById('register-switch')
const loginSwitch = document.getElementById('login-switch')
const container = document.getElementById('container')
const registerForm = document.getElementById('register-form')
const loginForm = document.getElementById('login-form')

const switchTop = registerSwitch.getBoundingClientRect().top - loginForm.getBoundingClientRect().top + registerSwitch.getBoundingClientRect().height / 2
const switchLeft = registerSwitch.getBoundingClientRect().left - loginForm.getBoundingClientRect().left + registerSwitch.getBoundingClientRect().width / 2

registerSwitch.addEventListener('click', ()=>{
	let fillSpan = document.createElement('span')
	let fadeSpan = document.createElement('span')
	
	fillSpan.style.top = switchTop + 'px'
	fillSpan.style.left = switchLeft + 'px'
	fadeSpan.style.top = switchTop + 'px'
	fadeSpan.style.left = switchLeft + 'px'

	loginForm.appendChild(fillSpan)
	registerForm.appendChild(fadeSpan)
	fillSpan.style.animation = 'circle-fill .5s ease-out forwards'

	fillSpan.addEventListener('animationend', ()=>{
		registerForm.style.display = 'flex'
		loginForm.style.display = 'none'
		fadeSpan.style.animation = 'circle-fade .5s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})

loginSwitch.addEventListener('click', ()=>{
	let fillSpan = document.createElement('span')
	let fadeSpan = document.createElement('span')

	fillSpan.style.top = switchTop + 'px'
	fillSpan.style.left = switchLeft + 'px'
	fadeSpan.style.top = switchTop + 'px'
	fadeSpan.style.left = switchLeft + 'px'

	loginForm.appendChild(fadeSpan)
	registerForm.appendChild(fillSpan)
	fillSpan.style.animation = 'circle-fill .5s ease-out forwards'

	fillSpan.addEventListener('animationend', ()=>{
		registerForm.style.display = 'none'
		loginForm.style.display = 'flex'
		fadeSpan.style.animation = 'circle-fade .5s ease-out forwards'
		fillSpan.remove()
	})
	fadeSpan.addEventListener('animationend', ()=>{
		fadeSpan.remove()
	})
})