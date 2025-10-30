#ifndef __SEGUIDOR_PINOUT__
#define __SEGUIDOR_PINOUT__

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

#endif  // __SEGUIDOR_PINOUT__

#ifndef __SENSOR_PINOUT__
#define __SENSOR_PINOUT__

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

#endif  // __SENSOR_PINOUT__
