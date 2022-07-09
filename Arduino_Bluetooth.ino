/*Comandos:
 * Para Piscar a seta direita: F1 para desligar F0
 * Para ligar a seta Esquerda: E1, para desligar E0
 * 
 * Para ligar pisca alerta: P1 para desligar P0
 * 
 * Farol Alto: C1 desligar C0 
 * Farol Baixo: A1 desligar A0 
 * Farol de Neblina: G1 desligar G0
 * 
 */
 #include <SoftwareSerial.h>
 #define RX 7                           //cabo RX aopino 7
 #define TX 6                           //cabo TX ao pino 6
 
int Leds_direita[1] = {2};               //SETA DIREITA PINO 2

int Leds_esquerda[1] = {4};              //SETA ESQUERDA´PINO 4
  
int Leds_farolalto[1] = {9};             //FAROL ALTO PINO 9

int Leds_farolbaixo[1] = {10};           //FAROL BAIXO PINO 10

int Leds_farolneblina[1] = {11};         //FAROL NEBLINA PINO 11

bool Pisca=false;
bool alerta = false;                     //VARIAVEL BOOLEANA ALERTA=0
unsigned int estado, t=1000;             //VARIAVEL TEMPO MILLIS

void setup() {
    
    for (int ind=0; ind>=2; ind++){              //BRILHO DO LED
     pinMode(Leds_direita,OUTPUT);
     pinMode(Leds_esquerda,OUTPUT);
}
Serial.begin(9600);
}

void loop() {

if(alerta>0) PiscaAlerta();

if(Serial.available()){
  char n;                                     //VARIAVEL n
  n=Serial.read();

     
      if (n=='C') {                          //FAROL ALTO C1,C0 
        estado = Serial.parseInt();           
        FarolAlto(estado);
      }
      if (n=='A') {                          //FAROL BAIXO A1,A0
        estado = Serial.parseInt();
        FarolBaixo(estado);
      }
      if (n=='G') {                           //FAROL NEBLINA G1,G0
        estado = Serial.parseInt();
        FarolNeblina(estado);
      }
      if (n=='P') {                              //PISCA ALERTA P1,P0
        estado = Serial.parseInt();              
        if (estado==1) alerta = true;
        if (estado==0) alerta = false;
      }

         if (n=='F') {                              //O1,O0
           PiscaDireita();
            estado = Serial.parseInt();
         if (estado==1) alerta = true;
           if (estado==0) alerta = false;
      }
        if (n=='E') {                              //p1,p0
           PiscaEsquerda();  
           estado = Serial.parseInt();              
        if (estado==1) alerta = true;
        if (estado==0) alerta = false;                       
      }
     
      n=0;                                         //VARIAVEL n=0
        estado=0;                                  //estado LOW
        delay(3);                                  //ATRASO
}
   if(alerta>0) PiscaAlerta();  
    
}                                     ///////////////////////////////       


void SetaDireita(int estado) {                  
    if(estado == 1) {
    estado =HIGH;
  }
    else {
    estado =LOW;
  }
  for (int i=0; i<1; i++) {
    digitalWrite(Leds_direita[i], estado);
    
  }
  //////////////////////////////////////////
  
}

void SetaEsquerda(int estado) {
  if(estado == 1) {
    estado =HIGH;
  }
    else {
    estado =LOW;
  }
  for (int i=0; i<1; i++) {
    digitalWrite(Leds_esquerda[i], estado);
  }
}

void FarolAlto(int estado) {
  if(estado == 1) {
    for (int i=0; i<2; i++) {
    analogWrite(Leds_farolalto[i], 255/3);
  }
  }
  else {
  for (int i=0; i<2; i++) {
    digitalWrite(Leds_farolalto[i], LOW);
  }
  }
}

void FarolBaixo(int estado){
  if(estado == 1) {
    for (int i=0; i<2; i++) {
    analogWrite(Leds_farolbaixo[i], 255/3);
  }
  }
  else {
  for (int i=0; i<2; i++) {
    digitalWrite(Leds_farolbaixo[i], LOW);
  }
  }
}

void FarolNeblina(int estado){
  if(estado == 1) {
    for (int i=0; i<2; i++) {
    analogWrite(Leds_farolneblina[i], 255/3);
  }
  }
  else {
  for (int i=0; i<2; i++) {
    digitalWrite(Leds_farolneblina[i], LOW);
  }
  }
}

void PiscaDireita(){
  SetaDireita(HIGH);
  delay(t/2);
  SetaDireita(LOW);
  delay(t/2);
}

void PiscaEsquerda(){
  SetaEsquerda(HIGH);
  delay(t/2);
  SetaEsquerda(LOW);
  delay(t/2); 
}

void PiscaAlerta() {
  SetaEsquerda(HIGH);
  SetaDireita(HIGH);
  delay(t/2);
  SetaEsquerda(LOW);
  SetaDireita(LOW);
  delay(t/2);
}                  
