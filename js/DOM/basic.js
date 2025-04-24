// console.log(window) // this includes all the properties and methods of the window object 

// Single element selectors
// console.log(document.getElementById('my-form'));
// console.log(document.querySelector('h1'));
// console.log(document.querySelector('.container'));

// Multiple element selectors

// console.log(document.querySelectorAll('.item'));
// console.log(document.getElementsByClassName('item'));  //these two are same 
// console.log(document.getElementsByTagName('li'));  //these three are same


const list = document.querySelector('.items');

// list.remove();
list.lastElementChild.remove();
list.firstElementChild.textContent = 'poteto';
list.children[1].innerText = 'banana';
list.lastElementChild.innerHTML = '<h1>hello</h1>';
// console.log(list);


//button

const butn = document.querySelector('.btn');
butn.style.backgroundColor = 'red'; // this is inline css
butn.style.color = 'blue'; ;

// Events
butn.addEventListener('click', (abc) => {
    abc.preventDefault();
    console.log('click');
    console.log(abc.target.className);

    // document.querySelector('body').classList.add('bg-dark');  //added from css
    document.querySelector('body').style.backgroundColor = '#455';


    console.log('Background color changed!');
});