import React, { useState } from "react";

interface Props {
  children: string;
  maxChar?: number; //? means optional
}

const ExpandableText = ({ children, maxChar = 20 }: Props) => {

  const [isExpanded,setExpanded]=useState(true)
  if (children.length <= maxChar) return <p>{children}</p>;

  const text =isExpanded? children: children.substring(0, maxChar) + "... "
  return (
    <>
      <p>
        {text}
        <button onClick={()=>{setExpanded(isExpanded? false:true)}} >{isExpanded? "more":"less"}</button>
      </p>
    </>
  );
};

export default ExpandableText;
