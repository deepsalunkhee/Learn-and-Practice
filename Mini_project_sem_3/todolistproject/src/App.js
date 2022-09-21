import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';

import './App.css';
import Navbar1 from './Component/Navbar/Navbar';
import Footer from './Component/Footer/Footer';
import Addtodo from './Component/Addtodo/Addtodo';
import Todolist from './Component/Todolist/Todolist';
import { useState } from 'react';
import { useEffect } from 'react';


function App() {

  let initTodo;
  if (localStorage.getItem("todos") === null) {
    initTodo = [];
  }
  else {
    initTodo = JSON.parse(localStorage.getItem("todos"));
  }

  const [todos, setTodos] = useState(initTodo);
  useEffect(() => {
    localStorage.setItem("todos", JSON.stringify(todos));
  }, [todos])

  

  const addtodo=(title,desc)=>{

    const Mytodo=
    {
      title:title,
      desc:desc

    }
    setTodos([...todos, Mytodo]);
    console.log(Mytodo);


  }

  
  return (
    <div className="App">
     <Navbar1/>
     <Addtodo  addtodo={addtodo}/>
     <Todolist/>




     <Footer/>
    </div>
  );
}

export default App;
