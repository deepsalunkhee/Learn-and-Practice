import React, { useState } from 'react';
import Button from 'react-bootstrap/Button';
import Form from 'react-bootstrap/Form';

export const AddTodo = ({ addTodo }) => {
    const [title, setTitle] = useState("");
    const [desc, setDesc] = useState("");


    const add = (e) => {
        e.preventDefault();
        if (!title||!desc ) {
            alert("Title or Description cannot be blank");
        }
        else {
            addTodo(title, desc);
            setTitle("");
            setDesc("");
        }
    }
    return (
        <div className='add'>
    
      <Form.Group className="mb-3" controlId="formBasicEmail" >
        <Form.Label style={{color:"white"}}>ToDo Name</Form.Label>
        <Form.Control type="text" placeholder="Enter ToDo" value={title}  onChange={(e)=>{setTitle(e.target.value)}}/>
        <Form.Text className="text-muted" style={{color:"white"}}>
          ToDo Name cannot be empty
        </Form.Text>
      </Form.Group>

      <Form.Group className="mb-3" controlId="formBasicPassword">
        <Form.Label style={{color:"white"}}  >Todo Description</Form.Label>
        <Form.Control type="text" placeholder="Description" value={desc}  onChange={(e)=>{setDesc(e.target.value)}}/>
      </Form.Group>
      
      <Button variant="primary" type="submit" className='btn btn-warning'  id='add' onClick={add}>
        Add ToDo
      </Button>
      

      

        

    
    </div>
    )
}
