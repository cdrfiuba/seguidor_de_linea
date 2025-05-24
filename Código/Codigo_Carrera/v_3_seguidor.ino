#define MOTOR_IZQ 8
#define MOTOR_DER 9
#define SENSOR_1 1
#define SENSOR_2 2
#define SENSOR_3 3
#define SENSOR_4 4
#define SENSOR_5 5
#define SENSOR_6 6
#define MOTOR_DER_0  8// asignar
# define MOTOR_IZQ_0 8 /// asignar
int sensorPins[6] = {SENSOR_1, SENSOR_2, SENSOR_3, SENSOR_4, SENSOR_5, SENSOR_6};
int pesos[6]      = {-5, -3, -1, 1, 3, 5};// pesos asignados a cada sensor, se los puede cambiar 

void setup() {
  Serial.begin(9600);  
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
}

void loop() {
  int lectura[6];
  int sumaPesada = 0; // defino la suma d
  int sumaLecturas = 0;

  // Leer sensores y calcular suma pesada
  for (int i = 0; i < 6; i++) {
    lectura[i] = digitalRead(sensorPins[i]);
    sumaPesada += lectura[i] * pesos[i]; // la suma con sus pesos 
    sumaLecturas += lectura[i]; // cuantos sensores estan prendidos
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

  int baseSpeed = 200; // defino una velocidad para arrancar(se la puede variar)
  int correction = error * 10;  // Ganancia proporcional

  int speedLeft = baseSpeed + correction;
  int speedRight = baseSpeed - correction;

  // Limito las velocidades, averiguar bien como hace para recortar
  speedLeft = constrain(speedLeft, 0, 255);
  speedRight = constrain(speedRight, 0, 255);

  Serial.print(" | L: ");
  Serial.print(speedLeft);
  Serial.print(" R: ");
  Serial.println(speedRight);

 
  analogWrite(MOTOR_IZQ, speedLeft);
  analogWrite(MOTOR_DER, speedRight);

  delay(50);
}
