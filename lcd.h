

void envia_nibble_lcd(int dado)
{
//Carrega as vias de dados (pinos) do LCD de acordo com o nibble lido
output_bit(lcd_db4, bit_test(dado,0));    //Carrega DB4 do LCD com o bit DADO<0>
output_bit(lcd_db5, bit_test(dado,1));    //Carrega DB5 do LCD com o bit DADO<1>
output_bit(lcd_db6, bit_test(dado,2));    //Carrega DB6 do LCD com o bit DADO<2>
output_bit(lcd_db7, bit_test(dado,3));    //Carrega DB7 do LCD com o bit DADO<3>

output_high(lcd_enable);
delay_us(1);
output_low(lcd_enable);
return;
}
 

void envia_byte_lcd(boolean endereco, int dado)
{
output_bit(lcd_rs,endereco);  
delay_us(100);             
output_low(lcd_enable);
envia_nibble_lcd(dado>>4);
envia_nibble_lcd(dado & 0x0f);

delay_us(40);
return;
}
 
 

void escreve_lcd(char c)
{
envia_byte_lcd(1,c);
}

void limpa_lcd()
{
envia_byte_lcd(0,0x01);          
delay_ms(2);
return;
}
 

void inicializa_lcd()
{
output_low(lcd_db4);
output_low(lcd_db5);
output_low(lcd_db6);
output_low(lcd_db7);
output_low(lcd_rs);
output_low(lcd_enable);
delay_ms(15);
envia_nibble_lcd(0x03);
delay_ms(5);
envia_nibble_lcd(0x03);
delay_ms(5);
envia_nibble_lcd(0x03);
delay_ms(5);
envia_nibble_lcd(0x02);


delay_ms(1);
envia_byte_lcd(0,0x28);
envia_byte_lcd(0,0x0c);
limpa_lcd();
envia_byte_lcd(0,0x06);
return;
}


void caracter_inicio(int linha, int col)
{
int16 posicao=0;
   if(linha == 1)
   {
      posicao=0x80;
   }
   if(linha == 2)
   {
      posicao=0xc0;
   }
 
posicao=posicao+col;
posicao--;
 
envia_byte_lcd(0,posicao);
return;
}

