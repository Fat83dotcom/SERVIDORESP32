#include <Arduino.h>
#include "Confidentials.h"
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>

#define LARGURA_OLED 128
#define ALTURA_OLED 64
Adafruit_SSD1306 display (LARGURA_OLED, ALTURA_OLED, &Wire, -1);

byte pinCanais[10] = {13, 12, 14, 27, 26, 25, 33, 32, 35, 34};

#define mtIDENTIFICAR 0
#define mtGET 1
#define mtPOST 2
#define mtOUTRO 3

WiFiServer server(80);
WiFiClient client;
unsigned long delayClose;

void setup() {
    Serial.begin(9600);
    for (byte i = 0; i < 10; i++) {
        pinMode(pinCanais[i], OUTPUT);
    }
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("Endereço do visor não encontrado!!! Por favor, reinicie o MCu."));
        while (true);
        
    }
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(14, 17);
    display.print(F("Conectando em "));
    display.print(ssid);
    display.println("...");
    display.display();

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        display.print(".");
        display.display();
        
    }
    display.clearDisplay();
    display.setCursor(14, 17);
    display.println("WiFi conectado!");
    display.setCursor(14, 27);
    display.println("Endereco IP: ");
    display.setCursor(14, 37);
    display.print(WiFi.localIP());
    display.display();

    server.begin();
}

void run() {
    
}

void loop() {
  
}