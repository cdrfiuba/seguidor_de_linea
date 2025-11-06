// Este programa decide cuanto girar, suave, medio o fuerte, segun que sensores
// se prende. Se fija una respuesta por cada convinacion de sensores prendidos.
// // tiene el problema de que cuando estan todos prendidos no diferencia entre
// ir derecho o estar perdido////

#include "pins.h"

#define tranqui 70
#define medio 110
#define fuerte 160
#define quieto 0

void mysetup() {
    setupMotorPins();
    setupSensorPins();
    delay(2000);
}

bool states[SENSORS_SIZE];

void myloop() {
    readSensorsPins(states);
    int sensor1 = states[0];
    int sensor2 = states[1];
    int sensor3 = states[2];
    int sensor4 = states[3];
    int sensor5 = states[4];
    int sensor6 = states[5];
    digitalWrite(PIN_MOTOR_DER_DIG, LOW);
    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    ////////////////////// 0 0 0 0 0 0  ////////////////////
    //////////////////////   SEGUIR DERECHO ///////////////////
    if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW &&
        sensor5 == LOW && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }

    ////////////////////// 0 0 1 0 0 0  ////////////////////
    ////////////////////// SUAVE A LA IZQUIERDA //////////////////
    else if (sensor1 == LOW && sensor2 == LOW && sensor3 == HIGH &&
             sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, medio);
    }

    ////////////////////// 0 0 0 1 0 0  ////////////////////
    //////////////////////  SUAVE A LA DERECHA //////////////////
    else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW &&
             sensor4 == HIGH && sensor5 == LOW && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, medio);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }

    ////////////////////// 0 1 0 0 0 0  ////////////////////
    ////////////////////// MEDIO A LA IZQUIERDA //////////////////
    else if (sensor1 == LOW && sensor2 == HIGH && sensor3 == LOW &&
             sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, tranqui);
    }

    ////////////////////// 0 0 0 0 1 0  ////////////////////
    ////////////////////// MEDIO A LA DERECHA //////////////////
    else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW &&
             sensor4 == LOW && sensor5 == HIGH && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, tranqui);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }

    ////////////////////// 1 0 0 0 0 0  ////////////////////
    ////////////////////// fUERTE A LA IZQUIERDA //////////////////
    else if (sensor1 == HIGH && sensor2 == LOW && sensor3 == LOW &&
             sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, quieto);
    }

    ////////////////////// 0 0 0 0 0 1  ////////////////////
    ////////////////////// FUERTE A LA DERECHA //////////////////
    else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW &&
             sensor4 == LOW && sensor5 == LOW && sensor6 == HIGH) {
        analogWrite(PIN_MOTOR_DER_PWM, quieto);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }

    ////////////////////// 1 1 0 0 0 0  ////////////////////
    //////////////////////  FURTE A LA IZQUIERDA //////////////////
    else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == LOW &&
             sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, quieto);
    }

    ////////////////////// 0 0 0 0 1 1  ////////////////////
    //////////////////////  FURTE A LA DERECHA //////////////////
    else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW &&
             sensor4 == LOW && sensor5 == HIGH && sensor6 == HIGH) {
        analogWrite(PIN_MOTOR_DER_PWM, quieto);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }

    ////////////////////// 0 1 1 0 0 0  ////////////////////
    ////////////////////// SUAVE A LA IZQUIERDA //////////////////
    else if (sensor1 == LOW && sensor2 == HIGH && sensor3 == HIGH &&
             sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, fuerte);
        analogWrite(PIN_MOTOR_IZQ_PWM, medio);
    }

    ////////////////////// 0 0 0 1 1 0  ////////////////////
    ////////////////////// SUAVE A LA DERECHA //////////////////
    else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW &&
             sensor4 == HIGH && sensor5 == HIGH && sensor6 == LOW) {
        analogWrite(PIN_MOTOR_DER_PWM, medio);
        analogWrite(PIN_MOTOR_IZQ_PWM, fuerte);
    }

    ////////////////////// 1 1 1 1 1 1  ////////////////////
    ////////////////////// INTERSECCIÓN DETECTADA //////////////////
    else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == HIGH &&
             sensor4 == HIGH && sensor5 == HIGH && sensor6 == HIGH) {
        analogWrite(PIN_MOTOR_DER_PWM, 0);
        analogWrite(PIN_MOTOR_IZQ_PWM, 0);
        // Opcional: pausa, giro, decisión especial
    }

    ////////////////////// OTROS CASOS - girar buscando ////////////////////
    else {
        analogWrite(PIN_MOTOR_DER_PWM, 100);
        analogWrite(PIN_MOTOR_IZQ_PWM, 0);
    }
}
