import React, { useEffect, useRef } from 'react';

const User = ({userName}) => {

    const canvasRef = useRef(null);

    const drawOnCanvas = async () => {
      const response = await fetch('main.wasm');
      const bytes = await response.arrayBuffer();
      const { instance } = await WebAssembly.instantiate(bytes);

      const canvas = canvasRef.current;
      const ctx = canvas.getContext('2d');

      instance.exports.draw(ctx);
    }

    return ( 
        <div>
            hello {userName}
            <canvas ref={canvasRef} width={400} height={400} />
            <button onClick={drawOnCanvas}>Draw on canvas</button>
        </div>
     );
}
 
export default User;