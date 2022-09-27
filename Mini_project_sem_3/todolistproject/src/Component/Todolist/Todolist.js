import Table from 'react-bootstrap/Table';
import Form from 'react-bootstrap/Form';

function Todolist() {
  return (
    <Table striped bordered hover variant="dark">
      <thead>
        <tr>
          
          <th>ToDo Name</th>
          <th>Description</th>
          <th>Status</th>
          <th><button className="btn btn-sm btn-danger" onClick={()=>{onDelete(todo)}}>Delete</button> </th>
          
        </tr>
      </thead>
      <tbody>
        <tr>
         
          <td>Pranav</td>
          <td>Omkar</td>
          <td><Form.Check type="checkbox"  /></td>
         
        </tr>
        <tr>
      
          <td>Sukant</td>
          <td>Deep</td>
          <td><Form.Check type="checkbox"  /></td>
         
          
        </tr>
        
      </tbody>
    </Table>
  );
}

export default Todolist;