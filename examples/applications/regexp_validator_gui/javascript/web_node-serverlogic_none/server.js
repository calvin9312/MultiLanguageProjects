const http = require('http');
const express = require('express');
const app = express();

const hostname = '127.0.0.1';
const port = 3000;

app.use(express.static(__dirname));
app.get('/', function(request, response){
    response.sendFile(__dirname + '/index.html');
});

app.get('/text_match', function(request, response){
	if (('text' in request.query) && ('pattern' in request.query)) {
		text = request.query['text']
		pattern = request.query['pattern']
		if ( text && pattern ) {
			re = new RegExp(pattern)
			if(re.test(text)) {
				response.send('true')
			} else {
				response.send('false')
			}
		} else {
			response.send('false')
		}
	} else {
		response.send('false')
	}
});

app.listen(port);
