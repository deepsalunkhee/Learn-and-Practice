import React from 'react'
import Table from 'react-bootstrap/Table';
import Form from 'react-bootstrap/Form';

export const TodoItem = ({todo, onDelete}) => {
    return (
        
         <Table striped bordered hover variant="dark">
      <thead>
        <tr>
          
          <th>{todo.title}</th>
          <th>{todo.desc}</th>
          <th><Form.Check type="checkbox"  /></th>
          <th><button className="btn btn-sm btn-danger" onClick={()=>{onDelete(todo)}}>Delete</button> </th>
          
        </tr>
      </thead> 
        </Table>
    )
}
