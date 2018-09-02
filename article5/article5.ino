#include <MomentaryOnSwitch.h>

const int SWITCH = 12;
const int LED = 13;
const int SWITCH2 = 10;
const int LED2 = 11;

MomentaryOnSwitch switch1(12,13);
MomentaryOnSwitch switch2(10,11);

void setup() {
  Serial.begin(9600);
}

void loop() {
 switch1.check();
 switch2.check();
}
