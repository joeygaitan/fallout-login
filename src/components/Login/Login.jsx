import React from 'react';
import LoginField from './LoginField/LoginField';



const Login = ({randomWord}) => {
    return ( 
        <div>
            <h1>Pleasse Enter The Password to the Terminal</h1>
            <LoginField randomWord = {randomWord}/>
        </div>
     );
}
 
export default Login;