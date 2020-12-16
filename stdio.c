#include "config.h"
#include "pic18f4520.h"
#include "delay.h"
#include "lcd.h"
#include "teclado.h"
#include "ssd.h"
#include "stdio.h"

char traduzMorse(char * palavra) {
    /*
     Essa função lê o vetor passado na main
     e compara com as condições até ser satisfeita .
     */
 
    if ((palavra[0] == '.')&& (palavra[1] == '-')&&(palavra[2] == 'V')&&(palavra[3] == 'V')) { // Identifica o código passado

        lcd_str("A"); // Exibe a letra traduzida no display
        Display();    //configura para a utilização do display
        PORTD = 0x77; // Exibe no display de 7 segmentos a letra traduzida
        atraso_ms(1000);
       returnConfig();     //Retorna a configuração dos PORTS

        return 'A';       // Retorna um char
    }
    if ((palavra[0] == '-')&& (palavra[1] == '.')&& (palavra[2] == '.')&& (palavra[3] == '.')) {

        lcd_str("B");
        Display();
        PORTD = 0x7C;
        atraso_ms(1000);
        returnConfig();

        return 'B';
    }
     if ((palavra[0] == '-')&& (palavra[1] == '.')&& (palavra[2] == '-')&& (palavra[3] == '.')) {

        lcd_str("C");

        Display();
        PORTD = 0x39;
        atraso_ms(1000);
        returnConfig();
        return 'C';

    }
    if ((palavra[0] == '-')&& (palavra[1] == '.')&& (palavra[2] == '.')&& (palavra[3] == 'V')) {

        lcd_str("D");

        Display();
        PORTD = 0x5E;
        atraso_ms(1000);
        returnConfig();
        return 'D';
    }
    if ((palavra[0] == '.')&&(palavra[1] == 'V')&&(palavra[2] == 'V')&&(palavra[3] == 'V')) {

        lcd_str("E");

        Display();
        PORTD = 0x79;
        atraso_ms(1000);
        returnConfig();
        return 'E';

    }
    if ((palavra[0] == '.')&& (palavra[1] == '.')&& (palavra[2] == '-')&& (palavra[3] == '.')) {

        lcd_str("F");

        Display();
        PORTD = 0x71;
        atraso_ms(1000);
        returnConfig();
        return 'F';
    }
     if ((palavra[0] == '-')&& (palavra[1] == '-')&& (palavra[2] == '.')&&(palavra[3] == 'V')) {

        lcd_str("G");

        Display();
        PORTD = 0x6F;
        atraso_ms(1000);
        returnConfig();
        return 'G';

    }
    if ((palavra[0] == '.')&& (palavra[1] == '.')&& (palavra[2] == '.')&& (palavra[3] == '.')) {

        lcd_str("H");

        Display();
        PORTD = 0x76;
        atraso_ms(1000);
        returnConfig();
        return 'H';
    }
     
    if ((palavra[0] == '.')&& (palavra[1] == '.')&&(palavra[2] == 'V')&&(palavra[3] == 'V')) {

        lcd_str("I");

        Display();
        PORTD = 0x30;
        atraso_ms(1000);
        returnConfig();
        return 'I';

    }
     
    if ((palavra[0] == '.')&& (palavra[1] == '-')&& (palavra[2] == '-')&& (palavra[3] == '-')) {

        lcd_str("J");

        Display();
        PORTD = 0x3C;
        atraso_ms(1000);
        returnConfig();
        return 'J';
        
    }
    if ((palavra[0] == '-')&& (palavra[1] == '.')&& (palavra[2] == '-')&&(palavra[3] == 'V')) {

        lcd_str("K");

        Display();
        PORTD = 0x7A;
        atraso_ms(1000);
        returnConfig();
        return 'K';

    }
     if ((palavra[0] == '.')&& (palavra[1] == '-')&& (palavra[2] == '.')&& (palavra[3] == '.')) {

        lcd_str("L");

        Display();
        PORTD = 0x38;
        atraso_ms(1000);
        returnConfig();
        return 'L';
    }
      if ((palavra[0] == '-')&& (palavra[1] == '-')&&(palavra[2] == 'V')&&(palavra[3] == 'V')) {

        lcd_str("M");

        Display();
        PORTD = 0x37;
        atraso_ms(1000);
        returnConfig();
        return 'M';
    }
    if ((palavra[0] == '-')&& (palavra[1] == '.')&&(palavra[2] == 'V')&&(palavra[3] == 'V')) {

        lcd_str("N");

        Display();
        PORTD = 0x54;
        atraso_ms(1000);
        returnConfig();
        return 'N';
    }
    if ((palavra[0] == '-')&& (palavra[1] == '-')&& (palavra[2] == '-') &&(palavra[3] == 'V')) {

        lcd_str("O");

        Display();
        PORTD = 0x3F;
        atraso_ms(1000);
        returnConfig();
        return 'O';
    }
      
    if ((palavra[0] == '.')&& (palavra[1] == '-')&& (palavra[2] == '-')&& (palavra[3] == '.')) {

        lcd_str("P");

        Display();
        PORTD = 0x73;
        atraso_ms(1000);
        returnConfig();
        return 'P';
    }
    if ((palavra[0] == '-')&& (palavra[1] == '-')&& (palavra[2] == '.')&& (palavra[3] == '-')) {

        lcd_str("Q");

        Display();
        PORTD = 0x67;
        atraso_ms(1000);
        returnConfig();
        return 'Q';
    }
    if ((palavra[0] == '.')&& (palavra[1] == '-')&& (palavra[2] == '.')&&(palavra[3] == 'V')) {

        lcd_str("R");

        Display();
        PORTD = 0x50;
        atraso_ms(1000);
        returnConfig();
        return 'R';
    }
    if ((palavra[0] == '.')&& (palavra[1] == '.')&& (palavra[2] == '.')&&(palavra[3] == 'V')) {

        lcd_str("S");

        Display();
        PORTD = 0x6D;
        atraso_ms(1000);
        returnConfig();
        return 'S';
    }
     if ((palavra[0] == '-')&&(palavra[1] == 'V')&&(palavra[2] == 'V')&&(palavra[3] == 'V')) {

        lcd_str("T");
        Display();
        PORTD = 0x78;
        atraso_ms(1000);
        returnConfig();
        return 'T';
    }
    if ((palavra[0] == '.')&& (palavra[1] == '.')&& (palavra[2] == '-') &&(palavra[3] == 'V')) {

        lcd_str("U");

        Display();
        PORTD = 0x3E;
        atraso_ms(1000);
        returnConfig();
        return 'U';
    }
    if ((palavra[0] == '.')&& (palavra[1] == '.')&& (palavra[2] == '.')&& (palavra[3] == '-')) {

        lcd_str("V");

        Display();
        PORTD = 0x1C;
        atraso_ms(1000);
        returnConfig();
        return 'V';
    }
    if ((palavra[0] == '.')&& (palavra[1] == '-')&& (palavra[2] == '-')&&(palavra[3] == 'V')) {

        lcd_str("W");

        Display();
        PORTD = 0x1D;
        atraso_ms(1000);
        returnConfig();
        return 'W';
    }
    
    
    if ((palavra[0] == '-')&& (palavra[1] == '.')&& (palavra[2] == '.')&& (palavra[3] == '-')) {

        lcd_str("X");

        Display();
        PORTD = 0x70;
        atraso_ms(1000);
        returnConfig();
        return 'X';
    }
    if ((palavra[0] == '-')&& (palavra[1] == '.')&& (palavra[2] == '-')&& (palavra[3] == '-')) {

        lcd_str("Y");

        Display();
        PORTD = 0x6E;
        atraso_ms(1000);
        returnConfig();
        return 'Y';
    }
     if ((palavra[0] == '-')&& (palavra[1] == '-')&& (palavra[2] == '.')&& (palavra[3] == '.')) {

        lcd_str("Z");

        Display();
        PORTD = 0x49;
        atraso_ms(1000);
        returnConfig();
        return 'Z';
    }
    return 0;
}

void Display() {
    
    //Configuração do Display
    
    TRISA = 0x00; //config da porta A 

    BitClr(INTCON2, 7); //liga pull up 
    ADCON1 = 0x0E; //config AD 

    TRISD = 0x00; //config. a porta D 
    PORTD = 0x00;
    BitSet(PORTA, 5); //liga o 1o display 
}

void returnConfig() {
    //Retorna a configuração 
    TRISA = 0x20;
    ADCON1 = 0x06;
    TRISD = 0x00;


}