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
                <button onClick = {this.try}>Guess</button>
                {this.props.guess}
            </div>
         );
    }
}
 
export default PastAttempts;