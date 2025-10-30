#define __TEST_M__
#ifdef __TEST_M__

#include "config.h"
#include "pins.h"

void mysetup() { setupMotorPins(); }

void avanzar() {
    digitalWrite(PIN_MOTOR_DER_DIG, LOW);
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    analogWrite(PIN_MOTOR_DER_PWM, MAX_VALUE_MOTOR_DER);
    analogWrite(PIN_MOTOR_IZQ_PWM, MAX_VALUE_MOTOR_IZQ);
}

void frenar() {
    digitalWrite(PIN_MOTOR_DER_DIG, LOW);
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    analogWrite(PIN_MOTOR_DER_PWM, LOW);
    analogWrite(PIN_MOTOR_IZQ_PWM, LOW);
}

void girarIzq() {
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    analogWrite(PIN_MOTOR_IZQ_PWM, LOW);

    digitalWrite(PIN_MOTOR_DER_DIG, LOW);
    analogWrite(PIN_MOTOR_DER_PWM, MAX_VALUE_MOTOR_DER);
}

void girarDer() {
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    analogWrite(PIN_MOTOR_IZQ_PWM, MAX_VALUE_MOTOR_IZQ);

    digitalWrite(PIN_MOTOR_DER_DIG, LOW);
    analogWrite(PIN_MOTOR_DER_PWM, 0);
}

bool test_finished = false;

void myloop() {
    if (not test_finished) {
        avanzar();
        delay(5000);
        frenar();
        delay(1000);

        girarIzq();
        delay(3000);
        frenar();
        delay(1000);

        avanzar();
        delay(5000);
        frenar();
        delay(1000);

        girarDer();
        delay(3000);
        frenar();
        delay(1000);
    }
    test_finished = true;
}

#endif
