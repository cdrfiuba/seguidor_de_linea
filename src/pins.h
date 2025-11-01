#ifndef __SEGUIDOR_PINOUT__
#define __SEGUIDOR_PINOUT__

// MOTORES
#define PIN_MOTOR_IZQ_DIG 2
#define PIN_MOTOR_IZQ_PWM 3
#define PIN_MOTOR_DER_DIG 9
#define PIN_MOTOR_DER_PWM 10

void setupMotorPins() {
    pinMode(PIN_MOTOR_DER_DIG, OUTPUT);
    pinMode(PIN_MOTOR_DER_PWM, OUTPUT);
    pinMode(PIN_MOTOR_IZQ_DIG, OUTPUT);
    pinMode(PIN_MOTOR_IZQ_PWM, OUTPUT);
}

// EXTRA
#define PIN_BUTTON_START 12
#define PIN_LED_INDICATOR A1

void setupExtraPins() {
    pinMode(PIN_BUTTON_START, INPUT);
    pinMode(PIN_LED_INDICATOR, OUTPUT);
}

// SENSORES
#define PIN_SENSOR_1 A7
#define PIN_SENSOR_2 A6
#define PIN_SENSOR_3 A5
#define PIN_SENSOR_4 A4
#define PIN_SENSOR_5 A3
#define PIN_SENSOR_6 A2

void setupSensorPins() {
    pinMode(PIN_SENSOR_1, INPUT);
    pinMode(PIN_SENSOR_2, INPUT);
    pinMode(PIN_SENSOR_3, INPUT);
    pinMode(PIN_SENSOR_4, INPUT);
    pinMode(PIN_SENSOR_5, INPUT);
    pinMode(PIN_SENSOR_6, INPUT);
}

void setupSeguidorPins(bool shouldSetupExtraPins = false) {
    if (shouldSetupExtraPins) setupExtraPins();
    setupSensorPins();
    setupMotorPins();
}

#endif  //  __SEGUIDOR_PINOUT__
