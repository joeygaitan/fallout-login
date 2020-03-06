import React, {useEffect, useState} from 'react';

//components
import HackCount from './HackCount';
import PastAttempts from './PastAttempts';


// function useKey(key){
//     const [pressed,setPressed] = useState

//     const match = event => key.toLowerCase() == event.key.toLowerCase()

//     const onDown = event => {
//         if (match(event)) setPressed(true)
//     }

//     const onUp = event => {
//         if (match(event)) setPressed(false)
//     }

//     useEffect(()=>{
//         window.addEventListener('keydown',onDown)
//         window.addEventListener('keyup',onUp)
//         return () => {
//             window.addEventListener('keydown',onDown)
//             window.addEventListener('keyup',onUp)
//         }
//     },[key])

//     return pressed
// }



const HackingLogin = ({randomWord, hexGenerator,wordRowGenerator}) => {
    let value = 4
    let guessArray = []

    const guess = (e) => {
        console.log()
        if (guess != randomWord) {
            guessArray.push()
        }
    }

    const displayLeftList = hexGenerator[0].map((item)=>{
    return <li>{item}</li>
    })

    const displayRightList = hexGenerator[1].map((item)=>{
        return <li>{item}</li>
    })

    const displayRandomCharactersLeft = wordRowGenerator[0].map((item)=>{
        return <li>{item}</li>
    })

    const displayRandomCharactersRight = wordRowGenerator[1].map((item)=>{
        return <li onClick={guess()}>{item}</li>
    })

    return ( 
    <div className="boxContainer">
        <div className="triesCount">
            <HackCount count = {value}/>
        </div>
        <div className="boxOne">
            <div>
                <ul className="listHexOne">
                    {displayLeftList}        
                </ul>
            </div>
            <div>
                <ul className="randomStringsOne">
                    {displayRandomCharactersLeft}
                </ul>
            </div>
        </div>
        <div className="boxTwo">
            <ul className="listHexTwo">
                {displayRightList}
            </ul>
            <ul className="randomStringsTwo">
                {displayRandomCharactersRight}
            </ul>
        </div>
        <div className="passAttempts">
            <PastAttempts/>
        </div>
    </div> );
}
 
export default HackingLogin;