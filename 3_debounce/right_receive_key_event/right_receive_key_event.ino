#define BAUD_RATE 9600
#include <SoftwareSerial.h>
#include <Keyboard.h>

SoftwareSerial BT(8, 7);

void setup() {
    delay(200);
    BT.begin(BAUD_RATE);
    Keyboard.begin();
}

void loop() {
    if (BT.available()) {
        uint8_t recv = BT.read();
        if (recv & 0b10000000) {
            recv &= 0b01111111;
            switch (recv) {
                case 10:
                    Keyboard.release('a');
                    break;
                case 17:
                    Keyboard.release('s');
                    break;
                case 24:
                    Keyboard.release('d');
                    break;
                case 31:
                    Keyboard.release('f');
                    break;
            }
        } else {
            switch (recv) {
                case 10:
                    Keyboard.press('a');
                    break;
                case 17:
                    Keyboard.press('s');
                    break;
                case 24:
                    Keyboard.press('d');
                    break;
                case 31:
                    Keyboard.press('f');
                    break;
            }
        }
    }
}
