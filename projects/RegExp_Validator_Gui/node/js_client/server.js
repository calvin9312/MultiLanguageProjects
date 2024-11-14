const http = require('http');
const express = require('express');
const app = express();

const hostname = '127.0.0.1';
const port = 3000;

app.use(express.static(__dirname));
app.get('/', function(request, response){
    response.sendFile(__dirname + '/index.html');
});

app.listen(port);
