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
#define SENSORS_SIZE 6
typedef enum {
    PIN_SENSOR_1 = A7,
    PIN_SENSOR_2 = A6,
    PIN_SENSOR_3 = A5,
    PIN_SENSOR_4 = A4,
    PIN_SENSOR_5 = A3,
    PIN_SENSOR_6 = A2
} pin_sensor_t;

const pin_sensor_t sensor_pins[SENSORS_SIZE] = {PIN_SENSOR_1, PIN_SENSOR_2,
                                                PIN_SENSOR_3, PIN_SENSOR_4,
                                                PIN_SENSOR_5, PIN_SENSOR_6};

void setupSensorPins() {
    for (int i = 0; i < SENSORS_SIZE; i++)
        pinMode(sensor_pins[i], INPUT);
}

void readSensorsPins(bool values[SENSORS_SIZE]) {
    for (int i = 0; i < SENSORS_SIZE; i++) {
        int pin = sensor_pins[i];
        if (pin == A6 or pin == A7)
            values[i] = analogRead(pin) > 1000;
        else
            values[i] = digitalRead(pin);
    }
}

void readSensorsPins(int values[SENSORS_SIZE]) {
    for (int i = 0; i < SENSORS_SIZE; i++)
        values[i] = analogRead(sensor_pins[i]);
}

// SEGUIDOR
void setupSeguidorPins(bool shouldSetupExtraPins = false) {
    if (shouldSetupExtraPins) setupExtraPins();
    setupSensorPins();
    setupMotorPins();
}

#endif  //  __SEGUIDOR_PINOUT__
