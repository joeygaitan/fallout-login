import React, { Component } from 'react';

class PastAttempts extends Component {
    constructor(props) {
        super(props);
        this.state = {  }
    }

    try = () => {
        this.props.guessMeth()
    }

    render() { 
        return ( 
            <div>
                Past Attempts
                <br/>
                <ul>
                    {this.props.attempts.map((item)=>{
                        return <li>{item}</li>
                    })}
                </ul>
                <button onClick = {this.try}>Try</button>
                <br/>
                <p>Current Selected Guess:{this.props.guess}</p>
                
            </div>
         );
    }
}
 
export default PastAttempts;