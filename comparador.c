#include <16F628A.h>            //Define o modelo do microcontrolador
 
// Fusíveis de configuração do microcontrolador
 
#FUSES NOWDT                    //Watch Dog Timer desabilitado
#fuses INTRC_IO//#FUSES HS                       //oscilador cristal
#FUSES PUT                      //Power Up Timer
#FUSES NOPROTECT                //sem proteção para leitura da eprom
#FUSES BROWNOUT                 //Resetar quando detectar brownout
#FUSES NOMCLR                   //Reset desabilitado
#FUSES NOLVP                    //prog. baixa voltagem desabilitado
#FUSES NOCPD                    //Sem travar o chip
 
#use delay(clock=4000000)      //Define o cristal utilizado
 
 
//Definição de entradas e saídas
//Cada bit representa um pino físico de I/O
// 0 significa que o pino será uma saída
// 1 significa que o pino será uma entrada
#define trisa 0b1111111
#define trisb 0b00000000
 

 
/*
Usando os dois Comparadores:
pinos a0 e a3 são as enrradas de comp1, a variavel c1out contem o valor de saida
pinos a1 e a2 são as enrradas de comp2, a variavel c2out contem o valor de saida


void main(){
 setup_comparator(A0_A3_A1_A2);
while(true){
         if(C1OUT || C2OUT ){
          output_high(pin_b0);
         }else{
          output_low(pin_b0);
         }  
        }
}
*/


/*
Usando somente o comparador 2:
entradas a1 e a2 saida = C2OUT

void main(){
 setup_comparator(NC_NC_A1_A2);
while(true){
         if(C2OUT){
          output_high(pin_b0);
         }else{
          output_low(pin_b0);
         }  
        }
}
*/



/*

A0_A2_A1_A2_OUT_ON_A3_A4
descricao:
Entrada1Comp1_Entrada2Comp1_Entrada1Comp2_Entrada2Comp2_OUT_ON_SaidaComp1_SaidaComp2
estão definidas no header as possiveis configurações, há pinos multiplexados.
a tensão de referencia pode ser programada internamente

*/


#byte MCU_CMCON = 0x01F //acesso ao registrador


void main(){
 //setup_comparator(A0_A3_A1_A2);

MCU_CMCON = 0b0000100; //escrevendo diretamente no registrador, o valor 4 do datasheet


while(true){
         if(C1OUT){
          output_high(pin_b0);
         }else{
          output_low(pin_b0);
         }  
        }
}
