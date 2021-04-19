//Declarando servos
#include <Servo.h> //Libreria para servomotores
Servo servo2; //Pulgar      ##movimientos verticales
Servo servo3; //Indice
Servo servo4; //Medio
Servo servo5; //Anular
Servo servo6; //Meñique
Servo servo7; //Muñeca
Servo servo8; //Pulgar MH   ##movimientos horizontales
Servo servo9; //Indice MH
Servo servo10; //Medio MH
Servo servo11; //Anular MH
Servo servo12; //Meñique MH
Servo servo13; //Muñeca MH

//Declarando los potenciometros y sus variables
int P_val; //Pulgar
int I_val; //Indice
int M_val; //Medio
int A_val; //Anular
int Q_val; //Meñique
int N_val; //Muñeca
int Px_val; //Pulgar H
int Ix_val; //Indice H
int Mx_val; //Medio H
int Ax_val; //Anular H
int Qx_val; //Meñique H
int Nx_val; //Muñeca H

/////////////////////////// Filtro ///////////////////////////
int Lecturas2[10]; //Vector de lecturas
int Lecturas3[10]; 
int Lecturas4[10];
int Lecturas5[10];
int Lecturas6[10]; 
int Lecturas7[10]; 
int Lecturas8[10]; 
int Lecturas9[10]; 
int Lecturas10[10]; 
int Lecturas11[10]; 
int Lecturas12[10]; 
int Lecturas13[10]; 
int p=0;
int i=0;
int m=0;
int a=0;
int q=0;
int n=0;
int px=0;
int ix=0;
int mx=0;
int ax=0;
int qx=0;
int nx=0;
int Total2 = 0;
int Total3 = 0;
int Total4 = 0;
int Total5 = 0;
int Total6 = 0;
int Total7 = 0;
int Total8 = 0;
int Total9 = 0;
int Total10 = 0;
int Total11 = 0;
int Total12 = 0;
int Total13 = 0;
int Promedio2 = 0;
int Promedio3 = 0;
int Promedio4 = 0;
int Promedio5 = 0;
int Promedio6 = 0;
int Promedio7 = 0;
int Promedio8 = 0;
int Promedio9 = 0;
int Promedio10 = 0;
int Promedio11 = 0;
int Promedio12 = 0;
int Promedio13 = 0;

//Declarando pulsadores y LEDs de comunicacion
const int btn_verde=26;
const int btn_rojo=27;
const int ledverde=22;
const int ledama=24;
const int ledrojo=23;
const int ledazul=25;

//Declarando variables de control
int btn_vread; //lectura de boton verde
int btn_rread; //lectura de boton rojo
bool lab_verde;
bool lab_rojo;
bool lab_azul;
bool lab_ama;
bool ant_val;
bool val_0;
bool val_25;

//Variable para lectura de puerto serial
char b;
String readString;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
// Direccion de servos
servo2.attach(2); //Pulgar
servo3.attach(3); //Indice
servo4.attach(4); //Medio
servo5.attach(5); //Anular
servo6.attach(6); //Meñique
servo7.attach(7); //Muñeca
servo8.attach(8); //Pulgar MH
servo9.attach(9); //Indice MH
servo10.attach(10); //Medio MH
servo11.attach(11); //Anular MH
servo12.attach(12); //Meñique MH
servo13.attach(13); //Giro MH
// Posicion inicial de servos
servo2.write(179); //Pulgar
servo3.write(179); //Indice
servo4.write(179); //Medio
servo5.write(1); //Anular
servo6.write(1); //Meñique
servo7.write(80); //Pulgar
servo8.write(60); //Indice
servo9.write(48); //Medio
servo10.write(75); //Anular
servo11.write(66); //Meñique
servo12.write(67); //Anular
servo13.write(110); //Muñeca
// Operaciones del filtro
for(p=0; p< 10; p++) 
Lecturas2[p] = 0;
p=0;
for(i=0; i<10; i++) 
Lecturas3[i] = 0;
i=0;
for(m=0; m< 10; m++)
Lecturas4[m] = 0;
m=0;
for(a=0; a< 10; a++) 
Lecturas5[a] = 0;
a=0;
for(q=0; q< 10; q++) 
Lecturas6[q] = 0;
q=0;
for(n=0; n< 10; n++) 
Lecturas7[n] = 0;
n=0;
for(px=0; px< 10; px++) 
Lecturas8[px] = 0;
px=0;
for(ix=0; ix<10; ix++) 
Lecturas9[ix] = 0;
ix=0;
for(mx=0; mx< 10; mx++)
Lecturas10[mx] = 0;
mx=0;
for(ax=0; ax< 10; ax++) 
Lecturas11[ax] = 0;
ax=0;
for(qx=0; qx< 10; qx++) 
Lecturas12[qx] = 0;
qx=0;
for(nx=0; nx< 10; nx++) 
Lecturas13[nx] = 0;
nx=0;

