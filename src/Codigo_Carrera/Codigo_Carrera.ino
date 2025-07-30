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






//#include <Arduino.h> 

const int Motor_A_pwm = D8;   //Motor IZquierdo
const int Motor_A_Dig = D9;  // Motor Izquierdo
const int Motor_B_pwm = D10;  //Motor Derecho
const int Motor_B_Dig = D11; //Motor Derecho 

const int Sensor_1 = D2;   //Extremo izquierdo
const int Sensor_2 = D3;  //Medio izquierdo
const int Sensor_3 = D4;  //Centro Izquierda
const int Sensor_4 = D5;  //Centro Derecha 
const int Sensor_5 = D6;  //Medio Derecha 1 
const int Sensor_6 = D7;  //Extremo Derecho  2

const int pulsador = D13;

const int blanco = HIGH;
const int negro = LOW;

float multiplicador_der = 1; // multiplica la velocidad de la rueda derecha
float multiplicador_izq = 1; // multiplica la velocidad de la rueda iquierda
float paso_multiplicador = 0.05; // paso con el que se van variando los multiplicadores en cada iteración

int velocidad_max = 150; //puede variar entre 0 y 255


void setup() {
  pinMode(Motor_A_pwm, OUTPUT);
  pinMode(Motor_A_Dig, OUTPUT);
  pinMode(Motor_B_pwm, OUTPUT);
  pinMode(Motor_B_Dig, OUTPUT);
  
  pinMode(Sensor_1, INPUT);
  pinMode(Sensor_2, INPUT);
  pinMode(Sensor_3, INPUT);
  pinMode(Sensor_4, INPUT);
  pinMode(Sensor_5, INPUT);
  pinMode(Sensor_6, INPUT);

  pinMode(pulsador, INPUT);

  while(digitalRead(pulsador)); //Espera a que se accione el pulsador para comenzar a correr el código
}
 
void loop() {

  if(digitalRead(Sensor_1) == blanco) doblar_iquierda(2 * paso_multiplicador);
  if(digitalRead(Sensor_2) == blanco) doblar_iquierda(paso_multiplicador);
  if(digitalRead(Sensor_3) == blanco && digitalRead(Sensor_4) == blanco) centrar();
  if(digitalRead(Sensor_5) == blanco) doblar_derecha(paso_multiplicador);
  if(digitalRead(Sensor_6) == blanco) doblar_derecha(2 * paso_multiplicador);
  
  analogWrite(Motor_A_Dig, 0);
  analogWrite(Motor_A_pwm, velocidad_max * multiplicador_der);
  analogWrite(Motor_B_Dig, 0);
  analogWrite(Motor_B_pwm, velocidad_max * multiplicador_izq);

  //delay(50);
}



void centrar(){ //Reestablece los multiplicadores para que avance recto
  multiplicador_der = 1;
  multiplicador_izq = 1;
}

void doblar_iquierda(float val){ //recibe un valor entre 0 y 1 que modifica el multiplicador adecuado

  if(multiplicador_der + val < 1){
    multiplicador_der = multiplicador_der + val;
  }

  else if(multiplicador_der + val > 1 && multiplicador_der != 1){
    multiplicador_der = 1;
  }
  
  else if(multiplicador_der == 1 && multiplicador_izq - val > 0){
    multiplicador_izq = multiplicador_izq - val;
  }

  else if(multiplicador_der == 1 && multiplicador_izq - val < 0){
    multiplicador_izq = 0;
  }
}

void doblar_derecha(float val){ //recibe un valor entre 0 y 1 que modifica el multiplicador adecuado

  if(multiplicador_izq + val < 1){
    multiplicador_izq = multiplicador_izq + val;
  }

  else if(multiplicador_izq + val > 1 && multiplicador_izq != 1){
    multiplicador_izq = 1;
  }
  
  else if(multiplicador_izq == 1 && multiplicador_der - val > 0){
    multiplicador_der = multiplicador_der - val;
  }

  else if(multiplicador_izq == 1 && multiplicador_der - val < 0){
    multiplicador_der = 0;
  }
}
