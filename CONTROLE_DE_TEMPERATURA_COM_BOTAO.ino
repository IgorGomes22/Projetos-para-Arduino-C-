/* CODIGO FEITO POR :IGOR GOMES PEREIRA,TECNICO EM AUTOMACAO INDUSTRIAL   TEL:(31)97353-9925     INSTAGRAM:IG_AUTOMACAO   FACEBOOK:IG AUTOMACAO
   
 CONTROLE DE TEMPERATURA,
 2 BOTOES (INCREMENTO E DECREMENTO),
 UM SENSOR DE TEMPERATURA NTC ,
 UM DISPLAY LCD 16X2.
            
   ESTE SKETCH FOI ELABORADO PARA DEFINIRMOS UMA TEMPERATURA MAX,PARA LIGAR UMA SAIDA DIGITAL ASSIM QUE A TEMPERATURA MAX FOR ATINGIDA,
   E O MELHOR DISSO TUDO,QUE PODEMOS DEFINIR O SETPOINT DA TEMPERATURA MAXIMA ATRAVES DE DOIS BOTOES,UM INCREMENTA O VALOR DA TEMPERATURA E O OUTRO DECREMENTA                               */
//____________________________________________________________________________________________________________________________________________________________________________________________

#include <LiquidCrystal.h>               //INCLUI BIBLIOTECA DO LCD 16X2
LiquidCrystal lcd(12,11,5,4,3,2);        //DEFINE OS PINOS DO ARDUINO PARA LIGACAO DO LCD
#include <Thermistor.h>                  //INCLUI A BIBLIOTECA DO SENSOR DE TEMPERATURA

int posicao = 0;
int temp_max = 26;                       //QUANDO O ARDUINO FOR LIGADO A TEMPERATURA MAXIMA COMEÇARÁ COM 26 GRAUS,(PODE SER EDITADO A SEU CRITERIO DEPENDENDO DA SUA REGIAO)

#define pino_aumenta 8                   //BOTAO INCREMENTA NO PINO 8 DO ARDUINO
#define pino_diminui 9                   //BOTAO DECREMENTA NO PINO 9 DO ARDUINO
#define pino_rele 7                      //SAIDA DIGITAL QUE SERA LIGADA APOS A TEMPERATURA MAXIMA FOR ATINGIDA
Thermistor temp(2);                      //VARIAVEL DA TEMPERATURA CALCULADA PELA BIBLIOTECA, PINO A2 DO ARDUINO

int temperatura;                         //VARIAVEL INTEIRA DA TEMPERATURA
int aumenta, diminui;                    //VARIAVEL INTEIRA PARA OS BOTOES

unsigned long previousMillis = 0;        //FUNCAO MILLIS
const long interval = 1000;              //Intervalo de medicao temperatura,ATUALIZA A CADA 1 SEGUNDO NO DISPLAY,(PODE SER EDITADA)


void setup(void)
{ lcd.begin(16,2);                       //DEFINE LCD 16 COLUNAS 2 LINHAS
  Serial.begin(9600);
  pinMode(pino_rele, OUTPUT);            //DEFINE O RELE COMO SAIDA DIGITAL
  pinMode(pino_aumenta, INPUT);          //DEFINE O BOTAO COMO ENTRADA DIGITAL
  pinMode(pino_diminui, INPUT);          //DEFINE O BOTAO COMO ENTRADA DIGITAL
}

void loop(void)
{
  int temperatura = temp.getTemp();     //variavel inteira recebe o valor de temperatura calculado pela biblioteca
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temp: ");
lcd.setCursor(5,0);
lcd.print(temperatura);
lcd.setCursor(7,0);
lcd.write(B11011111);
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Temp MAX: ");
lcd.setCursor(10,1);
lcd.print(temp_max);
lcd.setCursor(12,1);
lcd.write(B11011111);
lcd.print("C");
  unsigned long currentMillis = millis();
  //Timer para ler o valor da temperatura
  if (currentMillis - previousMillis >= interval)
  {
    temperatura = temp.getTemp(); 
    previousMillis = currentMillis;
  }

  aumenta = digitalRead(pino_aumenta);
  if (aumenta == 1)
  {temp_max++;}
  
  while (digitalRead(pino_aumenta) == 1)
  {delay(10);}
  
  diminui = digitalRead(pino_diminui);
  if (diminui == 1)
  {temp_max--;}
  
  while (digitalRead(pino_diminui) == 1)
  {delay(10);}
  if (temp_max <= temperatura)
   { digitalWrite(pino_rele,HIGH);
   }
   else
   { digitalWrite(pino_rele,LOW);
   }
  delay(200);
}
  
