import { WebSocketServer } from "ws";

const server = new WebSocketServer({
    port: 4000
});

server.on('connection', (socket) => {

    console.log('Socket Conectado!!');

    socket.on('message', (data) => {
        
        console.log('Mensaje Recibo: ', data.toString());
    });
});

server.on('listening', () => console.log('Websocket server listen on port: ', server.options.port));