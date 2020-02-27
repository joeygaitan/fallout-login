import React from 'react';

const HackingLogin = ({randomWord, hexGenerator}) => {
    const displayLeftList = hexGenerator[0].map((item)=>{
    return <l1>{item}</l1>
    })
    const displayRightList = hexGenerator[1].map((item)=>{
        return <l1>{item}</l1>
        })
    console.log(randomWord, hexGenerator)
    return ( 
    <div>
        <ul>
            {displayLeftList}
        </ul>
        <ul>
            {displayRightList}
        </ul>
    </div> );
}
 
export default HackingLogin;