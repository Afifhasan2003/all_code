const myform = document.querySelector('#my-form');
const nameInput = document.querySelector('#name');
const mail = document.querySelector('#email');
const msg = document.querySelector('.msg');
const userlist = document.querySelector('#users');

myform.addEventListener('submit', onSubmit);        // .addEventListener('event', function to be executed when the event occurs)

function onSubmit(abc){
    abc.preventDefault();

    if(nameInput.value ==='' || mail.value === ''){

        msg.innerHTML = '<h1> Please enter all fields </h1>';
        msg.classList.add('error');
        setTimeout(()=> msg.remove(),3000 );        // remove the message after 3 seconds
        
    }
    else{
        const newlist = document.createElement('li');
        newlist.appendChild(document.createTextNode(`${nameInput.value} : ${mail.value}`));
        userlist.append(newlist);

        nameInput.value='';
        mail.value='';
    }




}

//OR we could just 
myform.addEventListener('submit',(onSubmit) =>{
    onSubmit.preventDefault();

    if(nameInput.value ==='' || mail.value === ''){

        msg.innerHTML = '<h1> Please enter all fields </h1>';
        msg.classList.add('error');
        setTimeout(()=> msg.remove(),3000 );        // remove the message after 3 seconds
        
    }
    else{
        const newlist = document.createElement('li');
        newlist.appendChild(document.createTextNode(`${nameInput.value} : ${mail.value}`));
        userlist.append(newlist);

        nameInput.value='';
        mail.value='';
    }
})