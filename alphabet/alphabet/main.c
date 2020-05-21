/*
 * alfabeto.c
 *
 * Created: 15/02/2017 11:38:20
 * Author : jazzr
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <compat/deprecated.h>
#include "lcd.h"

void configuration();
void selec1();
void selec2();
void selec3();	

char cont1=0, cont2=0, aux=0, word=0, write=0, write2=0, cont3=0;

int main(void)
{
	configuration();
	sei ();
	
	lcd_init(LCD_DISP_ON);
	lcd_gotoxy(5,0);
	lcd_puts("ACAT");	
	lcd_gotoxy(2,1);
	lcd_puts("IMPLEMENTATION");
	lcd_gotoxy(4,2);
	lcd_puts("PROTOTYPE");
    _delay_ms(3400);
	lcd_clrscr();
	
    while (1) 
    {	
		switch (cont1)
		{
		case 0:
			if (aux==0)
			{
				lcd_gotoxy(0,0);
				lcd_puts("*ABCDEFGHIJKLMN ");
				lcd_gotoxy(0,1);
				lcd_puts(" 0PQRSTUVWXYZ ESP");
				lcd_gotoxy(0,2);
				lcd_puts(" ERASE CLEAR");
			}
			if (aux==1)
			{
				lcd_gotoxy(0,0);
				lcd_puts(" ABCDEFGHIJKLMN   ");
				lcd_gotoxy(0,1);
				lcd_puts("*0PQRSTUVWXYZ ESP");
				lcd_gotoxy(0,2);
				lcd_puts(" ERASE CLEAR");
			}
				if (aux==2)
				{
					lcd_gotoxy(0,0);
					lcd_puts(" ABCDEFGHIJKLMN   ");
					lcd_gotoxy(0,1);
					lcd_puts(" 0PQRSTUVWXYZ ESP");
					lcd_gotoxy(0,2);
					lcd_puts("*ERASE CLEAR");
				}
			break;
			
		case 1:
			_delay_ms(5);
			lcd_gotoxy(0,1);
			lcd_puts("                    ");
			_delay_ms(5);
			lcd_gotoxy(0,2);
			lcd_puts("                    ");

			_delay_ms(5);
			lcd_gotoxy(0,0);
			lcd_puts(" ABCDEFGHIJKLMN    ");
			lcd_gotoxy(cont2,1);
			lcd_puts(" * ");
			lcd_gotoxy(0,2);
			lcd_puts("                 ");
			break;
						
		case 2:
			_delay_ms(5);
				lcd_gotoxy(0,1);
				lcd_puts("                    ");
			_delay_ms(5);
				lcd_gotoxy(0,2);
				lcd_puts("                    ");
			
			_delay_ms(5);
			lcd_gotoxy(0,0);
			lcd_puts(" 0PQRSTUVWXYZ ESP");
			lcd_gotoxy(cont2,1);
			lcd_puts(" * ");
		
			break;
					
		case 3:
			_delay_ms(5);
			lcd_gotoxy(0,1);
			lcd_puts("                    ");
			_delay_ms(5);
			lcd_gotoxy(0,2);
			lcd_puts("                    ");

		_delay_ms(5);
		lcd_gotoxy(0,0);
		lcd_puts(" ERASE CLEAR   ");
		lcd_gotoxy(cont2,1);
		lcd_puts("    *    ");
		break;
			
		}	
	}
}



void configuration(){
	/////port
	DDRA=0b11111110;
	PORTA=0;
	DDRB=0;
	PORTB=(1<<PB2);
	DDRC=1;
	PORTC=0;

	/////interrupt
	EICRA=(1<<ISC21);
	EIMSK=(1<<INT2);
	
	/////timer int
	TCCR1A=0;
	TCCR1B|=(1<<WGM12)|(1<<CS12)|(1<<CS10);
	TCCR1C=0;
	OCR1AH=0x0f;
	OCR1AL=0xff;
	TIMSK1=(1<<OCIE1A);
	
}


void selec1(){
	_delay_ms(20);
	switch (cont2){
		case 0:
		lcd_gotoxy(cont3,3);
		lcd_puts("A");
		break;
		case 1:
		lcd_gotoxy(cont3,3);
		lcd_puts("B");
		break;
		
		case 2:
		lcd_gotoxy(cont3,3);
		lcd_puts("C");
		break;
		
		case 3:
		lcd_gotoxy(cont3,3);
		lcd_puts("D");
		break;
		
		case 4:
		lcd_gotoxy(cont3,3);
		lcd_puts("E");
		break;
		
		case 5:
		lcd_gotoxy(cont3,3);
		lcd_puts("F");
		break;
		
		case 6:
		lcd_gotoxy(cont3,3);
		lcd_puts("G");
		break;
		
		case 7:
		lcd_gotoxy(cont3,3);
		lcd_puts("H");
		break;
		
		case 8:
		lcd_gotoxy(cont3,3);
		lcd_puts("I");
		break;
		
		case 9:
		lcd_gotoxy(cont3,3);
		lcd_puts("J");
		break;
		
		case 10:
		lcd_gotoxy(cont3,3);
		lcd_puts("K");
		break;
		
		case 11:
		lcd_gotoxy(cont3,3);
		lcd_puts("L");
		break;
		
		case 12:
		lcd_gotoxy(cont3,3);
		lcd_puts("M");
		break;
		
		case 13:
		lcd_gotoxy(cont3,3);
		lcd_puts("N");
		break;
		default:
		break;
		
	}
	cont1=0;
	cont2=0;
	aux=0;
	_delay_ms(20);
}

void selec2(){
	_delay_ms(20);
	switch(cont2){
		case 0:
		lcd_gotoxy(cont3,3);
		lcd_puts("O");
		break;
		
		case 1:
		lcd_gotoxy(cont3,3);
		lcd_puts("P");
		break;
		
		case 2:
		lcd_gotoxy(cont3,3);
		lcd_puts("Q");
		break;
		
		case 3:
		lcd_gotoxy(cont3,3);
		lcd_puts("R");
		break;
		
		case 4:
		lcd_gotoxy(cont3,3);
		lcd_puts("S");
		break;
		
		case 5:
		lcd_gotoxy(cont3,3);
		lcd_puts("T");
		break;
		
		case 6:
		lcd_gotoxy(cont3,3);
		lcd_puts("U");
		break;
		
		case 7:
		lcd_gotoxy(cont3,3);
		lcd_puts("V");
		break;
		
		case 8:
		lcd_gotoxy(cont3,3);
		lcd_puts("W");
		break;
		
		case 9:
		lcd_gotoxy(cont3,3);
		lcd_puts("X");
		break;
		
		case 10:
		lcd_gotoxy(cont3,3);
		lcd_puts("Y");
		break;
		
		case 11:
		lcd_gotoxy(cont3,3);
		lcd_puts("Z");
		break;
		
		case 12:
		lcd_gotoxy(cont3,3);
		lcd_puts(" ");
		break;
		case 13:
		lcd_gotoxy(cont3,3);
		lcd_puts(" ");
		break;
		default:
		break;
	}
	cont1=0;
	cont2=0;
	aux=0;
	_delay_ms(20);
}

void selec3(){
	_delay_ms(20);
	switch(cont2)
	{
		case 0:
		cont3-=1;
		lcd_gotoxy(cont3,3);
		lcd_puts(" ");
		cont3-=1;
		break;
		case 7:
		lcd_gotoxy(0,3);
		lcd_puts("                    ");
		break;
		default:
		break;
	}
	cont1=0;
	cont2=0;
	aux=0;
	_delay_ms(20);
}

ISR (INT2_vect){
	_delay_ms(50);
	switch(cont1){
		case 0:
	if (aux==0){
		
		cont1=1;
	}
	if (aux==1){
		
		cont1=2;
	}
	if (aux==2){
		
		cont1=3;
	}
	break;
	case 1:
		if (cont3==20)
		{
			cont3=0;
		}
		else{
		cont3+=1;
		selec1();
		}
	break;
	case 2:
		if (cont3==20)
		{
			cont3=0;
		}
		else{
		cont3+=1;
		selec2();
		
		}
	break;
	
	case 3:
	if (cont3==20)
	{	
		
		cont3=0;
	}
	else{
		cont3+=1;
		selec3();
	}
	break;
	default:
	break;
	}
	

	
}

ISR (TIMER1_COMPA_vect){
	if (cont1==0){
		if (aux==3)
		{
			aux=0;
		}
		else {
			aux+=1;
		}
		
	}
	
	if (cont1==1)////ABC
	{
		if (cont2==14)
		{
			cont2=0;
		}
		else
		{
			cont2+=1;
		}
	}
	if (cont1==2)////OPQ
	{
		
		if (cont2==14)
		{
			cont2=0;
		}
		else
		{
			cont2+=1;
		}
	}
	if (cont1==3)////ERASE clear
	{
		
		if (cont2==7)
		{
			cont2=0;
		}
		else
		{
			cont2=cont2+7;
		}
	}
}