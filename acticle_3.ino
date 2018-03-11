const int SWITCH = 12;

boolean lightUpLED = false;
int previous = 1;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  /*
   * 0 = Pressé
   * 1 = Relaché
   * 
   * La condition ci-dessous vérifie si on a actionné l'interrupteur
   * Dans ce cas, on change d'état
   */
 Serial.println(digitalRead(SWITCH));
 if(previous == 0 && digitalRead(SWITCH) == 1) {
    lightUpLED = !lightUpLED;
 }

 digitalWrite(LED_BUILTIN, lightUpLED);
 previous = digitalRead(SWITCH);
}
