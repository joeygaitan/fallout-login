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

const randomString = () => {
  let characters = '!@#$%^*()_+={]><~`'.split('')
  let characterString = []

  for (let i = 0; i <= 17;i += 1){
    characterString.push(characters[Math.floor(Math.random() * 18)])

  }
  // console.log(characterString)
  return characterString
  // string.join()
  // console.log(string)
  // return string
}

//length of word minus length of array shouldn't return minus
const  generateTextGenerator = (word) => {
  let wordRowGenerator = []

  for (let i = 0; i <= 1; i += 1){
    wordRowGenerator.push([])
    for(let j = 0; j <= 17; j += 1) {
      if (j % 5 === 0 && j !== 10) {
        wordRowGenerator[i].push(randomWords())
      } else if (i === 0 && j === 10) {
        wordRowGenerator[i].push(word)
      }
      else {
        wordRowGenerator[i].push(randomString())
      }
    }
  }
  
  return wordRowGenerator
}

const App = () => {
  let word = randomWords()
  let words = randomWords(8)
  let name = "ROOTUSER"
  let generator = rowGenerator()
  let wordGenerator = generateTextGenerator(word, words)
  
 
  return (
    <BrowserRouter>
      <div>
        <Switch>
          <Route exact path='/' render = {(props) => <Login {...props} randomWord = { word }/>}/>
          <Route path='/HACK' render = {(props) => <HackLogin {...props} randomWord = { word } hexGenerator = { generator } wordRowGenerator = {wordGenerator }/>}/>
          <Route path= '/USER' render = {(props) => <User {...props} userName = {name}/>}/>
        </Switch>
      </div>
  </BrowserRouter>
  );
}





export default App;
