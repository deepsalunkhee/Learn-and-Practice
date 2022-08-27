import React from 'react'
import './navbar.css'
  
const Navbar = () => {
  return (
    
        <div className='n- cover'>
            <div className='n-left'>
                <div className='n-name'>D.S</div>
                <span>something</span>
            </div>
            <div className='n-right'>
                <div className='n-list'>
                    <ul>
                        <li >About Me</li>
                        <li> This wesite</li>
                       
                    </ul>
                </div>
                <div className='n-button'>
                    <button className="button">Contact</button>
                </div>
            </div>
        </div>
      )
  
}

export default Navbar