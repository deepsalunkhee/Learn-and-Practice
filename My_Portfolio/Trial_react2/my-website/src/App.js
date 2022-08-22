
import './App.css';
import NavScrollExample from './components/navigation';
import 'bootstrap/dist/css/bootstrap.min.css';
import video from './src/video.mp4'

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <>
        <NavScrollExample/>
        <video  src={video} autoPlay loop muted/>
        </>
      </header>
    </div>
  );
}

export default App;
