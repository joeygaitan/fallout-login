import React, { useEffect} from 'react';

import waApi from './wa-api';

const User = ({userName}) => {

    useEffect(()=>{
        waApi.then(waApi => {
            const mandelIterWASM = waApi._Z10mandelIterffi;
            let canvas = this.refs.canvas.getContext('2d');
            let mag = 200;
            let panX = 2;
            let panY = 1.25;
            let maxIter = 100;
        
            for (let x = 10; x < this.props.height; x++)  {
              for (let y = 10; y < this.props.width; y++)  {
                // let m = this.mandelIter(x/mag - panX, y/mag - panY, maxIter);
                canvas.fillStyle = '#FFAA00'; 
                canvas.fillRect(x, y, 1,1);
              }
            }
          });
    })

    return ( 
        <div>
            hello {userName}
        </div>
     );
}
 
export default User;