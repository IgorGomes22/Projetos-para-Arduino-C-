#include <LiquidCrystal.h>
int entrada = 3;
unsigned long valor;
unsigned long oldMillisLedAsa = 0;
unsigned long oldMillisLedCauda = 0;
int countLedAsa = 0;
int countLedCauda = 0;
 
void setup() {
  pinMode(8, OUTPUT); //LED 1 asa esquerda
  pinMode(7, OUTPUT); //LED 2 asa esquerda
  pinMode(6, OUTPUT); //LED cauda
  pinMode(5, OUTPUT); //LED barriga
  pinMode(4, OUTPUT); //LED PONTA DE ASA
  pinMode(2, OUTPUT);
  pinMode(entrada, INPUT_PULLUP);
}
 
void loop() {
  valor = pulseIn (entrada, HIGH);
 Serial.print("valor do sinal: ");
Serial.print(valor);
Serial.println("us");
  if ((valor >= 1800)&&(valor <=1920)) { 
    digitalWrite(4, HIGH);
    LedAsa(); 
    LedCauda();
  }  else {
    digitalWrite(2, LOW);
    digitalWrite(4,LOW);
    digitalWrite(5, LOW);
    digitalWrite(6,LOW);
    digitalWrite(7, LOW);
    digitalWrite(8,LOW);

  }
}
 
void LedAsa() {
  int qtdLoop = 4;      //Numero de piscadas
  int delayBlink = 150; //Valor do delay entre as piscadas
  unsigned long millisAsa = millis();
  if (millisAsa - oldMillisLedAsa >= delayBlink) {
    oldMillisLedAsa = millisAsa;
    if (countLedAsa < qtdLoop * 2) {
      digitalWrite(7, !digitalRead(7));
      digitalWrite(8, !digitalRead(8));
    }
    if (countLedAsa == (qtdLoop * 2) + 2) {
      countLedAsa = 0;
    } else {
      countLedAsa++;
    }
  }
}
 

void LedCauda() {
  int qtdLoop = 1;      //Numero de piscadas
  int delayBlink = 100; //Vaor do delay entre as piscadas
  unsigned long millisCausa = millis();
  if (millisCausa - oldMillisLedCauda >= delayBlink) {
    oldMillisLedCauda = millisCausa;
    if (countLedCauda < qtdLoop * 2) {
      digitalWrite(5, !digitalRead(5));
      digitalWrite(6, !digitalRead(6));
    }
    if (countLedCauda == (qtdLoop * 2) + 6) {
      countLedCauda = 0;
    } else {
      countLedCauda++;
    }
  }
}
