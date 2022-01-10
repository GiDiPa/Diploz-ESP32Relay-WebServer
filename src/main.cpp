#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <EEPROM.h>
//#include <DNSServer.h>


//EEPROM test
#define EEPROM_SIZE 2

// Set to true to define Relay as Normally Open (NO)
#define RELAY_NO   true

// Set number of relays
#define NUM_RELAYS  2

const int output1 = 16;
const int output2 = 17;

// Assign each GPIO to a relay
int relayGPIOs[NUM_RELAYS] = {18, 19};

// Replace with your network credentials
const char* ssid     = "4ch";
const char* password = "12345678";

const char* PARAM_INPUT_1 = "relay";  
const char* PARAM_INPUT_2 = "state";

// Set web server port number to 80
//const byte DNS_PORT = 53;
//DNSServer dnsServer;
AsyncWebServer server(80);

String relayState(int numRelay){
  if(RELAY_NO){
    if(digitalRead(relayGPIOs[numRelay-1])){
      return "";
    }
    else {
      return "checked";
    }
  }
  else {
    if(digitalRead(relayGPIOs[numRelay-1])){
      return "checked";
    }
    else {
      return "";
    }
  }
  return "";
}

String processor(const String& var){
  //Serial.println(var);
  if(var == "BUTTONPLACEHOLDER"){
    String buttons ="";
    for(int i=1; i<=NUM_RELAYS; i++){
      String relayStateValue = relayState(i);
      buttons+= "<div class=\"col-md-6 col-sm-6 col-6 noselect\"><h4>Channel " + String(i+2) + "</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox34(this)\" id=\"" + String(i) + "\" "+ relayStateValue +"><span class=\"slider\"></span></label></div>";
    }
    return buttons;
  }
  return String();
}

void setup() {
  Serial.begin(115200);

  for(int i=1; i<=NUM_RELAYS; i++){
    pinMode(relayGPIOs[i-1], OUTPUT);
    if(RELAY_NO){
      digitalWrite(relayGPIOs[i-1], HIGH);
    }
    else{
      digitalWrite(relayGPIOs[i-1], LOW);
    }
  }

  if(!SPIFFS.begin()){
     Serial.println("An Error has occurred while mounting SPIFFS");
     return;
  }
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password,1,0,10);
  delay(100);

  IPAddress Ip = IPAddress (192, 168, 1, 1); // curly braces
  IPAddress NMask = IPAddress (255, 255, 255, 0); // not curly braces

  WiFi.softAPConfig(Ip, Ip, NMask);

 // dnsServer.setTTL(300);
 // dnsServer.setErrorReplyCode(DNSReplyCode::ServerFailure);

  pinMode(output1, OUTPUT);
  digitalWrite(output1, LOW);

  pinMode(output2, OUTPUT);
  digitalWrite(output2, LOW);

  //dnsServer.start(DNS_PORT, "*", Ip);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.on("/src/bootstrap.bundle.min.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/bootstrap.bundle.min.js", "text/javascript");
  });
 
  server.on("/src/jquery-3.6.0.min.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/jquery-3.6.0.min.js", "text/javascript");
  });
 
  server.on("/src/bootstrap.min.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/bootstrap.min.css", "text/css");
  });
  
  server.on("/src/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/style.css", "text/css");
  });

  server.on("/sw.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/sw.js", "text/javascript");
  });

  server.on("/src/app.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/app.js", "text/javascript");
  });

  server.on("/manifest.json", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/manifest.json", "application/json");
  });

  server.on("/src/an36.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an36.png", "image/png");
  });

  server.on("/src/an48.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an48.png", "image/png");
  });

  server.on("/src/an72.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an72.png", "image/png");
  });

  server.on("/src/an96.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an96.png", "image/png");
  });

  server.on("/src/an192.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an192.png", "image/png");
  });

  server.on("/src/an144.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an144.png", "image/png");
  });

  server.on("/src/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/favicon.ico", "image/x-icon");
  });

  server.on("/src/ap57.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an36.png", "image/png");
  });
  
  server.on("/src/ap76.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an36.png", "image/png");
  });

  server.on("/src/ap144.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an36.png", "image/png");
  });

  server.on("/src/ap180.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an36.png", "image/png");
  });

  server.on("/src/apicon.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an36.png", "image/png");
  });

  server.on("/src/apprec.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/src/an36.png", "image/png");
  });


  server.on("/on1", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(output1, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // Receive an HTTP GET request
  server.on("/off1", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(output1, LOW);
    request->send(200, "text/plain", "ok");
  });
 

  server.on("/on2", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(output2, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // Receive an HTTP GET request
  server.on("/off2", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(output2, LOW);
    request->send(200, "text/plain", "ok");
  });

  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    String inputParam;
    String inputMessage2;
    String inputParam2;
    // GET input1 value on <ESP_IP>/update?relay=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1) & request->hasParam(PARAM_INPUT_2)) {
      inputMessage = request->getParam(PARAM_INPUT_1)->value();
      inputParam = PARAM_INPUT_1;
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      inputParam2 = PARAM_INPUT_2;
      if(RELAY_NO){
        digitalWrite(relayGPIOs[inputMessage.toInt()-1], !inputMessage2.toInt());
      }
      else{
        digitalWrite(relayGPIOs[inputMessage.toInt()-1], inputMessage2.toInt());
      }
    }
    else {
      inputMessage = "No message sent";
      inputParam = "none";
    }
    request->send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop(){
  //dnsServer.processNextRequest();
  if (WiFi.softAPgetStationNum() < 10){
    Serial.print("Stations connected: ");
    Serial.println(WiFi.softAPgetStationNum());
    delay(5000);
  }
  else{
    Serial.println("max connection reached. Disabling Wifi in 30 seconds.");
    delay(30000);
    WiFi.enableAP(false);
    Serial.println("Disabled. Please wait 10 seconds.");
    delay(10000);
    WiFi.enableAP(true);
    Serial.println("Enabling Wifi...");
  }
}

