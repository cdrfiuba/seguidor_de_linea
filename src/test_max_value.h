#ifdef __MAX_V__

#include "pins.h"
#include "config.h"

void mysetup() {
    setupMotorPins();
}

void myloop() {
    digitalWrite(PIN_MOTOR_DER_DIG, LOW);
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    analogWrite(PIN_MOTOR_DER_PWM, MAX_VALUE_MOTOR_DER);
    analogWrite(PIN_MOTOR_IZQ_PWM, MAX_VALUE_MOTOR_IZQ);
}

#endif // __MAX_V__
