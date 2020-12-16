/*
 Alunos: Felipe Pasqua Rodrigues 2019000591 
         Matheus Bueno Queiroz   2019000199
 
 Trabalho de Programação Embarcada - ECOPO4
 UNIFEI - Universidade Federal de Itajubá
 
            TRADUTOR DE CÓDIGO MORSE 
 
 */





#include "config.h"
#include "pic18f4520.h"
#include "delay.h"
#include "lcd.h"
#include "teclado.h"
#include "stdio.h"
#include "string.h"

/*
 *  RB1 é usado para fazer o traço
 *  RB3 é usado para fazer ponto
 *  RB4 é usado para realizar a tradução após a inserção das letras
 *  RB5 é usado para fazer a tradução de cada letra
 *  RB0 é usado para reiniciar o programa
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
*/

unsigned int atrasoMin = 20;
unsigned int atrasoMed = 500;
unsigned int atrasoMax = 1000;

void main() {
    char codigo [4];
    memset(codigo, 'V', sizeof(codigo));
    char palavra [16];

    int i = 0;
    int pos = 0;

    // Configuração do LCD
    ADCON1 = 0x06;
    TRISB = 0x01;
    TRISD = 0x00;
    TRISE = 0x00;

    lcd_init(); //Inicia LCD
    TRISA = 0x20;
    TRISB = 0x3F;

    
    lcd_cmd(L_CLR); //Limpa o LCD
    lcd_cmd(L_L1);
    lcd_str("Digite o Codigo");
    BitClr(PORTB, 1);
    BitClr(PORTB, 3);

    while (BitTst(PORTB, 0)) { //looping usado para reset do programa

        if (!BitTst(PORTB, 1) && pos < 4 ) { // Botão 1 utilizado para adicionar um traço, quando pressionado entra na condição
            lcd_cmd(L_L2 + pos);             // Seleciona posição do cursor
            lcd_str("-");                    // Mostra traço no LCD
            codigo[pos] = '-';               // Armazena o traço na variavel código
            pos++;                           // Incremento da variável de controle
           
            atraso_ms(500);
            
        }

        if (!BitTst(PORTB, 3) && pos < 4) { // Botão 3 utilizado para adicionar um ponto, quando pressionado entra na condição
            lcd_cmd(L_L2 + pos);            // Seleciona posição do cursor
            lcd_str(".");                   // Mostra ponto no LCD
            codigo[pos] = '.';              // Armazena o ponto na variavel código
            pos++;                          // Incremento da variável de controle
 
            atraso_ms(500);
        }

        if (!BitTst(PORTB, 5)) {            //Botão 5 utilizado para realizar a tradução do caracter digitado
            
            lcd_cmd(L_L1);                  //Seleciona Linha
            lcd_cmd(L_CLR);                 // Limpa LCD
          
           
            
            palavra[i] = traduzMorse(codigo);   //Variavel palavra recebe o char da função traduzMorse
           
            i++;                                
            pos = 0;
            atraso_ms(2000);
            lcd_cmd(L_CLR);                     // Limpa LCD
            lcd_cmd(L_L1);                      //Seleciona Linha
            lcd_str("Digite o Codigo");         //Continuação do código
             memset(codigo, 'V', sizeof(codigo));   //Limpa o vetor codigo
        }

        if (!BitTst(PORTB, 4)) {        //Botão 4, utilizado para mostrar a palavra formada
            i = 0;
            lcd_cmd(L_L1);              //Seleciona Linha
            lcd_cmd(L_CLR);              // Limpa LCD
            lcd_str("TRADUCAO");
            atraso_ms(2000);
            lcd_cmd(L_L2);              //Seleciona Linha
            lcd_str(palavra);           //Exibe o vetor palavra que contem a junção de todos os caracteres
        
        }
    }
}