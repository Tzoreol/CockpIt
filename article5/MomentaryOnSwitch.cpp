#include "Arduino.h"
#include "MomentaryOnSwitch.h"

MomentaryOnSwitch::MomentaryOnSwitch(int switchPin, int ledPin) {
	pinMode(switchPin, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);
	_switchPin = switchPin;
	_ledPin = ledPin;
	_previousSwitchState = HIGH;
	_lastStateChange = millis();
	_switchState = HIGH;
	_ledState = false;
}

void MomentaryOnSwitch::check() {
	int now = digitalRead(_switchPin);
	if(_previousSwitchState != now) {
		_lastStateChange = millis();
   }
   
  if((millis() - _lastStateChange) >= 50) {
    if( _switchState != now) {
		 _switchState = now;

      if( _switchState == HIGH) {
        _ledState = !_ledState;;
      }
    }
  }

  digitalWrite(_ledPin, _ledState);
  _previousSwitchState = now;
}
