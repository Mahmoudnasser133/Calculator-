/*
 * calculator.c
 *
 * Created: 27-Oct-22 10:50:02 AM
 *  Author: nasser
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "keypad_driver.h"
#include "LCD.h"
int main(void)
{
	LCD_vInit();
	keypad_vInit();
	char x,y,press_1,press_2,press_3,flag,operation;
	 int result;
	flag = 0;
	result=0;
lable:
while(1) //number 1 first digit 
	{
		
			press_1=keypad_u8check_press();
				
			if ((press_1!=0xff) && (flag ==0))
			{
				
				LCD_vSend_char(press_1);
				x=press_1-48;
				x=x*10;
				flag ++;
				_delay_ms(200);
				LCD_movecursor(1,2);
		
			}		
		if (flag==1)
			{
				break;
			}
		
	}

while(1) //number 1 second digit
{
	
	press_1=keypad_u8check_press();
	
	if ((press_1!=0xff) && (flag ==1))
	{
		
		LCD_vSend_char(press_1);
		press_2=press_1-48;
		x=x+press_2;
		flag++;
		_delay_ms(200);
		LCD_movecursor(1,3);
		
	}
	if (flag==2)
	{
		break;
	}
	
}

while(1) // operation
{
	
	press_1=keypad_u8check_press();
	
	if ((press_1!=0xff) && (flag ==2))
	{
		
		LCD_vSend_char(press_1);
		operation=press_1;
		flag++;
		_delay_ms(200);
		LCD_movecursor(1,4);
		
	}
	if (flag==3)
	{
		break;
	}
	
}


while(1) //number 2 first digit
	{
		
		press_1=keypad_u8check_press();
		
		if ((press_1!=0xff) && (flag ==3))
		{
			
			LCD_vSend_char(press_1);
			y=press_1-48;
			y=y*10;
			flag ++;
			_delay_ms(200);
			LCD_movecursor(1,5);
			
		}
		if (flag==4)
		{
			break;
		}
		
	}
	
while(1) //number 2 second digit
{
	
	press_1=keypad_u8check_press();
	
	if ((press_1!=0xff) && (flag ==4))
	{
		
		LCD_vSend_char(press_1);
		press_3=press_1-48;
		y=y+press_3;
		flag++;
		_delay_ms(200);
		LCD_movecursor(1,7);
		
	}
	if (flag==5)
	{
		break;
	}
	
}



	switch (operation)
	{
		case '+':
			result = x + y;
			break;
		case '-':
		if (x<y)
		{
			result = y-x;
			LCD_movecursor(1,8);
			LCD_vSend_char('-');
		}
		else{	result = x - y;}
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;

	}

	LCD_vSend_char('=');
	LCD_movecursor(1,9);
	if (result>999)
	{
		LCD_vSend_char(((result)/1000)+48);
		LCD_movecursor(1,10);
		LCD_vSend_char(((result%1000)/100)+48);
		LCD_movecursor(1,11);
		LCD_vSend_char((((result%1000)%100)/10)+48);
		LCD_movecursor(1,12);
		LCD_vSend_char((((result%1000)%100)%10)+48);

	}
	
		else if (result>99)
		{
			LCD_vSend_char(((result)/100)+48);
			LCD_movecursor(1,10);
			LCD_vSend_char(((result%100)/10)+48);
			LCD_movecursor(1,11);
			LCD_vSend_char(((result%100)%10)+48);
			
		}
		else if (result>9)
		{
			LCD_vSend_char(((result)/10)+48);
			LCD_movecursor(1,10);
			LCD_vSend_char((result%10)+48);
			
		}
		else if (result<=9)
		{
			LCD_vSend_char((result)+48);
			
		}

while(1) //repeat  
{
	
	press_1=keypad_u8check_press();
	_delay_ms(200);
	if ((press_1!=0xff))
	{
		if (press_1=='A')
		{
			LCD_clearscreen();
			flag=0;
			LCD_movecursor(1,1);
			
		}
		
		
	}
	if (flag==0)
		{
			goto lable;	
		}

}

}


