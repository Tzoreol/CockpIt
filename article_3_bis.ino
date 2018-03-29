const int SWITCH = 12;
const int LED = 13;

const int pressDelay = 50; //Contante qui définie le temps nécessaire pour considérer un état comme volontaire

boolean lightUpLED = false;
int previous = HIGH;
int switchState = HIGH;
int lastCheckTime; //Variable où l'on va stocker le moment de derner changement d'état

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  lastCheckTime = millis();
}

void loop() {
  /*
   * LOW = Pressé
   * HIGH = Relaché
   * 
   * La condition ci-dessous vérifie si on a actionné l'interrupteur
   * Dans ce cas, on change d'état
   */

//Comme on l'utilise plusieurs fois, on stocke l'état de l'interrupteur à l'intant t
int now = digitalRead(SWITCH);

/*
 * Si changement d'état, on réinitialise la variable de dernière vérification avec un timestamp.
 * Un timestamp est le nombre de millisecondes écoulées depuis le 1er Janvier 1970
 * Il permet de comparer très précisément des dates et de connaitre l'iinteravale entre deux.
 */
if(previous != now) {
  lastCheckTime = millis(); //La fonction millis nous retourne le timestamp
}

/*
 * Le programme continue à faire ses boucles
 * Si un autre changement d'état est détecté, le chronomètre est réinitialisé
 * Le bloc suivant traite le cas où il n'y pas eu de changement dans le délai qui décrète le changement d'état comme volontaire 
 */

//On récupère le timestamp actuel auquel on soustrait celui sauvegardé. La différnece nous donne le temps entre les deux
 if((millis() - lastCheckTime) >= pressDelay) {
    //Si on rentre ici, le changement n'est pas parasitaire
    /*
     * On regarde s'il y changement d'état par rapport au dernier changement volontaire
     * Cela signifie que l'on a un demi-cycle de pression (soit de relaché à pressé, soit de pressé à relaché)
     * Si oui, on écrase l'état de l'interrupteur et on regarde s'il est relaché
     */
     if(switchState != now) {
      switchState = now;

      //Si l'interrupteur est relaché, on change l'état de la LED
      if(switchState == HIGH) {
        lightUpLED = !lightUpLED;
      }
     }
 }

 /*
  * A la fin de la boucle on demande à Arduino de mettre à LED à l'état où elle doit être
  * et de sauvegarder l'état actuel pour qu'il soit le précédent dans la prochaine itération
  */
  digitalWrite(LED, lightUpLED);
  previous = now;
}
