import React from 'react'
import categories from "../categories";



interface Props{
  onSelectCategory: (category: string) => void;
}

const ExpenseFiler = ({onSelectCategory}:Props) => {
  return (
    <select className="form-select" onChange={(event)=>onSelectCategory(event.target.value)}>
        <option >ALL Categories</option>
        {categories.map(cat => <option key={cat} value={cat} >{cat}</option> )}
        
    </select>
  )
}

export default ExpenseFiler
