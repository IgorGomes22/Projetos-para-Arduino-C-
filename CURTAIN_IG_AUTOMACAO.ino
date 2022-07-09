/* ===========================================================================================================================================================================================
                     IG AUTOMAÇÃO
                 DESENVOLVENDO SOLUÇÕES

 *AUTOR:    IGOR GOMES PEREIRA     DATA:29 DE FEVEREIRO DE 2020
 *TELEFONE:(31)97353-9925
 *
 *
 *facebook:      https://www.facebook.com/G6automacao/
 *
 *instagram:     https://www.instagram.com/ig_automacao/?hl=pt-br
 *
==============================================================================================================================================================================================
*/

#define abrir 8         //BOTAO DE ABRIR PINO 8
#define fechar 9        //BOTAO DE FECHAR PINO 9
#define fim1 10         //FIM DE CURSO 1 NO CANTO PARA ACIONAR QUANDO A CORTINA ESTIVER TODA ABERTA
#define fim2 11         //FIM DE CURSO 2 PARA QUANDO A CORTINA ESTIVER TODA FECHADA

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
  //define os pinos como entrada
pinMode(abrir,INPUT_PULLUP);
pinMode(fechar,INPUT_PULLUP);
pinMode(fim1,INPUT_PULLUP);
pinMode(fim2,INPUT_PULLUP);
 //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 //OUTPUTS DESLIGADOS
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,LOW);
}

void loop(){
  
  if ((digitalRead(abrir)==LOW) && (digitalRead(fim1)==HIGH))         //ABRIR=1 E FIM1=0 == ABRIR
   {       //Gira o Motor A no sentido horario
           digitalWrite(IN1, HIGH);
           digitalWrite(IN2, LOW);
           //Gira o Motor B no sentido horario
           digitalWrite(IN3, HIGH);
           digitalWrite(IN4, LOW);
      }
   if  ((digitalRead(fim1)==LOW) && (digitalRead(fechar)==HIGH))      //FIM1=1 E FECHAR=0 == PARADO
   {       //PARA O MOTOR A
           digitalWrite(IN1, HIGH);
           digitalWrite(IN2, HIGH);
           //PARA O MOTOR B
           digitalWrite(IN3, HIGH);
           digitalWrite(IN4, HIGH);
   }
 if ((digitalRead(fechar)==LOW) && (digitalRead(fim2)==HIGH))       //FECHAR==1 E FIM2=0 == FECHAR
  {
         //Gira o Motor A no sentido anti-horario
         digitalWrite(IN1, LOW);
         digitalWrite(IN2, HIGH);
         //Gira o Motor B no sentido anti-horario
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
}
 if ((digitalRead(fim2)==LOW) && (digitalRead(abrir)==HIGH))          //FIM2=1 E ABRIR=0 == PARADO
  {
         //PARA O MOTOR A
         digitalWrite(IN1, HIGH);
         digitalWrite(IN2, HIGH);
         //PARA O MOTOR B
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, HIGH);
 delay(100);
}
}            
