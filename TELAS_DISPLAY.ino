/* ===========================================================================================================================================================================================
                     IG AUTOMAÇÃO
                 DESENVOLVENDO SOLUÇÕES

 *AUTOR:    IGOR GOMES PEREIRA   /TECNICO EM AUTOMACAO INDUSTRIAL  
 *
 *DATA:9 DE ABRIL DE 2020
 *TELEFONE:(31)97353-9925
 *
 *
 *facebook:      https://www.facebook.com/G6automacao/
 *
 *instagram:     https://www.instagram.com/ig_automacao/?hl=pt-br
 *
 *  DESCRICAO: NESTE CODIGO VOCE PODERA ALTERNAR AS TELAS DE UM DISPLAY 16X2 APERTANDO APENAS UM BOTAO,
 *  SAO SEPARADAS EM 6 TELAS USANDO A FUNCAO CASE(ESCOLHA),
 *  PODE SER INCREMENTADO MAIS TELAS OU DECREMENTAR A SUA ESCOLHA,APENAS ALTERANDO ALGUMS PARAMETROS DO CODIGO!
 *  
==============================================================================================================================================================================================
*/
#include <LiquidCrystal.h>           //BIBLIOTECA DO DISPLAY 16X2
 
LiquidCrystal lcd(9,8,7,6,5,4);      //PINOS 4 A 9 LIGAR DISPLAY 16X2
 
int WhichScreen =1;                  //representa o numero da tela (1)
boolean hasChanged = true;           //VARIVEL TIPO BOOLEANA (TRUE=1 , FALSE=0)
const int BotaoEnter = 12;           //BOTAO PINO 12
int EstadoDoBotao;                   //LEITURA DO PINO DO BOTAO (ENTRADA)
int UltimoEstadoDoBotao = LOW;       //LEITURA ANTERIOR DA ENTRADA
unsigned long lastDebounceTime = 0;  //ULTIMA VEZ QUE OPINO FOI ALTERADO
unsigned long debounceDelay = 50;    //TEMPO DE DEBOUNCE milisegundos(PODE SER ALTERADO)
 
void setup()
{
  lcd.begin(16,2);
  pinMode(BotaoEnter, INPUT);        //BOTAO DE ENTRADA(IRA MUDAR AS TELAS)
}
void loop()
{
 
  if (hasChanged == true) {         //SE A VARIAVEL É IGUAL A 1,EXECUTA AS FUNCOES DE ESCOLHA(CASE)
   
  switch(WhichScreen) {
    case 1:
    {
      primeiraTela();
    }
      break;
   
    case 2:
      {
        segundaTela();
      }
      break;
   
    case 3:
      {
        terceiraTela();
      }
      break;
   
    case 4:
      {
        quartaTela();
      }
      break;
   
    case 5:
      {
        quintaTela();
      }
      break;
   
    case 6:
      {
        sextaTela();
      }
      break;
    case 0:
      {
       
      }
      break;
    }
}
 
    //===============================================================================
    // inicio do codigo do botao
    
    int leitura = digitalRead(BotaoEnter);
  if (leitura != UltimoEstadoDoBotao) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 
if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (leitura != EstadoDoBotao) {      //SE O ESTADO DO BOTAO MUDOU
      EstadoDoBotao = leitura;
 
      if (EstadoDoBotao == HIGH) {    //SE O BOTAO É HIGH
        hasChanged = true;          //MUDOU PARA VERDADEIRO
        WhichScreen++;              //INCREMENTA A TELA +1
    
      }
    } else {                      
      hasChanged = false;           //SENAO,PERMANECE FALSO
    }
  }
     UltimoEstadoDoBotao = leitura;     //ULTIMO ESTADO DO BOTAO = LEITURA   
     // FIM CODIGO DO BOTAO
  //=================================================================================
  if (WhichScreen > 6){            //APOS A ULTIMA TELA(6) VOLTARÁ PARA A PRIMEIRA(1)
    WhichScreen = 1;
  }
}
 
void primeiraTela()
  {
   lcd.clear();
   lcd.setCursor(0,0);               // COLUNA E LINHA
   lcd.print("IG AUTOMACAO");
   lcd.setCursor(0,1);
   lcd.print("PRIMEIRA TELA");
  }
void segundaTela()
  {
    lcd.clear();
    lcd.setCursor(0,0);                 // COLUNA E LINHA
    lcd.print("IG AUTOMACAO");
    lcd.setCursor(0,1);
    lcd.print("SEGUNDA TELA");
  }
void terceiraTela()
  {
    lcd.clear();
    lcd.setCursor(0,0);                 //COLUNA E LINHA
    lcd.print("IG AUTOMACAO");
    lcd.setCursor(0,1);
    lcd.print("TERCEIRA TELA");
  }
void quartaTela()
  {
    lcd.clear();
    lcd.setCursor(0,0);                //COLUNA E LINHA
    lcd.print("IG AUTOMACAO");
    lcd.setCursor(0,1);
    lcd.print("QUARTA TELA");
  }
void quintaTela()
  {
    lcd.clear();
    lcd.setCursor(0,0);                 //COLUNA E LINHA
    lcd.print("IG AUTOMACAO");
    lcd.setCursor(0,1);
    lcd.print("QUINTA TELA");
  }
void sextaTela()
  {
    lcd.clear();
    lcd.setCursor(0,0);                //COLUNA E LINHA
    lcd.print("IG AUTOMACAO");
    lcd.setCursor(0,1);
    lcd.print("SEXTA TELA");
  } 
