#ifdef __V2__
//Este programa decide cuanto girar, suave, medio o fuerte, segun que sensores se prende. Se fija una respuesta por cada convinacion de sensores prendidos. //
//tiene el problema de que cuando estan todos prendidos no diferencia entre ir derecho o estar perdido////

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
#define quieto 0

void mysetup() {
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

void myloop() {

 int sensor1 = digitalRead(SENSOR_1);  
 int sensor2 = digitalRead(SENSOR_2);  
 int sensor3 = digitalRead(SENSOR_3);
 int sensor4 = digitalRead(SENSOR_4);
 int sensor5 = digitalRead(SENSOR_5);
 int sensor6 = digitalRead(SENSOR_6);
digitalWrite(MOTOR_DER_0,LOW);
digitalWrite(MOTOR_DER_0,LOW);
////////////////////// 0 0 0 0 0 0  ////////////////////
//////////////////////   SEGUIR DERECHO ///////////////////
if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {  
  analogWrite(MOTOR_DER, fuerte);
  analogWrite(MOTOR_IZQ, fuerte);
}

////////////////////// 0 0 1 0 0 0  ////////////////////
////////////////////// SUAVE A LA IZQUIERDA //////////////////
else if (sensor1 == LOW && sensor2 == LOW && sensor3 == HIGH && sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
  analogWrite(MOTOR_DER, fuerte);
  analogWrite(MOTOR_IZQ, medio);
}

////////////////////// 0 0 0 1 0 0  ////////////////////
//////////////////////  SUAVE A LA DERECHA //////////////////
else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == HIGH && sensor5 == LOW && sensor6 == LOW) { 
  analogWrite(MOTOR_DER, medio);
  analogWrite(MOTOR_IZQ, fuerte);
}

////////////////////// 0 1 0 0 0 0  ////////////////////
////////////////////// MEDIO A LA IZQUIERDA //////////////////
else if (sensor1 == LOW && sensor2 == HIGH && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
  analogWrite(MOTOR_DER, fuerte);
  analogWrite(MOTOR_IZQ, tranqui);
}

////////////////////// 0 0 0 0 1 0  ////////////////////
////////////////////// MEDIO A LA DERECHA //////////////////
else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == HIGH && sensor6 == LOW) {
  analogWrite(MOTOR_DER, tranqui);
  analogWrite(MOTOR_IZQ, fuerte);
}

////////////////////// 1 0 0 0 0 0  ////////////////////
////////////////////// fUERTE A LA IZQUIERDA //////////////////
else if (sensor1 == HIGH && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
  analogWrite(MOTOR_DER, fuerte);
  analogWrite(MOTOR_IZQ, quieto);
}

////////////////////// 0 0 0 0 0 1  ////////////////////
////////////////////// FUERTE A LA DERECHA //////////////////
else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW && sensor6 == HIGH) {
  analogWrite(MOTOR_DER, quieto);
  analogWrite(MOTOR_IZQ, fuerte);
}

////////////////////// 1 1 0 0 0 0  ////////////////////
//////////////////////  FURTE A LA IZQUIERDA //////////////////
else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
  analogWrite(MOTOR_DER, fuerte);
  analogWrite(MOTOR_IZQ, quieto);
}

////////////////////// 0 0 0 0 1 1  ////////////////////
//////////////////////  FURTE A LA DERECHA //////////////////
else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == HIGH && sensor6 == HIGH) {
  analogWrite(MOTOR_DER, quieto);
  analogWrite(MOTOR_IZQ, fuerte);
}

////////////////////// 0 1 1 0 0 0  ////////////////////
////////////////////// SUAVE A LA IZQUIERDA //////////////////
else if (sensor1 == LOW && sensor2 == HIGH && sensor3 == HIGH && sensor4 == LOW && sensor5 == LOW && sensor6 == LOW) {
  analogWrite(MOTOR_DER, fuerte);
  analogWrite(MOTOR_IZQ, medio);
}

////////////////////// 0 0 0 1 1 0  ////////////////////
////////////////////// SUAVE A LA DERECHA //////////////////
else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == HIGH && sensor5 == HIGH && sensor6 == LOW) {
  analogWrite(MOTOR_DER, medio);
  analogWrite(MOTOR_IZQ, fuerte);
}

////////////////////// 1 1 1 1 1 1  ////////////////////
////////////////////// INTERSECCIÓN DETECTADA //////////////////
else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == HIGH && sensor4 == HIGH && sensor5 == HIGH && sensor6 == HIGH) {
  analogWrite(MOTOR_DER, 0);
  analogWrite(MOTOR_IZQ, 0);
  // Opcional: pausa, giro, decisión especial
}

////////////////////// OTROS CASOS - girar buscando ////////////////////
else {
  analogWrite(MOTOR_DER, 100); 
  analogWrite(MOTOR_IZQ, 0);
}

}
#endif
