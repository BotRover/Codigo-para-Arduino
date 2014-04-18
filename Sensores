#include <Ultrasonic.h>

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
Ultrasonic ultrasonic2(10,7);
int izquierda = 12;
int derecha = 11;
int led = 13;

void setup() 
{
  Serial.begin(9600); 
  pinMode(izquierda,OUTPUT);
  pinMode(derecha,  OUTPUT);
  pinMode(led,      OUTPUT);
}

void loop()
{  
  // read the input on analog pin 0:
  int ST1 = analogRead(A0);
  int ST2 = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float VST1=(5.0 * ST1 * 100.0)/1023.0 ;
  float VST2=(5.0 * ST2 * 100.0)/1023.0 ;
  // print out the value you read:
  Serial.print(VST1);
  Serial.print('\t');
  Serial.print(VST2);
  Serial.print('\t');
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.print('\t');
  Serial.println(ultrasonic2.Ranging(CM));
  delay(50); 
  
  if((VST1 >= 30.30) || ( VST2 >= 31.00))
  {
    /*Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.println("Caliente");*/
    digitalWrite(led,HIGH);
  }
  else
  {
//    Serial.print("");
    digitalWrite(led,LOW);
  }
  if(ultrasonic.Ranging(CM) <= 10)
  {
    /*Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.println("Izquierda");*/
    digitalWrite(izquierda,HIGH);
  }
  else
  {
//    Serial.print("");
    digitalWrite(izquierda,LOW);
  }
  if(ultrasonic2.Ranging(CM) <= 10)
  {
    /*Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.print('\t');
    Serial.println("Izquierda");*/
    digitalWrite(derecha,HIGH);
  }
  else
  {
//    Serial.print("");
    digitalWrite(derecha,LOW);
  }
}
