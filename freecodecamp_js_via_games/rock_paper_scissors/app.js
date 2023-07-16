const comp_choice_display = document.getElementById('computer-choice')
const user_choice_display = document.getElementById('user-choice')
const result_display = document.getElementById('result')
const choices = document.querySelectorAll('button')

choices.forEach(choice => choice.addEventListener(
    'click',
    (e) => {
        user_choice_display.innerHTML = e.target.id
        genComputerChoice()
        showResult()
    }
)
)

function genComputerChoice() {
    const randomNum = Math.floor(Math.random() * choices.length)
    comp_choice_display.innerHTML = choices[randomNum].id
}

function showResult() {
    let result
    const computer_choice = comp_choice_display.innerHTML;
    const user_choice = user_choice_display.innerHTML;
    
    if (computer_choice === user_choice) {
        result_display.innerHTML = "Draw!!!"
        return
    }

    const uwin_txt = 'You win!!!'
    const iwin_txt = 'Computer wins!!!'
    
    switch(computer_choice) {
        case "rock":
            if (user_choice === 'paper') result = uwin_txt
            else if (user_choice === 'scissors') result = iwin_txt
            break            
        case "scissors":
            if (user_choice === 'paper') result = iwin_txt
            else if (user_choice === 'rock') result = uwin_txt
            break 
        default:
            if (user_choice === 'scissors') result = uwin_txt
            else if (user_choice === 'rock') result = iwin_txt
    }

    result_display.innerHTML = result
}
