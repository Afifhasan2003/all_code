import './App.css';
import Header from './myComponents/Header.js';
import {Todos} from './myComponents/Todos.js'

import {Footer} from './myComponents/Footer.js'   //if not default export
import React, {useState,useEffect} from 'react'  //to delete element
import {AddTodo} from './myComponents/AddTodo.js'
import {About} from './myComponents/About.js' //if not default export

import {
  BrowserRouter as Router,
  Routes,
  Route,
  Link
} from 'react-router-dom';

function App() {
  let initTodo;
  if(localStorage.getItem("todos") ===null){
    initTodo = [];
  }
  else{
    initTodo = JSON.parse(localStorage.getItem("todos"))
  }

  const onDelete = (todo)=>{
    console.log("im on delete")
    console.log(todo) 
    
    //deleting this way wont work on react
    // let index = todos.indexOf(todo);
    // todos.splice(index,1); 

    setTodos(todos.filter((e)=>{
      return e!==todo
    }))
    // localStorage.setItem("todos",JSON.stringify(todos));
  }

  const addTodo = (title, desc) =>{
    // console.log("todo is added" ,title,desc)
    let sno
    if(todos.length==0) sno =1
    else  sno = todos[todos.length -1].sno +1

    const newTodo ={
      sno:sno,
      title: title,
      desc: desc
    }
    setTodos([...todos,newTodo]);
    console.log(newTodo)


   
  } 

  // let todos =[
  //   {
  //     sno:1,
  //     title:"Go to the market",
  //     desc:"You need to go to the market to buy some vegetables",

  //   },
  //   {
  //     sno:2,
  //     title:"Go to the mall",
  //     desc:"You need to go to the mall to buy some clothes",
  //   },
  //   {
  //     sno:3,
  //     title:"Go to the gym",
  //     desc:"You need to go to the gym to exercise",
  //   },
  //   {
  //     sno:4,
  //     title:"Go to the bank",
  //     desc:"You need to go to the bank to deposit some money",
  //   } 
  // ] // wont use this, coz we ,cant delete element from here

//  const [todos,setTodos] = useState([   //usestate is a hook that allows us to use state in functional components
//     {
//       sno:1,
//       title:"Go to the market",
//       desc:"You need to go to the market to buy some vegetables",

//     },
//     {
//       sno:2,
//       title:"Go to the mall",
//       desc:"You need to go to the mall to buy some clothes",
//     },
//     {
//       sno:3,
//       title:"Go to the gym",
//       desc:"You need to go to the gym to exercise",
//     },
//     {
//       sno:4,
//       title:"Go to the bank",
//       desc:"You need to go to the bank to deposit some money",
//     } 
//   ])

const [todos,setTodos] = useState(initTodo);  //now todos is just an empty array
 useEffect(() =>{
    localStorage.setItem("todos",JSON.stringify(todos));
    },[todos])




  return (
    <>
    <Router>
      <Header title="My Todo list" searchBar = {true} />
      <Routes>
        <Route path="/" element={
          <>
            <AddTodo addTodo={addTodo} />
            <Todos todos={todos} onDelete={onDelete} />
          </>
        } />

        <Route path="/about" element={
          <>
            <h1>About Us</h1>
            <About />
          </>
          } />

      </Routes>

    </Router>
    </>
  );
}

export default App; 