// Declarando entradas y salidas de botones e indicadores
pinMode(ledverde,OUTPUT);
pinMode(ledrojo,OUTPUT);
pinMode(ledazul,OUTPUT);
pinMode(ledama,OUTPUT);
pinMode(btn_verde,INPUT);
pinMode(btn_rojo,INPUT);
// Indicadores apagados
digitalWrite(ledverde,HIGH);
digitalWrite(ledrojo,HIGH);
digitalWrite(ledazul,HIGH);
digitalWrite(ledama,HIGH); 
// Variables para uso de botones
lab_verde = false;
lab_rojo = true;
lab_azul = false;
lab_ama = false;
ant_val = true;
val_25 = true;
val_0 = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  // Programa apagado
  while(lab_rojo==true&&lab_verde==false){ //Mientras el boton de encendido físico
    digitalWrite(ledverde,HIGH);           //o el botón de LabVIEW no se presionen
    digitalWrite(ledrojo,LOW);
    digitalWrite(ledazul,HIGH);
    digitalWrite(ledama,HIGH);
    if(Serial.available()){ // Si el puerto serial esta en uso
    b = Serial.read();
      if(b=='a'){ // Si llega el caracter "a"
        delay(6);
        lab_verde=true; //Encendido Labview
        lab_rojo=false;
      }
    }
    btn_vread = digitalRead(btn_verde);
    btn_rread = digitalRead(btn_rojo);
    if(btn_vread==HIGH&&btn_rread==LOW){ //Si se preisona el botón encendido
      lab_verde=true; //Encendido Labview
      lab_rojo=false;
      Serial.println("encender");
    }
  }

  // Programa encendido
  while(lab_verde==true&&lab_rojo==false&&btn_rread==LOW){ //Mientras las variables de encendido sean TRUE
    digitalWrite(ledverde,LOW);
    digitalWrite(ledrojo,HIGH);
      while(lab_ama==false&&(lab_azul==true||ant_val==true)&&lab_rojo==false){ //Mientras la variable de lectura sean TRUE
        digitalWrite(ledazul,LOW);
        digitalWrite(ledama,HIGH);
        btn_vread = digitalRead(btn_verde);
        btn_rread = digitalRead(btn_rojo);
        if(Serial.available()){ //Si el puerto serial esta uso
          b = Serial.read();
          if(b=='d'){ //Si llega el caracter "d"
            lab_ama=true; //Modo control
            lab_azul=false;
            ant_val==false;
          }
          else if(b=='b'){ //Si llega el caracter "b"
            lab_rojo=true;//apagar
            lab_verde=false;
          }
          else if(b=='e'){ //Si llega el caracter "e"
            digitalWrite(ledverde,HIGH);
            digitalWrite(ledrojo,HIGH);
            digitalWrite(ledazul,HIGH);
            digitalWrite(ledama,HIGH);
            lab_rojo=false;
            lab_verde=false;
            lab_ama=false;
            lab_azul=false;
            ant_val==false;
          }
        }
        else{ //Sino se ejecuta el siguiente comando
          Exoesqueleto();
        }
        if(btn_rread==HIGH&&btn_vread==LOW){ //Si se presiona el botón de apagado
          lab_verde=false;
          lab_rojo=true;
        }
      }
    while(lab_ama==true&&lab_azul==false&&lab_rojo==false){ //Mientras las variables de control sean TRUE
      digitalWrite(ledazul,HIGH);
      digitalWrite(ledama,LOW);
      btn_vread = digitalRead(btn_verde);
      btn_rread = digitalRead(btn_rojo);
      if(Serial.available()){ //Si el puerto serial esta en uso
        b = Serial.read();
        if(b=='c'){ //Si se recibe el caracter "c"
          delay(6);
          lab_ama=false; //Lectura exoesqueleto Labview
          lab_azul=true;
        }
        else if(b=='b'){ //Si se recibe el caracter "b"
          delay(6);
          lab_rojo=true; //Apagar labview
          lab_verde=false;
        }
        else if(b=='e'){ //Si se recibe el caracter "e"
          delay(6);
          digitalWrite(ledverde,HIGH);
          digitalWrite(ledrojo,HIGH);
          digitalWrite(ledazul,HIGH);
          digitalWrite(ledama,HIGH);
          lab_rojo=false;
          lab_verde=false;
          lab_ama=false;
          lab_azul=false;
          ant_val==false;
        }
          
        //Pulgar
        else if(b=='A'){ //Si se recibe el caracter "A", se controla el pulgar vertical
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo2.write(readString.toInt()); 
            readString=""; //Limpiar string
          }
        }
        
        //Indice
        else if(b=='B'){ //Si se recibe el caracter "B", se controla el índice vertical
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo3.write(readString.toInt()); 
            readString=""; //Limpiar string
          } 
        }
        
        //Medio
        else if(b=='M'){ //Si se recibe el caracter "M", se controla el medio vertical
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo4.write(readString.toInt()); 
            readString=""; //Limpiar string
          } 
        }
        
        //Anular
        else if(b=='D'){ //Si se recibe el caracter "D", se controla el anular vertical
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo5.write(readString.toInt()); 
            readString=""; //Limpiar string
          }
        }
        
        //Meñique
        else if(b=='E'){ //Si se recibe el caracter "E", se controla el meñique vertical
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo6.write(readString.toInt()); 
            readString=""; //Limpiar string
          }
        }
        
        //Muñeca
        else if(b=='F'){ //Si se recibe el caracter "F", se controla el muñeca vertical
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo7.write(readString.toInt()); 
            readString=""; //Limpiar string
          }
        }
        
        //Pulgar MH
        else if(b=='G'){ //Si se recibe el caracter "G", se controla el pelgar horizontal
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo8.write(readString.toInt()); 
            readString=""; //Clear string
          }
        }
        
        //Indice MH
        else if(b=='H'){ //Si se recibe el caracter "H", se controla el índice horizontal
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo9.write(readString.toInt()); 
            readString=""; //Limpiar string
          }
        }
    
        //Medio MH
        else if(b=='I'){ //Si se recibe el caracter "I", se controla el medio horizontal
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){
            servo10.write(readString.toInt()); 
            readString=""; //Limpiar string
          } 
        }
        
        //Anular MH
        else if(b=='J'){ //Si se recibe el caracter "J", se controla el anular horizontal
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo11.write(readString.toInt()); 
            readString=""; //Clear string
          }
        }
        
        //Meñique MH
        else if(b=='K'){ //Si se recibe el caracter "K", se controla el meñique horizontal
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){ 
            servo12.write(readString.toInt()); 
            readString=""; //Limpiar string
          }
        }
        
        //Muñeca MH
        else if(b=='L'){ //Si se recibe el caracter "L", se controla la muñeca horizontal
          delay(6);
          while (Serial.available()){
            char c = Serial.read();
            readString += c;
          }
          if(readString.length() >0){
            servo13.write(readString.toInt()); 
            readString=""; //Limpiar string
          }
        }
      }
      if(btn_rread==HIGH&&btn_vread==LOW){ //Si se presiona el botón de apagado
        lab_verde=false;
        lab_rojo=true;
      }
    }
  }
}

