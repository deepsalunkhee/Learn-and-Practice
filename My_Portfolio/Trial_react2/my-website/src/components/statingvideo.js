import React from 'react'
import video1 from './src/components/video1.mp4'

function statingvideo() {
  return (
    <div>
      <video  src={video1} autoPlay loop muted/>
    </div>
  )
}

export default statingvideo