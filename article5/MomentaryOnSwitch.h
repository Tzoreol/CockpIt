#ifndef MomentaryOnSwitch_h
#define MomentaryOnSwitch_h

#include "Arduino.h"

class MomentaryOnSwitch {
	public:
		MomentaryOnSwitch(int switchPin, int ledPin);
		void check();
	private:
		int _switchPin;
		int _ledPin;
		int _previousSwitchState;
		int _lastStateChange;
		int _switchState;
		bool _ledState;
};

#endif
