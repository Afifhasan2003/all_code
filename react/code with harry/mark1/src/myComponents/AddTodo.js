import React, { useState } from 'react'


export const AddTodo = (props) => {
  const [title,setTitle] = useState("");
  const [desc,setDesc] = useState("");

  const submit = (e) =>{
      e.preventDefault();
      if(!title){
        alert("full up the title")
      }
      else {props.addTodo(title,desc);
      setTitle("")
      setDesc("")}

  }
  return (
    <div className='container my-3'>
        <h3 className='text-center'>Add a Todo</h3>
      <form onSubmit={submit}>

  <div className="form-group">
    <label htmlFor="title">Task</label>
    <input type="text" value={title} onChange={(e)=>{setTitle(e.target.value)}} className="form-control" id="title" aria-describedby="emailHelp" placeholder="Enter task"/>   
                                  {/* cant write without onchange */}
  </div>
  <div className="form-group">
    <label htmlFor="desc">Description</label>
    <input type="text" value = {desc} onChange={(e)=>{setDesc(e.target.value)}}  className="form-control" id="desc" placeholder="Enter description"/>
  </div>
  
  <button type="submit" className="btn btn-success btn-sm ">Add</button>
</form>
    </div>
  )
}


