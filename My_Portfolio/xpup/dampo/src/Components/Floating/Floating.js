import React from 'react'
import './Floating.css'


const Floating = ({image,text1,text2}) => {
  return (
    <div  className='Floating_cover'> 
        <div className='f-top_left'>
           <img src={image}  alt='crown' className='crown' />
           <span className='web'>
          {text1}{ text2}
            <br></br>
           
         </span>
        </div>
    </div>
  )
}

export default Floating