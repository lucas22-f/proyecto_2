// C++ code
//constitucion
#define constitucion 13
//san juan
#define sanJuan 12
//independencia
#define independencia 11
//moreno
#define moreno 4
//display 7 segmentos
//display A 
#define A 5
//display B 
#define B 3
//display C
#define C 8
//display D 
#define D 9
//display E 
#define E 10
//display F 
#define F 6
//display G 
#define G 7

#define BOTON 2

void LevantarEstaciones(int tiempoEstacion);
void Apagar7Segmentos();
void prenderNumero(int numero);
void prenderBuzzer();
void prenderLedEstacion(int ledEstacion, int tiempo);
void EncenderConDisplay7Segmentos(int ledEstacion,int tiempo);

void setup()
{
	pinMode(constitucion,OUTPUT);
    pinMode(sanJuan,OUTPUT);
    pinMode(independencia,OUTPUT);
    pinMode(moreno,OUTPUT);
  	pinMode(A,OUTPUT);
  	pinMode(B,OUTPUT);
  	pinMode(C,OUTPUT);
  	pinMode(D,OUTPUT);
  	pinMode(E,OUTPUT);
  	pinMode(F,OUTPUT);
  	pinMode(G,OUTPUT);
  	pinMode(A0,OUTPUT);
  	pinMode(BOTON,INPUT);
  	Serial.begin(9600);
}
void loop()
{
 
  int boton = digitalRead(BOTON);
  Serial.println(boton);
  if(boton == HIGH){
    LevantarEstaciones(2000);
  }
  

 
}
void LevantarEstaciones(int tiempoEstacion){
 EncenderConDisplay7Segmentos(constitucion,tiempoEstacion);
 EncenderConDisplay7Segmentos(sanJuan,tiempoEstacion);
 EncenderConDisplay7Segmentos(independencia,tiempoEstacion);
 EncenderConDisplay7Segmentos(moreno,tiempoEstacion);

}
void Apagar7Segmentos(){
	digitalWrite(A,LOW);
    digitalWrite(B,LOW);
  	digitalWrite(C,LOW);
  	digitalWrite(D,LOW);
  	digitalWrite(E,LOW);
    digitalWrite(F,LOW);
 	digitalWrite(G,LOW);
}
void prenderNumero(int numero){
  switch(numero){
  	case 1:digitalWrite(B,HIGH);
           digitalWrite(C,HIGH);
    		break;
    case 2:digitalWrite(A,HIGH);
           digitalWrite(B,HIGH);
    	   digitalWrite(G,HIGH);
           digitalWrite(E,HIGH);
           digitalWrite(D,HIGH);
    		break;
    case 3:digitalWrite(A,HIGH);
           digitalWrite(B,HIGH);
    	   digitalWrite(G,HIGH);
           digitalWrite(C,HIGH);
           digitalWrite(D,HIGH);
    		break;
    case 4:digitalWrite(B,HIGH);
           digitalWrite(C,HIGH);
    	   digitalWrite(F,HIGH);
           digitalWrite(G,HIGH);
    		break;
  }
}
void prenderBuzzer(){
	tone(A0,150);
    delay(160);
    noTone(A0);
}
void prenderLedEstacion(int ledEstacion, int tiempo){
	digitalWrite(ledEstacion,HIGH);
    delay(tiempo);
    digitalWrite(ledEstacion,LOW);
}
void EncenderConDisplay7Segmentos(int ledEstacion,int tiempo){
   switch(ledEstacion){
  	case constitucion:
     	prenderBuzzer();
    	prenderNumero(1);
        prenderLedEstacion(ledEstacion,tiempo);
        Apagar7Segmentos();
     	break;
     case sanJuan:
     	prenderBuzzer();
     	prenderNumero(2);
        prenderLedEstacion(ledEstacion,tiempo);
     	Apagar7Segmentos();
     	break;
      case independencia:
     	prenderBuzzer();
     	prenderNumero(3);
        prenderLedEstacion(ledEstacion,tiempo);
     	Apagar7Segmentos();
     	break;
      case moreno:
     	prenderBuzzer();
     	prenderNumero(4);
        prenderLedEstacion(ledEstacion,tiempo);
        Apagar7Segmentos();
     	break;
  }
}
