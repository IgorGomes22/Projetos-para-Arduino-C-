int buttonPin = 2;   
int ledPin =  8;    
unsigned long tempo = 0;     // variável para receber valores do millis()
int temporizador = 0;        // variável para indicar quando o temporizador está operando
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);    
  pinMode(buttonPin, INPUT);   
}

void loop(){
  buttonState = digitalRead(buttonPin);               // lê o estado do botão
  if (buttonState == HIGH && temporizador == 0)       // se botão acionado
   { temporizador = 1;                                // inicia o temporizador
     tempo = millis();                                // passa à variável o valor de millis()
}  
  if (millis() - tempo >= 1000 && temporizador == 1)  // após 1 segundo e temporizador                                                                               // ligado
   {  digitalWrite(ledPin, HIGH);                     // aciona o LED
   }
  if (millis() - tempo >= 5000 && temporizador == 1)  // após 5 seg. e temporizador 
   {  digitalWrite(ledPin, LOW);                      // apaga o LED 
      temporizador = 0;                               // desliga o temporizador
}
 
}
