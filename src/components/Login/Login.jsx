import React from 'react';
import LoginField from './LoginField/LoginField';
import randomWords from 'random-words';


const Login = () => {
    return ( 
        <div>
            <h1>Pleasse Enter The Password to the Terminal</h1>
            <LoginField randomWord = {randomWords()}/>
        </div>
     );
}
 
export default Login;