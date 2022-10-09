import React from 'react';
import './Navbar.css'
import Container from 'react-bootstrap/Container';
import Nav from 'react-bootstrap/Nav';
import Navbar from 'react-bootstrap/Navbar';
import NavDropdown from 'react-bootstrap/NavDropdown';


function Navbar1() {
  return (
    <Navbar bg="black" expand="lg"  className='Navbar'>
      <Container>
        <Navbar.Brand href="#home" style={{color:"orange"}}>ToDo</Navbar.Brand>
        <Navbar.Toggle aria-controls="basic-navbar-nav" style={{color:"white" ,background:"orange"}} />
        <Navbar.Collapse id="basic-navbar-nav" style={{color:"white"}}>
          <Nav className="me-auto">
            <Nav.Link href="#home" style={{color:"orange"}}>Option1</Nav.Link>
            <Nav.Link href="#link" style={{color:"orange"}}>Option2</Nav.Link>
            <NavDropdown title="Sub-options " id="basic-nav-dropdown" style={{color:"orange",background:"black"}}>
              <NavDropdown.Item href="#action/3.1">Sub-option1</NavDropdown.Item>
              <NavDropdown.Item href="#action/3.2">
                Sub-Option2
              </NavDropdown.Item>
              <NavDropdown.Item href="#action/3.3">Sub-Option3</NavDropdown.Item>
              <NavDropdown.Divider />
              <NavDropdown.Item href="#action/3.4">
                Sub-Sub-Option1
              </NavDropdown.Item>
            </NavDropdown>
          </Nav>
        </Navbar.Collapse>
      </Container>
    </Navbar>
  );
}

export default Navbar1;