//added in packages and css
import React from 'react';
import './App.css';
import { BrowserRouter, Route, Switch } from 'react-router-dom'
import randomWords from 'random-words';

//components
import Login from './components/Login/Login';
import HackLogin from './components/HackLogin/HackingLogin';
import User from './components/UserPage/User';

function randomUCS2HexaDecimalGenrator () {
  let randomString = '0xF' + Math.floor(Math.random() * 10) + Math.floor(Math.random() * 10) + Math.floor(Math.random() * 10)
  return randomString
}

function rowGenerator () { 
  let array = []
  for (let i = 0; i <= 1; i += 1){
    array.push({})
    for(let j = 1; j <= 18; j += 1)
    array[i][j] = randomUCS2HexaDecimalGenrator()
  }
  return array
}

const App = () => {

  let word = randomWords()
  let words = randomWords(7)
  let name = "ROOTUSER"
  let generator = rowGenerator()
  
  console.log(generator)
  return (
    <BrowserRouter>
      <div>
        <Switch>
          <Route exact path='/' render = {(props) => <Login {...props} randomWord = { word }/>}/>
          <Route path='/HACK' render = {(props) => <HackLogin {...props} randomWord = { word } randomWords = { words } />}/>
          <Route path= '/USER' render = {(props) => <User {...props} userName = {name}/>}/>
        </Switch>
      </div>
  </BrowserRouter>
  );
}





export default App;
