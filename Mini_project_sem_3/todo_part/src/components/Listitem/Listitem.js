import React from 'react'

const Listitem = (props) => {
  return (
    <div className='item'>
      <h3>
        {props.todo.title}
      </h3>
      <p>
        {props.todo.description}
      </p>
      <button onClick={()=>{props.onDelete(props.todo)}}>Delete</button> 
    </div>
  )
}

export default Listitem
