import React, { Component } from 'react';
import { withRouter } from 'react-router-dom';

class LoginField extends Component {
    constructor(props) {
        super(props);
        this.state = { password: '', tries: 4 };
    }

    componentDidMount = () => {
        this.onFinish()
    }

    onFinish = () => {
        if (this.state.password === this.props.randomWord) {
            this.props.history.push('/USER')
        }else if (this.state.tries <= 1) {
            this.props.history.push('/HACK')
        }else if(this.state.password !== ''){
            this.setState({ password: '', tries: this.state.tries - 1 })
        }
    }

    render() {
        return (
            <div className="inputWrapper">
                { (4 > this.state.tries >= 1) ? <h1 className="triesLeftH1">tries left :{this.state.tries}</h1>: ''}
                <input type="text" value={this.state.password} onChange={(e)=> this.setState({
                    password: e.target.value
                })}/>
                <button onClick={this.onFinish.bind(this)}>login</button>
            </div>
        );
    }
}

export default withRouter(LoginField);