//Basic express app
const express = require('express');
const app = express();
const port = 80||process.env.PORT;
app.get('/', (req, res) => {
    res.send('Hello From Deep');
});

app.listen(port, () => {
    console.log('Server is running on port 3000');
});