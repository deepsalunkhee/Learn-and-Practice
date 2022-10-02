import React from 'react'
import './Contact.css'
import linkden from '../Contact/linkden.png'
import Github from '../Contact/Github.png'
import Codechef from '../Contact/Codechef.png'

const Contact = () => {
  return (
    <div className='contact'>
        <div className='linkden'>
          
          <a href='https://in.linkedin.com/in/deep-salunkhe-917931225?trk=public_profile_browsemap' target={"blank"}><img src={linkden} alt="Linkden" width={350} style={{border:"0.3rem solid orange"} } /></a>  
          <p style={{color:"orange"}}>linkedin</p>
          
        </div>
        <div className="Github">
        <a href='https://github.com/deepsalunkhee' target={"blank"}><img src={Github} alt="Linkden" width={350} style={{border:"0.3rem solid orange"} } /></a>  
        <p style={{color:"orange"}}>Github</p>
        </div>
        <div className="codechef">
        <a href='https://www.codechef.com/users/deepsalunkhee' target={"blank"}><img src={Codechef} alt="Linkden" width={350} style={{border:"0.3rem solid orange"} } /></a>  
        <p style={{color:"orange"}}>Codechef</p>
        </div>

      
    </div>
  )
}

export default Contact
