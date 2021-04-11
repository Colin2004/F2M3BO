/*
 * Duurzaam Huis
 * Temperature + Humidity Sensor DHT11
 * transmit data to Ma-cloud
 * MediaCollege Amsterdam apr 2021
*/
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
// your data = student nummer
String deviceID = "123456_test"; // let op geen spaties
/* 
 *  temperature + humidity sensor type DHT11
 */
#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11 sensor
uint8_t DHTPin = D7; // DHT Sensor data output 
DHT dht(DHTPin, DHTTYPE);  // Initialize DHT sensor.    
float Temperature;
float Humidity;
float HeatIndex;
int LightLevel = 0; // LDR sensor not in the hardware setup yet
/* 
 *  LDR light dependent resistor 10k
 *  voltage divider resistor 10k
 *  on analog input A0
 */
uint8_t analog_in = A0; // 
 
/*
 * Wifi Network
 * insert here your own network Wifi Credentials 
*/
const char* ssid     = "Medialab"; // wifi lan
const char* password = "Mediacollege"; // wifi lan
/*
 * Ma-cloud 
*/
String server  = "http://31761.hosts1.ma-cloud.nl";          // deployment server
String pathSendData = "/duurzaam1/jsonWrite.php?src=esp&data="; // path to file

// Slow it down 
const int wait = 10000;  // msec between data requests


void setup () {
  Serial.begin(115200); // start serial monitor 
  dht.begin();          // start DHT11 sensor
}
 
void loop() {  
  if (WiFi.status() != WL_CONNECTED) wifiConnect();// reconnect Wifi if necessary 
  if (WiFi.status() == WL_CONNECTED) { //if connected
     readDHT11();  // get sensor readings from DHT11
     LightLevel = readLDR(); // get light sensor
     httpRequestSendData(); // write data to server
  }
  delay(wait);    //Send a request every XXX seconds
}

void wifiConnect(){
  WiFi.begin(ssid, password); // connect to wifi ssid with password 
  while (WiFi.status() != WL_CONNECTED) {
      delay(1000); // wait 1 sec
      Serial.print("Connecting..");
      }
  //if connected
  Serial.print("\r\nConnected: IP address: "); 
  Serial.println(WiFi.localIP());
 }

void httpRequestSendData(){
  StaticJsonDocument<200> jsonDoc; // 
  // create an empty array, arrayLocalData
  JsonArray arrayLocalData = jsonDoc.to<JsonArray>();
  arrayLocalData.add("temperature"); 
  arrayLocalData.add(Temperature); // value from DHT11
  arrayLocalData.add("humidity");
  arrayLocalData.add(Humidity); // value from DHT11
  arrayLocalData.add("heatindex");
  arrayLocalData.add(HeatIndex); // value from DHT11
  arrayLocalData.add("light");
  arrayLocalData.add(LightLevel); // value from DHT11
  arrayLocalData.add("deviceID");
  arrayLocalData.add(deviceID); // device identity
  String serverString;
  serializeJson(jsonDoc, serverString);
  
  HTTPClient http;                   //Instance of class HTTPClient
  String url = server + pathSendData  + serverString;
  Serial.println(url);               // handig voor debuggen
  http.begin(url);                   //Specify request destination
  int httpCode = http.GET();         //Send the request  
  }

 void readDHT11(){
  /* 
   *  read the sensor
   *  sampling rate DHT11 is max. 1Hz 
   *  the DHT11 is known for erroneous readings
   */
    float temperature =  round(dht.readTemperature()*10)/10; // Gets the values of the temperature
    float humidity = round(dht.readHumidity()*10)/10; // Gets the values of the humidity
    float heatindex = round(dht.computeHeatIndex( Temperature, Humidity, false)*10)/10; 
    // Compute heat index in Celsius (isFahrenheit = false)
    if(isnan(temperature) || isnan(humidity) || isnan(heatindex)){
        // sensor error
        Serial.println("DHT11 sensor error");
    }
    else{
        // the DHT11 readings look ok 
        Temperature = temperature;
        Humidity =  humidity ;
        HeatIndex = heatindex;
      }
 } 
/*
 * LDR lightlevel not implemented in hardware
 */
 int readLDR(){
    int inputVal = analogRead (analog_in); // Analog Values 0 to 1023
    /*
     * inputVal dark 1023
     * inputval bright 135
     * inputVal intermediate light 300
     * convert to dark 1 light 100
     */
    int outputVal = map(inputVal, 135, 1023, 100, 1);
    Serial.print("LDR light"); 
    Serial.println(outputVal);
    return outputVal;
  }
