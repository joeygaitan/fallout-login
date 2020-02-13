//added in packages and css
import React from 'react';
import './App.css';
import { BrowserRouter, Route, Switch } from 'react-router-dom'
import randomWords from 'random-words';

//components
import Login from './components/Login/Login';
import HackLogin from './components/HackLogin/HackingLogin';

function App() {
  return (
    <BrowserRouter>
      <div>
        <Switch>
          <Route exact path='/' render = {(props) => <Login {...props} randomWord = {randomWords()}/>}/>
          <Route path='/HACK' render = {(props) => <HackLogin {...props} randomWords = {(7) => {return randomWords(7)}}/>}/>
          <Route path= '/USER' render = {(props) => <User {...props} />}/>
        </Switch>
      </div>
  </BrowserRouter>
  );
}

export default App;
