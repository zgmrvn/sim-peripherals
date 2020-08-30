// https://github.com/MHeironimus/ArduinoJoystickLibrary

#include "Joystick.h"

Joystick_ Joystick(
    JOYSTICK_DEFAULT_REPORT_ID, 
    JOYSTICK_TYPE_JOYSTICK,
    0,
    0,
    false, // X axis
    false, // Y axis
    false, // Z axis
    false,
    false,
    false,
    true, // rudder 
    true, // throttle 
    false,
    false, // brake 
    false
);

#define RUDDER A0
#define THROTTLE A1

void setup()
{
    pinMode(RUDDER, INPUT);
    pinMode(THROTTLE, INPUT);
    
    Joystick.setRudderRange(0, 1023);
    Joystick.setThrottleRange(0, 1023);
    Joystick.begin(false);

    // Serial.begin(9600);
}

void loop()
{
    Joystick.setRudder(analogRead(RUDDER));
    Joystick.setThrottle(analogRead(THROTTLE));

    Joystick.sendState();

    // Serial.println(analogRead(THROTTLE));
}
