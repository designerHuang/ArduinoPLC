#include <U8g2lib.h>
#include <SPI.h>
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, 52, 51, A14, A13/*NO-Reset*/);

void displayBegin(){
    u8g2.begin();
    Serial.println("display begin");
}