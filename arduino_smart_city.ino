#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xAE, 0xEF, 0xFE, 0xED };

const char* host = "iotmmsp1941931245trial.hanatrial.ondemand.com";
String device_id = "35fd9ca4-6cb6-4746-af02-44e6322a744a";
String message_type_id = "d5b082dd4ecdaf226dac";
String oauth_token=" f3ae9f799c817a1946c5dbf283b778f7";

int pin;

String url = "/com.sap.iotservices.mms/v1/api/http/data/" + device_id;
// just an example payload corresponding to the other Starterkit examples
String post_payload = "{\"mode\":\"async\", \"messageType\":\"" + message_type_id + "\", \"messages\":[{\"sensor\":\"sensor1\", \"value\":\"455\", \"timestamp\":1413191680}]}";
const int httpsPort = 443;

int sensor;
void setup() {


      Serial.begin(9600);
      while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
      
      Serial.println(Ethernet.localIP());

      EthernetClient client;
      Serial.print("connecting to ");
      Serial.println(host);
      if (!client.connect(host, httpsPort)) {
      Serial.println("connection failed");
      return;
    }
 
    Serial.print("requesting URL: ");
  Serial.println(url);

  
  client.print(String("POST ") + url + " HTTP/1.0\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/json;charset=utf-8\r\n" +
               "Authorization: Bearer " + oauth_token + "\r\n" +
               "Content-Length: " + post_payload.length() + "\r\n\r\n" +
               post_payload + "\r\n\r\n");
               
  Serial.println("request sent");

  Serial.println("reply was:");
  Serial.println("==========");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
  Serial.println("==========");
  Serial.println("closing connection");
}

void loop() {

  
  
  client.print(String("POST ") + url + " HTTP/1.0\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/json;charset=utf-8\r\n" +
               "Authorization: Bearer " + oauth_token + "\r\n" +
               "Content-Length: " + post_payload.length() + "\r\n\r\n" +
               post_payload + "\r\n\r\n");


               client.print("POST/"+host+""{\"mode\":\"async\", \"messageType\":\"" + message_type_id +
                            "\", \"messages\":[{\"sensor\":\"sensor1\", "+value:+
                            "455\", \"timestamp\":1413191680}]}";");

      delay(5000);
 

  
}


