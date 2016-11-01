#include <Servo.h> // lamar a la libreria del servomotor

Servo myservo;  // crear el objeto servo para controlar al servomotor
int val=90;    // variable que almacenara los grados de movimiento del servomotor
int led = 3;
int led_verde = 4; //Un polo del motor
int led_rojo = 5;  //Otro polo
int motorPin = 6;  // Regulacion de velocidad

void setup()
{ 
  pinMode(led, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(motorPin, OUTPUT);
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_rojo, HIGH);
  myservo.attach(9);  // atribuye el pin 9 al servomotor para transferir los datos
  Serial.begin(9600); // iniciar comunicacion serial
} 

void loop()
{ 
  if (Serial.available() > 0) { //lee si el monitor serial recibe datos, si es asi entra al ciclo if
    int inByte = Serial.read(); //asigna el contenido del monitor serial a la variable.

    switch (inByte) {  //ciclos switch para determinar el valor que obtendra la variable val, segun sea el contenido de la variable inByte
      case 48:  //el contenido delmonitor seral es recibido como codigo ASCII, donde cero  es igual a 48 en codigo ASCII
        break;  //salir del ciclo
      case '1': //la compracion tambien se puede hacer usando el caracter encerrado entre comillas simples 
        digitalWrite(led, HIGH); //si el caso es 1 la variable val tendra el valor de 20
        break;  //salir del ciclo
      case '2': //...
        digitalWrite(led, LOW);
        break;
      case '3':
        val=140;
        break;
      case '4':
        val=110;
        break;
      case '5':
        val=90;
        break;
      case '6':
        val=70;
        break;
      case '7':
        val=40;
        break;
      case '8':
        analogWrite(motorPin, 255);
        break;
      case '9':
        analogWrite(motorPin, 180);
        break;
        case 'a':
        analogWrite(motorPin, 135);
        break;
        case 'b':
        analogWrite(motorPin, 100);
        break;
        case 'c':
        analogWrite(motorPin, 0);
        break;
        case 'd': //Reversa
        digitalWrite(led_verde, LOW);
        digitalWrite(led_rojo, HIGH);
        break;
        case 'e': //Directa
        digitalWrite(led_rojo, LOW);
        digitalWrite(led_verde, HIGH);
        break;
        case 'f': //Directa
        digitalWrite(led_rojo, HIGH);
        digitalWrite(led_verde, HIGH);
        break;
      default:  // en el caso de que no se haya introducido algun valor entre 0 y 9 se imprimira un mensaje en el monitor serial
        Serial.println("Introduce un valor entre 0-9 !!!");
    }
   myservo.write(val); 
   delay(30);           // espera a que el servo llegue a la posicion indicada antes de recibir otra orden
   }
}

