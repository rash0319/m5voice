#include <Free_Fonts.h>
#include <gitTagVersion.h>
#include <LoRaWan.h>
#include <M5Display.h>
#include <M5Faces.h>
#include <M5LoRa.h>
#include <M5Stack.h>
#include <stdio.h>
#include <unistd.h>

#define MIC 36
#define SAMPLING_FREQUENCY 40000
#define MAXTIME 3600
#define SAMPLES 144000000

int *buff = 0;
unsigned int sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQUENCY));

void setup()
{
    M5.begin();
    M5.Speaker.write(0); // スピーカーをオフする
    Serial.begin(115200);
    while (!Serial)
        ;
    M5.lcd.setBrightness(20); // LCDバックライトの輝度を下げる

    pinMode(MIC, INPUT);

    delay(1000);
}

void loop()
{
}