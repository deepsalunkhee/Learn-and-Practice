import '../node_modules/bootstrap/dist/css/bootstrap.min.css';
import './App.css';
import Email from './Components/Email/Email';
import { Footer } from './Components/Footer/Footer';
import Intro from './Components/Intro/Intro';
import Header from './Components/Navbar/Navbar';
import Projects from './Components/Projects/Projects';
import Contact from './Contact/Contact';

function App() {
  return (
    <div className="App">

      <Header/>
      <Intro/>
      <Contact/>
      <Projects/>

      <Email/>
      
      
      <Footer/>
    </div>
  );
}

export default App;
