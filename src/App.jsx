//added in packages and css
import React from 'react';
import './App.css';
import { BrowserRouter, Route, Switch } from 'react-router-dom'
import randomWords from 'random-words';

//components
import Login from './components/Login/Login';
import HackLogin from './components/HackLogin/HackingLogin';
import User from './components/UserPage/User';

const ifFound = () => {

}

const App = () => {
  let word = randomWords()
  let randomWords = randomWords(7)
  let name = "ROOTUSER"
  
  return (
    <BrowserRouter>
      <div>
        <Switch>
          <Route exact path='/' render = {(props) => <Login {...props} randomWord = { word }/>}/>
          <Route path='/HACK' render = {(props) => <HackLogin {...props} randomWords = { randomWords } />}/>
          <Route path= '/USER' render = {(props) => <User {...props} userName = {name}/>}/>
        </Switch>
      </div>
  </BrowserRouter>
  );
}

export default App;
