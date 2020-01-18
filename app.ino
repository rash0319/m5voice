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

// 人の声は約500~1000Hz
// ↑のナイキスト周波数は1000~2000Hz
// 余裕を持って3000に
#define SAMPLING_FREQUENCY 3000

// ArduinoのRAMだとこの辺が限界
#define SAMPLES 45000

// 録音可能時間 SAMPLES/SAMPLING_FREQUENCY
#define MAXTIME 15

// 0~4095が入ればいいのでshort型にする
short buff[SAMPLES];

unsigned int sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQUENCY));

int count = 0;

void setup()
{
    // M5Stackの初期化
    M5.begin();
    M5.Speaker.write(0); // スピーカーをオフする
    Serial.begin(115200);
    while (!Serial)
        ;
    M5.lcd.setBrightness(20); // LCDバックライトの輝度を下げる

    // 文字サイズを変更
    M5.Lcd.setTextSize(2);
    // Aボタン　カウンタ表示
    M5.Lcd.setCursor(50, 50);
    M5.Lcd.printf("Status : StandBy");

    pinMode(MIC, INPUT);

    delay(1000);
}

void loop()
{

    M5.update();
    // Aボタン
    unsigned long t = micros();
    if (M5.BtnA.isPressed())
    {
        buff[count] = analogRead(MIC);
        M5.Lcd.setCursor(50, 50);
        M5.Lcd.printf("Status : Sampling...");
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.printf("Time remaining: %d second", int(MAXTIME - (count / SAMPLING_FREQUENCY)));
        count++;
    }

    if (M5.BtnA.wasReleased())
    {
        for (int i = 0; i < count; i++)
        {
            Serial.println(buff[i]);
        }
        for (int i = 0; i < SAMPLES; i++)
        {
            buff[i] = 0;
        }

        M5.Lcd.setCursor(50, 50);
        M5.Lcd.printf("Status : Success!!");

        count = 0;
    }

    while ((micros() - t) < sampling_period_us)
        ;
}
