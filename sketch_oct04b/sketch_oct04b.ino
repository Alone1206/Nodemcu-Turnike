#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


const char* ssid = ""; //wifi ssid
const char* password = ""; //wifi password
String getapidata = "http://yourdomain"; //your domain adress to pull data from | Alan adınız- datanın okunacağı

void setup () {

  Serial.begin(115200); // Start the serial monitor.
  delay(10); // Give it a moment.


  pinMode(14, OUTPUT); // Set GPIO2 as an OUTPUT.
  digitalWrite(14, 1); // Başlangıçta açık, röle tipinize göre ayarlayın. | High on boot, adjust acording to your relay type

  // Connect to WiFi network:
  Serial.println("Hello yourname");
  Serial.println("Connecting ");
  WiFi.begin(ssid, password);

  // Show ... until connected:
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  // Print the IP address of the device:
  Serial.println(WiFi.localIP());

}

void loop() {
  WiFiClient client;

    HTTPClient http;  // HTTPClient object
    http.begin(client, getapidata);  
    int httpCode = http.GET(); // GET Request

    if (httpCode > 0) { //Check the returning code

      Serial.println("We got a repsonse!");
      String payload = http.getString();   // Get the response from the getapidata (1 or 0).
      Serial.println(payload); // Print getapidata value.
      digitalWrite(2, payload.toInt());
    }
    http.end();  //

  delay(5000);  //GET getapidata response at every 5 seconds
}
