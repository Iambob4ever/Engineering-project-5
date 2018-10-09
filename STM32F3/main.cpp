#include "main.h"
#include "stepper.h"
//const int FULL_STEP[4] = {0x84, 0x88,0x48,0x44};

/*****************************************
This is the Stepper program. Basically it takes in an int and turns the motor by that amount.
If a negitive number is sent it rotates counter clockwise.
The code for full stepping is in here but is unused.

***************************************************/
int main()
{
	
	//Sets the clock and stuff
	SystemInit();
	SysTickInit();
	GPIO_InitTypeDef GPIOC_Stepper;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	
	
	//This should enable the clock to GIPOC
	//

	//6-A 7-B 8-A NOT 9-B NOT
	GPIOC_Stepper.GPIO_Mode = GPIO_Mode_OUT;
	GPIOC_Stepper.GPIO_OType = GPIO_OType_PP;
	GPIOC_Stepper.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIOC_Stepper.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIOC_Stepper.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	GPIO_Init(GPIOC,&GPIOC_Stepper);
	int turns = 900000;
	/*
	int turns = 900000;
	
	if(turns > 0)
	*/
	 //Halfstep();
		
		/*
	else if (turns < 0)
		*/
		Reverse_Halfstep();


	//Fullstep(turns);
	
	
	

	
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

void Halfstep()
{
	
	/*
	int i;
	for(i=0;i>turns;i++)
	
	
	*/
	while(1){
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
}

void Reverse_Halfstep()
{
	int i;
	while(1){
	//for(i=0;i>turns;i++)
	
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
}
	
	
	
	

