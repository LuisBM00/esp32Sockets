#include <WebSocketsClient.h>
#include <WiFi.h>

const char* ssid = "wifi id";
const char* pass = "wifi password";

const char* HOST = "IP";
const int PORT = 4000;

WebSocketsClient socket;

void setup()
{
    Serial.begin(9600);

    WiFi.begin(ssid, pass);

    Serial.println("Conectado...");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Conectado");
    Serial.println(WiFi.localIP());

    socket.begin(HOST, PORT, "/");
    delay(1000);

}

void loop()
{
    socket.loop();

    const int pinTouch = touchRead(4);

    if(pinTouch < 100 && pinTouch > 40){
        Serial.println(pinTouch);    
        Serial.println("Tratando de enviar el mensaje...");
        socket.sendTXT("Pin touch ha sido tocado!");
        delay(500);
    }
   
}   
