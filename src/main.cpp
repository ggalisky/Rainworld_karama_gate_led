#include <Config.h>
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <WiFi.h>
#include <AutoConnect.h>
#include <WebServer.h>
#include <NTPClient.h>

#include <Display.h>
#include <OpenTransportDataSwiss.h>




#define AP_NAME "usb_c_adapter_2.4"
#define AP_PASSWORD "redwindow509"
#define TIME_SERVER "0.ch.pool.ntp.org"

// Api
#define OPEN_DATA_API_KEY "XXXXX"
#define OPEN_DATA_URL "https://api.opentransportdata.swiss/trias2020"
#define OPEN_DATA_STATION "8576193" // Zürich Bellevue
#define OPEN_DATA_RESULTS "5"
#define OPEN_DATA_DIRECTION "A" // H = Outward, R = Return, A = All

// Display
#define R1_PIN 25 // TCK
#define G1_PIN 26 //
#define B1_PIN 27
#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13
#define A_PIN 23
#define B_PIN 19
#define C_PIN 5
#define D_PIN 17
#define E_PIN 22 // required for 1/32 scan panels, like 64x64. Any available pin would do, i.e. IO32
#define LAT_PIN 4
#define OE_PIN 15
#define CLK_PIN 16
#define PANEL_RES_X 128 // Number of pixels wide of each INDIVIDUAL panel module.
#define PANEL_RES_Y 64  // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1   // Total number of panels chained one to another




// Set offset time in seconds to adjust for your timezone, for example:
// GMT +1 = 3600
// GMT +8 = 28800
// GMT -1 = -3600
// GMT 0 = 0
int timeOffset = 3600;
const char timeServer[18] = TIME_SERVER;
int sensorValue;
int loopCounter = 0;

OpenTransportDataSwiss api(
    OPEN_DATA_STATION,
    OPEN_DATA_DIRECTION,
    OPEN_DATA_URL,
    OPEN_DATA_API_KEY,
    OPEN_DATA_RESULTS);

Display display;

WebServer Server;
AutoConnect Portal(Server);
AutoConnectConfig Config;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, timeServer, timeOffset, 60000);
WiFiClient client;

bool startCP(IPAddress ip)
{
  display.connectionMsg(AP_NAME, AP_PASSWORD);
  delay(10000);
  return true;
}

void setup()
{
  delay(1000);

#ifdef DEBUG
  Serial.begin(MONITOR_SPEED);
  Serial.setDebugOutput(true);
  Serial.println("Debug Enabled");
#endif

  display.begin(
      R1_PIN,
      G1_PIN,
      B1_PIN,
      R2_PIN,
      G2_PIN,
      B2_PIN,
      A_PIN,
      B_PIN,
      C_PIN,
      D_PIN,
      E_PIN,
      LAT_PIN,
      OE_PIN,
      CLK_PIN,
      PANEL_RES_X,
      PANEL_RES_Y,
      PANEL_CHAIN);

      display.displaySetBrightness(190);

  display.showSplash();

  //delay(10000);

  display.bruh();
  delay(1000);

      uint32_t freq = 240;
    setCpuFrequencyMhz(freq);


  
}

void loop()
{
  display.showSplash();
  //Serial.println("test");
  
}
