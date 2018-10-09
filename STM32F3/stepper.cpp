#include "main.h"
#include "stepper.h"
//const int FULL_STEP[4] = {0x84, 0x88,0x48,0x44};


/*****************************************
This is the Stepper program. Basically it takes in an int and turns the motor by that amount.
If a negitive number is sent it rotates counter clockwise.
The code for full stepping is in here but is unused.
***************************************************/
int Stepper(int turns)
{
	
	
	
	//Sets the clock for the stepper motors
	SystemInit();
	SysTickInit();
	GPIO_InitTypeDef GPIOC_Stepper;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	
	
	//This should enable the clock to GIPOC
	

	//6-A 7-B 8-A NOT 9-B NOT
	GPIOC_Stepper.GPIO_Mode = GPIO_Mode_OUT;
	GPIOC_Stepper.GPIO_OType = GPIO_OType_PP;
	GPIOC_Stepper.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIOC_Stepper.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIOC_Stepper.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	GPIO_Init(GPIOC,&GPIOC_Stepper);


	//sets the clock for the limit switchs
	GPIO_InitTypeDef GPIOB_Limit_Switchs;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	
	GPIOB_Limit_Switchs.GPIO_Mode = GPIO_Mode_IN;
	GPIOB_Limit_Switchs.GPIO_OType = GPIO_OType_PP;
	GPIOB_Limit_Switchs.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_10;
	GPIOB_Limit_Switchs.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIOB_Limit_Switchs.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	//If turns is postitive-> Goes clockwise
	if(turns > 0)
	 Halfstep(turns);
		
	//else if negitive ->goes counter-clockwise
	else if (turns < 0)
		Reverse_Halfstep(turns);

	return(0);
}

void Fullstep(int turns)
{
	int i;
	for(i=0;i>turns;i++)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_6|GPIO_Pin_9);
			Delay(10);
		GPIO_ResetBits(GPIOC,GPIO_Pin_9);
		GPIO_SetBits(GPIOC,GPIO_Pin_6|GPIO_Pin_7);
		Delay(10);
		GPIO_ResetBits(GPIOC,GPIO_Pin_6);
		GPIO_SetBits(GPIOC,GPIO_Pin_8|GPIO_Pin_7);
		Delay(10);
		GPIO_ResetBits(GPIOC,GPIO_Pin_7);
		GPIO_SetBits(GPIOC,GPIO_Pin_8|GPIO_Pin_9);
		Delay(10);
		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
	}
}

void Halfstep(int turns)
{
	
	
	int i;
	for(i=0;i>turns;i++)
	{
		//read the right limit switch
		GPIO_ReadBit(GPIOB, GPIO_Pin_10);
		if ( GPIO_Pin_10 != 1)
			{
			GPIO_SetBits(GPIOC,GPIO_Pin_6|GPIO_Pin_9);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_9);
			Delay(2);
			GPIO_SetBits(GPIOC,GPIO_Pin_6|GPIO_Pin_7);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);
			Delay(2);
			GPIO_SetBits(GPIOC,GPIO_Pin_7|GPIO_Pin_8);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_7);
			Delay(2);
			GPIO_SetBits(GPIOC,GPIO_Pin_8|GPIO_Pin_9);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);
			Delay(2);
			}
		else
			i=turns;
			
	}
}

void Reverse_Halfstep(int turns)
{
	int i;
	
	for(i=0;i>turns;i++)
	{
		//read the left limit switch
		GPIO_ReadBit(GPIOB, GPIO_Pin_10);
		if ( GPIO_Pin_2 != 1)
			{
			GPIO_SetBits(GPIOC,GPIO_Pin_9);
			Delay(2);
			GPIO_SetBits(GPIOC,GPIO_Pin_9|GPIO_Pin_8);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_9);
			Delay(2);
			GPIO_SetBits(GPIOC,GPIO_Pin_7|GPIO_Pin_8);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);
			Delay(2);
			GPIO_SetBits(GPIOC,GPIO_Pin_7|GPIO_Pin_6);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_7);
			Delay(2);
			GPIO_SetBits(GPIOC,GPIO_Pin_9|GPIO_Pin_6);
			Delay(2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);
			}
			
		else
		i=turns;
	}
}
	
	
	
	

