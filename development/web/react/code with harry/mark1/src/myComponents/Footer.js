import React from 'react'

export const Footer = () => {

  // let footerStyle = {
  //   position : "relative",
  //   top:"90vh",
  //   width:"100%",

  // }
  return ( 
    //these classes are defined in bootstrap
    <footer className='bg-dark text-light py-3' /*style={footerStyle} */>  
     <p className='text-center'> Copyright &copy; MyTodoList.com </p>
    </footer>
  )
}


