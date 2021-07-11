'''

1. Create a Python script to connect through MQTT to any IOT gateway like AWS or GCP IOT core or Thingsboard or Devicehive etc of your choice.

2. Create a device in the same script.

3. Host this and show a demo of communication between the device and gateway (optional bonus)

This will take 2-3 hours to complete. You can push this to your github repo and send us link in reply. Please complete by Monday 10am. Please ensure the work is your own and you must be prepared to walk thru your work in detail. 

Thanks.

'''

import paho.mqtt.client as paho
import requests
import os
import time

#http://127.0.0.1:8081/adddevice?deviceid=112233&appkey=55223366
deviceid = "11223344"
appkey = "TEMPMON123456"
url_to_addnode = "http://127.0.0.1:8081/adddevice?deviceid=" + deviceid + "&" + "appkey=" + appkey ;



r = requests.get(url_to_addnode);

print( r.text );




broker="maqiatto.com"
port=1883
def on_publish(client,userdata,result):             #create function for callback
    print("data published \n")
    pass
client1= paho.Client("control1")                           #create client object
client1.username_pw_set(username="rohankumbhar27696@gmail.com",password="123456789")
client1.on_publish = on_publish                          #assign function to callback
client1.connect(broker,port)                                 #establish connection

cnt = 0; 

while( 1) :

	cnt = cnt  + 1 ;
	datastr = "DEMO TEST : " + str(cnt);
	ret= client1.publish("rohankumbhar27696@gmail.com/testdata",datastr)
	time.sleep(2); 

	if( cnt >= 10  ):
		break;

print( " program to  end");