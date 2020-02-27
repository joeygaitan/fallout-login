//added in packages and css
import React from 'react';
import './App.css';
import { BrowserRouter, Route, Switch } from 'react-router-dom'
import randomWords from 'random-words';

//components
import Login from './components/Login/Login';
import HackLogin from './components/HackLogin/HackingLogin';
import User from './components/UserPage/User';

const randomUCS2HexaDecimalGenrator = () => {
  let randomString = '0xF' + Math.floor(Math.random() * 10) + Math.floor(Math.random() * 10) + Math.floor(Math.random() * 10)
  return randomString
}

const rowGenerator = () => { 
  let array = []
  for (let i = 0; i <= 1; i += 1){
    array.push([])
    for(let j = 0; j <= 17; j += 1)
    array[i].push(randomUCS2HexaDecimalGenrator())
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
          <Route path='/HACK' render = {(props) => <HackLogin {...props} randomWord = { word } hexGenerator = { generator } />}/>
          <Route path= '/USER' render = {(props) => <User {...props} userName = {name}/>}/>
        </Switch>
      </div>
  </BrowserRouter>
  );
}





export default App;