//Comando para lectura de potenciometros del exoesqueleto
void Exoesqueleto(){

// Lectura de potenciometros y escritura en servomotores
Total2 = Total2 - Lecturas2[p];
Total3 = Total3 - Lecturas3[i];
Total4 = Total4 - Lecturas4[m];
Total5 = Total5 - Lecturas5[a];
Total6 = Total6 - Lecturas6[q];
Total7 = Total7 - Lecturas7[n];
Total8 = Total8 - Lecturas8[px];
Total9 = Total9 - Lecturas9[ix];
Total10 = Total10 - Lecturas10[mx];
Total11 = Total11 - Lecturas11[ax];
Total12 = Total12 - Lecturas12[qx];
Total13 = Total13 - Lecturas13[nx];
//Agrega una lectura a la posición actual dentro del vector
Lecturas2[p] = analogRead(A11);
Lecturas3[i] = analogRead(A7);
Lecturas4[m] = analogRead(A8);
Lecturas5[a] = analogRead(A9);
Lecturas6[q] = analogRead(A10);
Lecturas7[n] = analogRead(A6);
Lecturas8[px] = analogRead(A5);
Lecturas9[ix] = analogRead(A1);
Lecturas10[mx] = analogRead(A2);
Lecturas11[ax] = analogRead(A3);
Lecturas12[qx] = analogRead(A4);
Lecturas13[nx] = analogRead(A0);
//Realiza la sumatoria entre lecturas
Total2 = Total2 + Lecturas2[p];
p = p + 1;
Total3 = Total3 + Lecturas3[i];
i = i + 1;
Total4 = Total4 + Lecturas4[m];
m = m + 1;
Total5 = Total5 + Lecturas5[a];
a = a + 1;
Total6 = Total6 + Lecturas6[q];
q = q + 1;
Total7 = Total7 + Lecturas7[n];
n = n + 1;
Total8 = Total8 + Lecturas8[px];
px = px + 1;
Total9 = Total9 + Lecturas9[ix];
ix = ix + 1;
Total10 = Total10 + Lecturas10[mx];
mx = mx + 1;
Total11 = Total11 + Lecturas11[ax];
ax = ax + 1;
Total12 = Total12 + Lecturas12[qx];
qx = qx + 1;
Total13 = Total13 + Lecturas13[nx];
nx = nx + 1;

//Calcula el promedio y envía el resultado al servomotor
//Pulgar
if (p >= 10){
  p = 0;
  Promedio2 = Total2 / 10;
     Serial.print("#P1");
     Serial.print(",");
     Serial.print(Promedio2);
     Serial.print(",");
     P_val = map(Promedio2, 520, 560, 179, 1);
     Serial.println(P_val);
     servo2.write(P_val);
     }
      
//Indice
if (i >= 10){
  i = 0;
  Promedio3 = Total3 / 10;
     Serial.print("#P2");
     Serial.print(",");
     Serial.print(Promedio3);
     Serial.print(",");
     I_val = map(Promedio3, 400, 550,179, 40);
     Serial.println(I_val);
     servo3.write(I_val);
}

//Medio
if (m >= 10){
  m = 0;
  Promedio4 = Total4 / 10;
     Serial.print("#P3");
     Serial.print(",");
     Serial.print(Promedio4);
     Serial.print(",");
     M_val = map(Promedio4, 890, 760, 15, 179);
     Serial.println(M_val);
     servo4.write(M_val);
}

//Anular
if (a >= 10){
  a = 0;
  Promedio5 = Total5 / 10;
     Serial.print("#P4");
     Serial.print(",");
     Serial.print(Promedio5);
     Serial.print(",");
     A_val = map(Promedio5, 450 ,345, 179, 1);
     Serial.println(A_val);
     servo5.write(A_val);
     }

//Meñique
if (q >= 10){
  q = 0;
  Promedio6 = Total6 / 10;
     Serial.print("#P5");
     Serial.print(",");
     Serial.print(Promedio6);
     Serial.print(",");
     Q_val = map(Promedio6,  380,455, 1, 179);
     Serial.println(Q_val);
     servo6.write(Q_val);
     }

//Muñeca
if (n >= 10){
  n = 0;
  Promedio7 = Total7 / 10;
     Serial.print("#P6");
     Serial.print(",");
     Serial.print(Promedio7);
     Serial.print(",");
     N_val = map(Promedio7,  600,650, 1, 179);
     Serial.println(N_val);
     servo7.write(N_val);
     }

//Pulgar Horizontal
if (px >= 10){
  px = 0;
  Promedio8 = Total8 / 10;
     Serial.print("#P7");
     Serial.print(",");
     Serial.print(Promedio8);
     Serial.print(",");
     Px_val = map(Promedio8, 500, 620, 1, 125);
     Serial.println(Px_val);
     servo8.write(Px_val);
}

//Indice Horizontal
if (ix >= 10){
  ix = 0;
  Promedio9 = Total9 / 10;
     Serial.print("#P8");
     Serial.print(",");
     Serial.print(Promedio9);
     Serial.print(",");
     Ix_val = map(Promedio9, 515, 543, 60, 110);
     Serial.print(Ix_val);
     servo9.write(Ix_val);
   
}

//Medio Horizontal
if (mx >= 10){
  mx = 0;
  Promedio10 = Total10 / 10;
     Serial.print("#P9");
     Serial.print(",");
     Serial.print(Promedio10);
     Serial.print(",");
     Mx_val = map(Promedio10, 508, 538, 77, 152);
     Serial.print(Mx_val);
     servo10.write(Mx_val);
   
     }

//Anular Horizontal
if (ax >= 10){
  ax = 0;
  Promedio11 = Total11 / 10;
     Serial.print("#P10");
     Serial.print(",");
     Serial.print(Promedio11);
     Serial.print(",");
     Ax_val = map(Promedio11, 500,535 , 45, 90);    
     Serial.print(Ax_val);
     servo11.write(Ax_val);
 
     }

//Meñique Horizontal
     if (qx >= 10){
qx = 0;
Promedio12 = Total12 / 10;
     Serial.print("#P11");
     Serial.print(",");
     Serial.print(Promedio12);
     Serial.print(",");
     Qx_val = map(Promedio12, 500, 550, 20, 86);
     Serial.print(Qx_val);
     servo12.write(Qx_val);
  
     }

//Muñeca Horizontal
if (nx >= 10){
  nx = 0;
  Promedio13 = Total13 / 10;
     Serial.print("#P12");
     Serial.print(",");
     Serial.print(Promedio13);
     Serial.print(",");
     Nx_val = map(Promedio13, 590, 370, 1, 179);
     Serial.println(Nx_val);
     servo13.write(Nx_val);

   }
   delay(18);
}
