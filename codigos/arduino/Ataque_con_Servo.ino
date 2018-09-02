#include <Servo.h>
char nombre[10] = "Mazinger"; //El nuevo nombre del modulo
char password [10] = "1234"; //El nuevo password. No es muy seguro...
char baud = '4'; //4 = 9600 baud

int ang=0;//posicion inicial 
Servo servomotor;

void setup() {
  
  Serial.begin (9600);//inicial e serial 
  servomotor.attach(9,600,2400);//servo en el pin9 &AP(min)=600 AP(max)=2400
}

void loop(){
  
  if(Serial.available() >= 1){ //detecta una entrada
    char entrada = Serial.read(); //lee el caracter del celular 
    
    if (entrada == 'A'){
      ang=ang+5;//aumenta el angulo
      Serial.println(ang);
      }
    else if (entrada == 'S'){
      ang=ang-5;//disminuye el angulo
      Serial.println(ang);
      }
   ang=constrain(ang,0,180);//limitacion de los valores del angulo
      }
   servomotor.write(ang);//se ingresa el valor "ang" al servo
   delay(100);//por si las moscas   
  }
