import React from 'react'
import Listitem from '../Listitem/Listitem';

const List= (props) => {
  return (
    <div className='list'>

      <h3>
        Todos list
      </h3>

      {props.todos.length===0?"No Todos to complete":
      props.todos.map((todo)=>{
        console.log(todo.sno);
        return (<Listitem todo={todo} key={todo.sno} onDelete={props.onDelete} />   
        )
    })}
      
    </div>
  )
}

export default List

