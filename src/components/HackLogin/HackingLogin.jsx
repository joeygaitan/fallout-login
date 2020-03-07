import React, {Component} from 'react';

//components
import HackCount from './HackCount';
import PastAttempts from './PastAttempts';
import Failed from './Failed';


class HackingLogin extends Component {
    constructor(props){
        super(props)
        this.state = {
            value: 4,
            guessArray: [],
            guess: ''
        }
    }

    

    selectedGuessLeft = (event) => {
        let value = this.props.wordRowGenerator[0][event.target.value]
        this.setState({
            guess: value
        })
    }

    selectedGuessRight = (event) => {
        let value = this.props.wordRowGenerator[1][event.target.value]
        this.setState({
            guess: value
        })
    }

    guess = () => {
        if (this.state.guess != this.props.randomWord) {
            this.setState({
                guessArray: [...this.state.guessArray, this.state.guess],
                value: this.state.value - 1
            })
        }else {
            this.props.history.push('/USER')
        }
    }

    render () {
    return ( 
    <>
    {this.state.value > 0 ? <>
    <div className="boxContainer">
        <div className="triesCount">
            <HackCount count = {this.state.value}/>
        </div>
        <div className="boxOne">
            <div>
                <ul className="listHexOne">
                    {this.props.hexGenerator[0].map((item)=>{return <li>{item}</li>})}        
                </ul>
            </div>
            <div>
                <ul className="randomStringsOne">
                    {this.props.wordRowGenerator[0].map((item,index)=>{return <li value={index} onClick={this.selectedGuessLeft.bind(this)}>{item}</li> })}
                </ul>
            </div>
        </div>
        <div className="boxTwo">
            <ul className="listHexTwo">
                {this.props.hexGenerator[1].map((item)=>{return <li>{item}</li>})}
            </ul>
            <ul className="randomStringsTwo">
                {this.props.wordRowGenerator[1].map((item,index)=>{return <li value={index} onClick={this.selectedGuessRight.bind(this)}>{item}</li>})}
            </ul>
        </div>
        <div className="passAttempts">
            <PastAttempts attempts = {this.state.guessArray} guessMeth = {this.guess} selectedGuess = {this.state.guess}/>
        </div>
    </div> 
    </>: <Failed/>}
    </>
    );
    }
}
 
export default HackingLogin;