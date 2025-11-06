/*
 * Disposición de los sensores en el modulo Sensor
 *  _________________________________________
 * |                                         |
 * |    S1    S2    S3    S4    S5    S6     |
 * |    _________                            |
 * |   |Integrado|                           |
 * |_________________________________________|
 *              | | | | | | | |
 *              1 2 3 4 5 6 V GND
 */

#include "pins.h"

const int blanco = HIGH;
const int negro = LOW;

bool sensors[SENSORS_SIZE];

float multiplicador_der = 1;  // multiplica la velocidad de la rueda derecha
float multiplicador_izq = 1;  // multiplica la velocidad de la rueda izquierda
float paso_multiplicador = 0.05;  // paso con el que se van variando los
                                  // multiplicadores en cada iteración

int velocidad_max = 150;  // puede variar entre 0 y 255

// Reestablece los multiplicadores para que avance recto
void centrar() {
    multiplicador_der = 1;
    multiplicador_izq = 1;
}

// recibe un valor entre 0 y 1 que modifica el multiplicador adecuado
void doblar_izquierda(float val) {
    if (multiplicador_der + val < 1) {
        multiplicador_der = multiplicador_der + val;
    }

    else if (multiplicador_der + val > 1 && multiplicador_der != 1) {
        multiplicador_der = 1;
    }

    else if (multiplicador_der == 1 && multiplicador_izq - val > 0) {
        multiplicador_izq = multiplicador_izq - val;
    }

    else if (multiplicador_der == 1 && multiplicador_izq - val < 0) {
        multiplicador_izq = 0;
    }
}

// recibe un valor entre 0 y 1 que modifica el multiplicador adecuado
void doblar_derecha(float val) {
    if (multiplicador_izq + val < 1) {
        multiplicador_izq = multiplicador_izq + val;
    }

    else if (multiplicador_izq + val > 1 && multiplicador_izq != 1) {
        multiplicador_izq = 1;
    }

    else if (multiplicador_izq == 1 && multiplicador_der - val > 0) {
        multiplicador_der = multiplicador_der - val;
    }

    else if (multiplicador_izq == 1 && multiplicador_der - val < 0) {
        multiplicador_der = 0;
    }
}

void mysetup() {
    setupSeguidorPins();

    // Espera a que se accione el pulsador para comenzar a correr el código
    while (not digitalRead(PIN_BUTTON_START));
}

void myloop() {
    readSensorsPins(sensors);
    if (sensors[5] == HIGH) doblar_izquierda(2 * paso_multiplicador);
    if (sensors[4] == HIGH) doblar_izquierda(paso_multiplicador);
    if (sensors[3] == HIGH && sensors[2] == HIGH) centrar();
    if (sensors[1] == HIGH) doblar_derecha(paso_multiplicador);
    if (sensors[0] == HIGH) doblar_derecha(2 * paso_multiplicador);

    digitalWrite(PIN_MOTOR_IZQ_DIG, LOW);
    analogWrite(PIN_MOTOR_IZQ_PWM, velocidad_max * multiplicador_der);
    digitalWrite(PIN_MOTOR_DER_DIG, LOW);
    analogWrite(PIN_MOTOR_DER_PWM, velocidad_max * multiplicador_izq);

    delay(50);
}
