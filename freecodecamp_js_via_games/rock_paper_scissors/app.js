const comp_choice_display = document.getElementById('computer-choice')
const user_choice_display = document.getElementById('user-choice')
const result_display = document.getElementById('result')
const choices = document.querySelectorAll('button')

choices.forEach(choice => choice.addEventListener(
    'click',
    (e) => {
        user_choice_display.innerHTML = e.target.id
        genComputerChoice()
    }
)
)

function genComputerChoice() {
    const randomNum = Math.floor(Math.random() * choices.length)
    comp_choice_display.innerHTML = choices[randomNum].id
}
