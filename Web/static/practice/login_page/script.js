const registerSwitch = document.getElementById('register-switch')
const loginSwitch = document.getElementById('login-switch')
const container = document.getElementById('container')

registerSwitch.addEventListener('click', ()=>{
	container.classList.add("register-enabled")
})

loginSwitch.addEventListener('click', ()=>{
	container.classList.remove('register-enabled')
})