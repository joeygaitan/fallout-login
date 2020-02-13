import React, { Component } from 'react';

class LoginField extends Component {
    constructor(props) {
        super(props);
        this.state = { password: '' };
    }
    render() {
        console.log(this.props.randomWord)
        return (
            <div>
                <input type="text" value={this.state.password} />
            </div>
        );
    }
}

export default LoginField;