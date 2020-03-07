#include <16F628A.h>       

//#fuses INTRC_IO,put,nowdt,noprotect,nobrownout,NOLVP,NOCPD,nomclr
#FUSES NOWDT
#fuses INTRC_IO//#FUSES HS = oscilador cristal
#FUSES PUT
#FUSES NOPROTECT
#FUSES BROWNOUT
#FUSES NOMCLR
#FUSES NOLVP
#FUSES NOCPD
 
#use delay(clock=4000000)

#define trisa 0b11110111
#define trisb 0b00000000
#byte MCU_CMCON = 0x01F
#byte MCU_VRCON = 0x09F

#define lcd_enable pin_b3 
#define lcd_rs     pin_b2

#define lcd_db4    pin_b4 
#define lcd_db5    pin_b5
#define lcd_db6    pin_b6 
#define lcd_db7    pin_b7
#include <lcd.h>
 

long adc_calc(long resolution)
{
   long result = 0;                        
   MCU_CMCON   = 0x03; 

   while(resolution)                          
   {
       if(C1OUT) output_high(pin_a3); 
       else                                  
       {
         output_low(pin_a3); 
          result ++; 
       }
       resolution --;
   }
   MCU_CMCON = 0x06; 

   return(result);                            
}

void main(){
    setup_comparator(A0_A3_A1_A2);
    inicializa_lcd();
    caracter_inicio(2,4);
    printf(escreve_lcd,"Iniciando");
    delay_ms(1000);
    MCU_VRCON = 0xEC;
    while(true){
         long l = adc_calc(1024);
     limpa_lcd();
     printf(escreve_lcd,"%ld",l);
    }
     

}


