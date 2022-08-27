import React from 'react';
import './App.css';
import NavScrollExample from './components/navbar';
import 'bootstrap/dist/css/bootstrap.min.css';
import Body from './components/body';


function App() {
  return (
    <div className="App">
      
      <header className="App-header">
        <>
        <NavScrollExample/>
        
        </>
      </header>
      <body>
        {Body}
      </body>
    </div>
  );
}

export default App;
