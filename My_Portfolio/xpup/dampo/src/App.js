import '../node_modules/bootstrap/dist/css/bootstrap.min.css';
import './App.css';
import { Footer } from './Components/Footer/Footer';
import Intro from './Components/Intro/Intro';
import Header from './Components/Navbar/Navbar';

function App() {
  return (
    <div className="App">

      <Header/>
      <Intro/>
      
      <Footer/>
    </div>
  );
}

export default App;
