#include "pins.h"

#define tranqui 80
#define medio 110
#define fuerte 160

void mysetup() {
    setupMotorPins();
    setupSensorPins();
    delay(2000);
}

void myloop() {
    int sensor1 = digitalRead(SENSOR_1);
    int sensor2 = digitalRead(SENSOR_2);
    int sensor3 = digitalRead(SENSOR_3);
    int sensor4 = digitalRead(SENSOR_4);
    int sensor5 = digitalRead(SENSOR_5);
    int sensor6 = digitalRead(SENSOR_6);
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    digitalWrite(PIN_MOTOR_DER_DIG, LOW);

    //////////////////////   SEGUIR DERECHO////////////////////
    if (sensor3 == LOW && sensor4 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }
    /////////////// sensor 3 prendido-> tranqui a la derecha///////////////
    else if (sensor3 == HIGH && sensor4 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, medio);
        analogWrite(PIN_MOTOR_IZQ_PWM, tranqui);
    }

    /////////////// sensor 4 prendido-> tranqui a la izquierda///////////////
    else if (sensor3 == LOW && sensor4 == HIGH) {
        analogWrite(PIN_MOTOR_DER_PWM, tranqui);
        analogWrite(PIN_MOTOR_IZQ_PWM, medio);
    }
}
