import React from 'react';

//components
import HackCount from './HackCount'
import PastAttempts from './PastAttempts'

const HackingLogin = ({randomWord, hexGenerator,wordRowGenerator}) => {

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
        return <li>{item}</li>
    })

    return ( 
    <div className="boxContainer">
        <HackCount/>
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
        <PastAttempts/>
    </div> );
}
 
export default HackingLogin;