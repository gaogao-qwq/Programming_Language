let items = document.getElementsByTagName("li")

for (let i = 0; i < items.length; i++) {
    items[i].addEventListener("click", () => {
        items[i].classList.toggle("done")
    })
}