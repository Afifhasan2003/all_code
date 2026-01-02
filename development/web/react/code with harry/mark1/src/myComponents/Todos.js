import React from 'react'
import {TodoItem} from './TodoItem'


export const Todos = (props) => {
  let mystyle = {
    minHeight:"80vh",
    margin: "50px auto"
  }
  return (
    <div className='container'  style = {mystyle} >
      <h3 className='text-center my-3'>Todos list</h3>
      
      <div className="taskList mx-5">
      {props.todos.length ===0 ? "No tasks remaining":    
        props.todos.map((todo) => {
            return <>
            <TodoItem todo={todo} key={todo.sno} onDelete ={props.onDelete} />
            <hr />
            </>
        })
        } 
      </div>
        
    </div>
   )
} 

