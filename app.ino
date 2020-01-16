#include <Free_Fonts.h>
#include <gitTagVersion.h>
#include <LoRaWan.h>
#include <M5Display.h>
#include <M5Faces.h>
#include <M5LoRa.h>
#include <M5Stack.h>
#include <stdio.h>
#include <unistd.h>

unsigned int guiBtnA_Time;
unsigned int guiBtnB_Time;
unsigned int guiBtnC_Time;
int hz = 1;

void setup()
{
    // M5Stackの初期化
    M5.begin();

    // 初期化
    guiBtnA_Time = 0;
    guiBtnB_Time = 0;
    guiBtnC_Time = 0;
    // 文字サイズを変更
    M5.Lcd.setTextSize(2);
    // Aボタン　カウンタ表示
    M5.Lcd.setCursor(50, 50);
    M5.Lcd.printf("Button A : %d", guiBtnA_Time);
    // Bボタン　カウンタ表示
    M5.Lcd.setCursor(50, 100);
    M5.Lcd.printf("Button B : %d", guiBtnB_Time);
    // Cボタン　カウンタ表示
    M5.Lcd.setCursor(50, 150);
    M5.Lcd.printf("Button C : %d", guiBtnC_Time);
}

void loop()
{

    M5.update();
    // Aボタン
    // if (M5.BtnA.wasPressed())
    if (M5.BtnA.isPressed())
    {
        guiBtnA_Time++;
        // カウンタ表示
        M5.Lcd.setCursor(50, 50);
        M5.Lcd.printf("Button A : %d", guiBtnA_Time);
    }
    // Bボタン
    if (M5.BtnB.isPressed())
    {
        // カウンタ更新
        guiBtnB_Time++;
        // カウンタ表示
        M5.Lcd.setCursor(50, 100);
        M5.Lcd.printf("Button B : %d", guiBtnB_Time);
    }
    // Cボタン
    if (M5.BtnC.isPressed())
    {
        // カウンタ更新
        guiBtnC_Time++;
        // カウンタ表示
        M5.Lcd.setCursor(50, 150);
        M5.Lcd.printf("Button C : %d", guiBtnC_Time);
    }
    usleep(1000000 / hz);
}
