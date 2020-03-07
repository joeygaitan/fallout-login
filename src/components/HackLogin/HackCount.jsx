import React, { Component } from 'react';

const HackCount = ({count}) => {
    return ( 
        <div>
            tries {count}
            <br/>
            <p>
                select a guess. Then press Try....
            </p>
        </div>
     );
}
 
export default HackCount;