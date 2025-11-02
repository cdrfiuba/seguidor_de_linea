#include "config.h"
#include "pins.h"

//int sensorPins[6] = {SENSOR_1, SENSOR_2, SENSOR_3,
//                     SENSOR_4, SENSOR_5, SENSOR_6};
int pesos[6] = {-5, -3, -1, 1,
                3,  5};  // pesos asignados a cada sensor, se los puede cambiar

bool running = false;

void mysetup() {
    Serial.begin(9600);
    setupSeguidorPins(true);
    //while(not digitalRead(PIN_BUTTON_START)) continue;
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
    bool lectura[6];
    int sumaPesada = 0;  // defino la suma d
    int sumaLecturas = 0;

    readSensorsPins(lectura, NEGRO);
    // Leer sensores y calcular suma pesada
    for (int i = 0; i < 6; i++) {
        sumaPesada += lectura[i] * pesos[i];  // la suma con sus pesos
        sumaLecturas += lectura[i];  // cuantos sensores estan prendidos
    }

    int error = 0;

    if (sumaLecturas > 0) {
        error = sumaPesada / sumaLecturas;  // promedio ponderado
    }

    // Mostrar info en el Monitor Serie
    Serial.print("Lecturas: ");
    for (int i = 0; i < 6; i++) {
        Serial.print(lectura[i]);
        Serial.print(" ");
    }
    Serial.print("| Error: ");
    Serial.print(error);

    int baseSpeed =
        80;  // defino una velocidad para arrancar(se la puede variar)
    int correction = error * 30;  // Ganancia proporcional

    int speedLeft = baseSpeed + correction;
    int speedRight = baseSpeed - correction;

    // Limito las velocidades, averiguar bien como hace para recortar
    speedLeft = constrain(speedLeft, 0, 255);
    speedRight = constrain(speedRight, 0, 255);

    Serial.print(" | L: ");
    Serial.print(speedLeft);
    Serial.print(" R: ");
    Serial.println(speedRight);

    analogWrite(PIN_MOTOR_IZQ_PWM, speedLeft);
    analogWrite(PIN_MOTOR_DER_PWM, speedRight);
    }
    
    delay(50);
}
