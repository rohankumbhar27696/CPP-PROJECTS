// CREATING API USING NODE JS TO ADD DEVICE 




var express = require('express');
var app = express();
var fs = require("fs");



app.get('/adddevice',function(req,res)
{
   var a = req.param('deviceid');
   var b = req.param('appkey');

   console.log("DEVICE ID :" + a );
   console.log("APPKEY : " + b );

   // ADD NODES TO DATABASE or FILE   

   res.send('NODE ADDED');


});




var server = app.listen(8081, function () {
   var host = server.address().address
   var port = server.address().port
   console.log("Example app listening at http://%s:%s", host, port)
})