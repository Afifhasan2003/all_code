//editing all boxes
const boxes = document.querySelectorAll(".box");

boxes.forEach(box => {
    box.style.backgroundColor = 'red';
});



//box1


const box1header = document.getElementById("box1header")
const box1items = document.getElementsByClassName("box1items")
const box1 = document.getElementById("box1")
box1header.style.color = 'blue' // this will change the color of the header of box1
box1items[1].style.backgroundColor = 'green' // this will change the background color of the first element of box1items




//box2
        const box2header = document.querySelector("#box2header")
        const box2items = document.querySelectorAll(".box2items") // this will select all the elements with class box2items
        const box2 = document.querySelector("#box2")

        // box2.lastElementChild.remove()                // this will remove the last element of the box2
        box2items[box2items.length - 1].remove()        // same as above
        box2items[1].innerHTML = '<i>banana</i>'         //change the text of the second element of box2items

        //add a new element to box2items
        const newElement = document.createElement('p') // this will create a new element 
        newElement.innerText = 'new added fruits' // this will set the text of the new element
        box2.appendChild(newElement) // this will add the new element to the box2
        

        //in one line
        box2.appendChild(document.createElement('p')).innerText = 'new added fruits again' 
        // box2.prependChild(document.createElement('p')).innerText = 'new added fruits again' 


    
    //box2jr
        const box2jr = document.querySelector("#box2jr")
        const junior1 = document.createElement('p') 
        junior1.innerText = 'this is bomb1'
        const junior2 = document.createElement('p')
        junior2.innerText = 'this is bomb2'
        const junior3 = document.createElement('p')
        junior3.innerText = 'this is bomb3'

        box2jr.appendChild(junior1) // this will add the new element to the box2jr
        box2jr.prepend(junior2) // this will add the new element to the box2jr at the beginning
        box2jr.insertBefore(junior3, junior1) // this will add the new element to the box2jr before the junior1
    






//box3
        let id = box3.getAttribute('id') // this will get the id of the box3
        console.log(id) // box3
        box3.setAttribute('id', 'box3new') // this will set the id of the box3 to box3new
        box3new.style.backgroundColor = 'grey' // this will change the background color of the box3new


        const box3class = document.querySelector(".box3Class") 
        // box3class.setAttribute('class', 'makeRound') // but this overrides the previous classes
        box3class.classList.add('makeRound') // this will let keep the previous classes and add the new class
        box3class.classList.add('yellowText') // this will add a new class to the element
        // box3class.classList.remove('yellowText') // this will remove the class yellowText from the element



//box4
        //put a button in box4
        const box4 = document.querySelector("#box4")
        const butn= document.createElement('button') // element type is 'button'
        butn.innerText = 'click meee' // this will set the text of the button
        box4.appendChild(butn) // this will add the button to the box4

        //adding event listener to the button
        const hoverfunc =(evt) => {       //varible.addEventListener('event', function to be executed)
            evt.preventDefault();
            console.log('event triggered!!!!!');
            console.log(evt.type);           // this will print the type of event
            console.log(evt.target);         // this will print the target of the event
            console.log(evt.target.className);      // will need it when we have multiple buttons
            console.log(evt.target.id);            // will need it when we have multiple buttons
            box4.style.backgroundColor = 'blue' // this will change the background color of the box4
            const heading1 = document.querySelector("#box4 h3") // this will select the h3 element inside the box4
            heading1.textContent = 'i am changed'  
            box4.appendChild(document.createElement('div')).innerHTML='<i><big> <br>hi friend </big></i>'
        }
        butn.addEventListener('mouseover', hoverfunc) // this will add the event listener to the button;

        butn.addEventListener('click', () => {
            butn.removeEventListener('mouseover', hoverfunc) ;  //the parameter has to be same
        });



//box5
        const box5 = document.querySelector("#box5");

        // Create button
        const btn = document.createElement("button");
        btn.innerText = "Hover me";
        box5.appendChild(btn);

        // Hover effect
        box5.addEventListener("mouseover", () => {      //box5.onmouseover = () => {    we can also use this
        box5.style.backgroundColor = "blue";
        });

        const mouseoutFunc = () => {                // we can also use this
        box5.style.backgroundColor = "gray";
        }
        box5.addEventListener("mouseout", mouseoutFunc);



        // Click event
        // btn.addEventListener("click", () => {

        btn.onclick = (e) => {                      //e is the event object, not mandatory
            box5.style.backgroundColor = "green";
            const newElement = document.createElement("p");
            newElement.innerText = "You clicked the button!";
            box5.appendChild(newElement);
        };
        // Double click event
        btn.ondblclick = () => {
            box5.style.backgroundColor = "purple";
            const newElement = document.createElement("p");
            newElement.innerText = "You double-clicked the button!";
            box5.appendChild(newElement);
        };





//box6
        const box6 = document.querySelector("#box6")
        const box6jr = document.querySelector("#box6jr")

        box6jr.addEventListener("click",()=>{
            // let num = Math.random()
            let num2 = Math.random() * 10
            let num3 = Math.floor(Math.random() * 10)




            // box6jr.innerText = num
            // box6jr.innerText = num2
            box6jr.innerText = num3
        })









//mode  
        const body = document.querySelector('body');
        const modeBtn = document.querySelector('nav div button')
        let currMode='light'
        const mode = document.querySelector("#mode");
        mode.addEventListener('click',()=>{
            if(currMode==='light'){
                body.classList.add('darkMode')
                body.classList.remove('lightMode')
                currMode = 'dark'
                modeBtn.classList.add('navDarkMode')
                modeBtn.classList.remove('navLightMode')

                
            }
            else if(currMode ==='dark'){
                body.classList.add('lightMode')
                body.classList.remove('darkMode')
                currMode = 'light'
                modeBtn.classList.add('navLightMode')
                modeBtn.classList.remove('navDarkMode')
            }
        })














  //this is sooo cool
  /*
  document.body.addEventListener("mousemove", (e) => {
  const dot = document.createElement("div");
  dot.style.position = "absolute";
  dot.style.left = `${e.pageX}px`;
  dot.style.top = `${e.pageY}px`;
  dot.style.width = "8px";
  dot.style.height = "8px";
  dot.style.borderRadius = "50%";
  dot.style.backgroundColor = `hsl(${Math.random() * 360}, 100%, 50%)`;
  document.body.appendChild(dot);

  setTimeout(() => dot.remove(), 500);
}); 
l */
