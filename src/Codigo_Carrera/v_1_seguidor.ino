#define MOTOR_DER 9
#define MOTOR_IZQ 8
#define MOTOR_DER_0 11
#define MOTOR_IZQ_0 10
#define SENSOR_1 1  //el sensor 1 esta a la izq y el 6 a la derecha
#define SENSOR_2 2
#define SENSOR_3 3 //   0 0 0 0 0 0
#define SENSOR_4 4 //   1 2 3 4 5 6
#define SENSOR_5 5
#define SENSOR_6 6
#define tranqui 150
#define medio 200
#define fuerte 255

void setup() {
pinMode(MOTOR_DER,OUTPUT);// motor derecho
pinMode(MOTOR_IZQ,OUTPUT);//motor izquierdo
pinMode(MOTOR_DER_0,OUTPUT);
pinMode(MOTOR_IZQ_0, OUTPUT);
pinMode(SENSOR_1,INPUT);
pinMode(SENSOR_2,INPUT);
pinMode(SENSOR_3,INPUT);
pinMode(SENSOR_4,INPUT);
pinMode(SENSOR_5,INPUT);
pinMode(SENSOR_6,INPUT);
delay(2000);
}

void loop() {

 int sensor1 = digitalRead(SENSOR_1);  
 int sensor2 = digitalRead(SENSOR_2);  
 int sensor3 = digitalRead(SENSOR_3);
 int sensor4 = digitalRead(SENSOR_4);
 int sensor5 = digitalRead(SENSOR_5);
 int sensor6 = digitalRead(SENSOR_6);
digitalWrite(MOTOR_DER_0,LOW);
digitalWrite(MOTOR_DER_0,LOW);


 
 //////////////////////   SEGUIR DERECHO////////////////////
 if (sensor3 == LOW && sensor4 == LOW) {  
    analogWrite(MOTOR_DER, fuerte);
    analogWrite(MOTOR_IZQ, fuerte);
  }
/////////////// sensor 3 prendido-> tranqui a la derecha///////////////
else if (sensor3 == HIGH && sensor4 == LOW) {
    analogWrite(MOTOR_DER, fuerte);
    analogWrite(MOTOR_IZQ, medio);
  }


 /////////////// sensor 4 prendido-> tranqui a la izquierda///////////////
else if (sensor3 ==LOW  && sensor4 == HIGH) { 
    analogWrite(MOTOR_DER, medio);
    analogWrite(MOTOR_IZQ, fuerte);
  }

}
