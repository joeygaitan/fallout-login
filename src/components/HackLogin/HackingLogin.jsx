import React from 'react';

const HackingLogin = ({randomWord, hexGenerator,wordRowGenerator}) => {
    const displayLeftList = hexGenerator[0].map((item)=>{
    return <l1>{item}</l1>
    })
    const displayRightList = hexGenerator[1].map((item)=>{
        return <l1>{item}</l1>
    })
    const displayRandomCharactersLeft = wordRowGenerator[0].map((item)=>{
        return <li>{item}</li>
    })
    const displayRandomCharactersRight = wordRowGenerator[1].map((item)=>{
        return <li>{item}</li>
    })

    console.log(randomWord, hexGenerator,wordRowGenerator)
    return ( 
    <div>
        <div>
            <ul>
                {displayLeftList}        
            </ul>
            <ul>
                {displayRandomCharactersLeft}
            </ul>
        </div>
        <div>
            <ul>
                {displayRightList}
            </ul>
            <ul>
                {displayRandomCharactersRight}
            </ul>
        </div>
    </div> );
}
 
export default HackingLogin;