import React, { Component } from 'react';

class LoginField extends Component {
    constructor(props) {
        super(props);
        this.state = { password: '', tries: 0 };
    }

    componentDidMount = () =>{
        
    }

    onFinish = () => {
        if (this.state === this.props.randomWord){
            this.props.history.push('/USER')
        }
        this.setState({ tries: this.state.tries + 1 })
    }

    render() {
        console.log(this.props.randomWord)
        return (
            <div>
                <input type="text" value={this.state.password} onChange={(e)=> this.setState({
                    password: e.target.value
                })}/>
                <button onClick={this.onFinish()}> login</button>
            </div>
        );
    }
}

export default LoginField;