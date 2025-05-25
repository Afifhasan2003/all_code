let allBoxes = document.querySelectorAll(".box")
let restartBtn = document.querySelector("#restratBtn")
let resetBtn = document.querySelector("#resetBtn")
let restartGame = document.querySelector(".restartGame")
let msg = document.querySelector("#msg")
let turnO=true;
let count = 0

const winPatterns = [
    [0, 1, 2],
    [0, 3, 6],
    [0, 4, 8],
    [1, 4, 7],
    [2, 5, 8],
    [2, 4, 6],
    [3, 4, 5],
    [6, 7, 8],
];

const resetGame = () =>{
    count =0;
    enableAllButn();
    turnO = true;
    restartGame.classList.add("hide")
}

const checkWinner = ()=>{

    for(let pattern of winPatterns){

        let value1 = allBoxes[pattern[0]].innerText
        let value2 = allBoxes[pattern[1]].innerText
        let value3 = allBoxes[pattern[2]].innerText
        
        
        if(value1 !=='' && value2 !=='' && value3 !=='')
            if(value1===value2 && value1===value3){
                showWinner(value1)
                disableAllButn()
                return true;
            }
        }
}



const showWinner = (winner)=>{
    msg.innerText = `Congratulations!! Winner is ${winner}`
    restartGame.classList.remove("hide")

}








allBoxes.forEach((box=>{
    box.addEventListener("click",()=>{
       if(turnO) {
        box.innerHTML='<p style="color: rgb(201, 70, 70);">O</p>'
        turnO = false
        }
       else {
        box.innerHTML ='<p style="color: rgb(49, 121, 189);">X</p>'
        turnO = true
        }
        count++
        let didWon= checkWinner()
        box.disabled = true;

        if(count===9 && !didWon){
            msg.innerText = `The match is draw! `
            restartGame.classList.remove("hide")
        }

    })
}))





const enableAllButn = () =>{
    for(box of allBoxes){
        box.disabled = false
        box.innerText = ''
    }
}
const disableAllButn = () =>{
    for(box of allBoxes){
        box.disabled = true
    }
}


restartBtn.addEventListener("click",resetGame)
resetBtn.addEventListener("click",resetGame)


