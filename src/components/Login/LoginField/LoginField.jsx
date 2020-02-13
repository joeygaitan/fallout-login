import React, { Component } from 'react';
import { withRouter } from 'react-router-dom';

class LoginField extends Component {
    constructor(props) {
        super(props);
        this.state = { password: '', tries: 3 };
    }

    componentDidMount = () =>{
        
    }

    onFinish = () => {
        if (this.state === this.props.randomWord) {
            this.props.history.push('/USER')
        }
        this.setState({ tries: this.state.tries - 1 })
        if (this.state.tries === 0) {
            this.props.history.push('/HACK')
        }
    }

    render() {
        return (
            <div>
                {this.state.tries === 0 ? <h1>tries left :{this.state.tries}</h1>: ''}
                <input type="text" value={this.state.password} onChange={(e)=> this.setState({
                    password: e.target.value
                })}/>
                <button onClick={this.onFinish()}>login</button>
            </div>
        );
    }
}

export default withRouter(LoginField);