#include "pins.h"

#define tranqui 80
#define medio 110
#define fuerte 160

void mysetup() {
    setupMotorPins();
    setupSensorPins();
    delay(2000);
}

bool states[SENSORS_SIZE] = {0};

void myloop() {
    readSensorsPins(states);
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    digitalWrite(PIN_MOTOR_DER_DIG, LOW);

    //////////////////////   SEGUIR DERECHO////////////////////
    if (states[2] == LOW && states[3] == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }
    /////////////// sensor 3 prendido-> tranqui a la derecha///////////////
    else if (states[2] == HIGH && states[3] == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, medio);
        analogWrite(PIN_MOTOR_IZQ_PWM, tranqui);
    }

    /////////////// sensor 4 prendido-> tranqui a la izquierda///////////////
    else if (states[2] == LOW && states[3] == HIGH) {
        analogWrite(PIN_MOTOR_DER_PWM, tranqui);
        analogWrite(PIN_MOTOR_IZQ_PWM, medio);
    }
}
