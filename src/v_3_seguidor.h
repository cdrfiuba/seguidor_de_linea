#include "config.h"
#include "pins.h"

// defino una velocidad para arrancar(se la puede variar)
#define BASE_SPEED 80
#define PROPORTIONAL_GAIN 30

// pesos asignados a cada sensor, se los puede cambiar
int pesos[6] = {-5, -3, -1, 1, 3, 5};

bool running = false;

void mysetup() {
    Serial.begin(9600);
    setupSeguidorPins(true);
    // while(not digitalRead(PIN_BUTTON_START)) continue;
}

void print_info(bool lectura[SENSORS_SIZE], int error, int speedLeft,
                int speedRight) {
    Serial.print("Lecturas: ");
    for (int i = 0; i < SENSORS_SIZE; i++) {
        Serial.print(lectura[i]);
        Serial.print(" ");
    }
    Serial.print("| Error: ");
    Serial.print(error);

    Serial.print(" | L: ");
    Serial.print(speedLeft);
    Serial.print(" R: ");
    Serial.println(speedRight);
}

void myloop() {
    if (digitalRead(PIN_BUTTON_START)) {
        running = not running;
        digitalWrite(PIN_LED_INDICATOR, running);
        digitalWrite(PIN_MOTOR_IZQ_PWM, LOW);
        digitalWrite(PIN_MOTOR_DER_PWM, LOW);
        delay(500);
    }
    if (running) {
        bool lectura[SENSORS_SIZE];
        int sumaPesada = 0;  // defino la suma d
        int sumaLecturas = 0;

        readSensorsPins(lectura, BLANCO);
        // Leer sensores y calcular suma pesada
        for (int i = 0; i < SENSORS_SIZE; i++) {
            sumaPesada += lectura[i] * pesos[i];  // la suma con sus pesos
            sumaLecturas += lectura[i];  // cuantos sensores estan prendidos
        }

        int error = 0;

        if (sumaLecturas > 0) {
            error = sumaPesada / sumaLecturas;  // promedio ponderado
        }

        int correction = error * PROPORTIONAL_GAIN;

        int speedLeft = BASE_SPEED + correction;
        int speedRight = BASE_SPEED - correction;

        // Limito las velocidades, averiguar bien como hace para recortar
        speedLeft = constrain(speedLeft, 0, MAX_VALUE_MOTOR_IZQ);
        speedRight = constrain(speedRight, 0, MAX_VALUE_MOTOR_DER);

        print_info(lectura, error, speedLeft, speedRight);

        analogWrite(PIN_MOTOR_IZQ_PWM, speedLeft);
        analogWrite(PIN_MOTOR_DER_PWM, speedRight);
    }
    delay(50);
}
