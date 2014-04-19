int motor1Pin1 = 22;   // Motor 1 atras
int motor1Pin2 = 23;   // Motor 1 adelante
int speedpin1 = 2; // Motor 1 aceleracion (PWM) Pin enable del L293
int vel = 0;
int giro = 0;
int Derecha = 52;   // Motor 2 Derecha
int Izquierda = 53;   // Motor 2 Izquierda
int buzer = 49;
void setup() 
{   
Serial.begin (115200);
//configuracion de pines
// Control Motor 1
pinMode(buzer,OUTPUT);
pinMode(motor1Pin1, OUTPUT); 
pinMode(motor1Pin2, OUTPUT);
pinMode(Derecha, OUTPUT);
pinMode(Izquierda, OUTPUT);
// Establece speedPinX en modo High para poder controlar la velocidad
digitalWrite(speedpin1, HIGH);
// comprobacion de reseteo, si el led parpadea solo 3 veces, todo esta bien
// si vuelve a parpadear, significa que ha hecho un reset, revisar conexiones
// por si hubiera un corto
}

void loop()
{
     int c = Serial.read();
     int q = analogRead(15);
     int w = analogRead(14);
    
            digitalWrite(buzer,LOW);
            if (c=='a')
              {                       
                vel = 575;
                giro = 'a';
               }
            else if (c=='b')
               {
                vel = 615;
                giro = 'a';
               }
            else if (c=='c')
               {
                vel = 750;
                giro = 'a';
               }
               
            else if (c=='r')            //g cambia el giro del motor con una velocidad media
               {

                vel = 450;
                giro = 'g';
               }
               
            else if (c=='d')            //g cambia el direccion de carro Derecha
               {
                vel = 251;
                giro = 'd';
               }
            else if (c=='i')            //g cambia el direccion de carro Izquierda
               {
                vel = 250;
                giro = 'i';
               }
             else if (c=='z')
               {
               vel = 0;
               giro = 'z';
               
               }
if ( giro == 'g')
   {
    digitalWrite(motor1Pin1, LOW);      // Establece el sentido de giro del motor 1
    digitalWrite(motor1Pin2, HIGH);     // 
    analogWrite (speedpin1, vel);       //
    Serial.print("motor atras = ");         //
    Serial.println(vel);                //
    delay (50);                         //
                                        //
   }  
   else if(giro =='a')
      {
       digitalWrite(motor1Pin1, HIGH);     // Establece el sentido de giro del motor 1
       digitalWrite(motor1Pin2, LOW);      // 
       analogWrite (speedpin1, vel);  //
       Serial.print("motor adelante = ");         //
       Serial.println(vel);           //
       delay (50);    
      }
   if ( giro == 'd')
   {
    digitalWrite(Derecha, LOW);      // Establece el sentido de giro del motor 1
    digitalWrite(Izquierda, HIGH); 
    analogWrite (speedpin1, vel);       //
    Serial.print("motor 2 = ");         //
    Serial.println(vel);                //
    delay (50);                         //
                                        //
   }  
   else if( giro == 'i')
      {
       digitalWrite(Derecha, HIGH);     // Establece el sentido de giro del motor 1
       digitalWrite(Izquierda, LOW);      // 
       analogWrite (speedpin1, vel);  //
       Serial.print("motor 2 = ");         //
       Serial.println(vel);           //
       delay (50);    
      }
   if (giro == 'z')
      {
       digitalWrite(Derecha, LOW);     // Establece el sentido de giro del motor 1
       digitalWrite(Izquierda, LOW);
       digitalWrite(motor1Pin1, LOW);     // Establece el sentido de giro del motor 1
       digitalWrite(motor1Pin2, LOW);
       Serial.print("motor stop = ");  
       Serial.println(vel);
       Serial.print("motor 2 = ");
       Serial.println(vel);  
       delay (50);       
      }
      if ( q > 0)
      {
        digitalWrite(buzer,HIGH);
        
      }
      if ( w > 0)
      {
        digitalWrite(buzer,HIGH);
     
      }
}
