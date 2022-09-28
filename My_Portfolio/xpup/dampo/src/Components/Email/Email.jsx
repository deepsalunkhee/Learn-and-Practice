import Button from 'react-bootstrap/Button';
import Form from 'react-bootstrap/Form';

function Email() {
  return (

    
    <Form  action="https://formsubmit.co/deepsalunkhee@gmail.com" method='POST'>
        <h3>Contact</h3>
      <Form.Group className="mb-3" controlId="formBasicEmail">
        <Form.Label>Your Email address</Form.Label>
        <Form.Control type="email" placeholder="Enter email" />
        <Form.Text className="text-muted">
          We'll never share your email with anyone else.
        </Form.Text>
      </Form.Group>

      <Form.Group className="mb-3" controlId="formBasicPassword">
        <Form.Label>Message</Form.Label>
        <Form.Control type='text' placeholder="Password" />
      </Form.Group>
     
      <Button variant="primary" type="submit"  className='btn btn-warning'>
       Send
      </Button>
    </Form>
  );
}

export default Email;