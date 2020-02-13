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
            
        }
    }

    render() {
        console.log(this.props.randomWord)
        return (
            <div>
                <input type="text" value={this.state.password} onChange={(e)=> this.setState({
                    password: e.target.value
                })}/>
            </div>
        );
    }
}

export default LoginField;