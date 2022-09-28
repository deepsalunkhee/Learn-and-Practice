import Container from 'react-bootstrap/Container';
import Nav from 'react-bootstrap/Nav';
import Navbar from 'react-bootstrap/Navbar';
import NavDropdown from 'react-bootstrap/NavDropdown';
import './Navbar.css'

function Header() {
  return (
    <div className='header'>
    <Navbar collapseOnSelect expand="lg" bg="black" variant="dark">
      <Container>
        <Navbar.Brand href="#home" style={{color:"Orange"}}>Deep Salunkhe</Navbar.Brand>
        <Navbar.Toggle aria-controls="responsive-navbar-nav"style={{color:"white"}} />
        <Navbar.Collapse id="responsive-navbar-nav" style={{color:"white"}}>
          <Nav className="me-auto">
            <Nav.Link href="#features">Upcoming...</Nav.Link>
            <Nav.Link href="#pricing">Upcoming...</Nav.Link>
            <NavDropdown title="Upcoming..." id="collasible-nav-dropdown">
              <NavDropdown.Item href="#action/3.1">Upcoming...</NavDropdown.Item>
              <NavDropdown.Item href="#action/3.2">
              Upcoming...
              </NavDropdown.Item>
              <NavDropdown.Item href="#action/3.3">Upcoming...</NavDropdown.Item>
              <NavDropdown.Divider />
              <NavDropdown.Item href="#action/3.4">
              Upcoming...
              </NavDropdown.Item>
            </NavDropdown>
          </Nav>
          <Nav>
            <Nav.Link href="#deets">Upcoming...</Nav.Link>
            <Nav.Link eventKey={2} href="#memes">
              Upcoming...
            </Nav.Link>
          </Nav>
        </Navbar.Collapse>
      </Container>
    </Navbar>

    </div>
  );
}

export default Header;