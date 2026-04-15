#include "stm32f10x.h"                  // Device header
#include "Led.h"
#include "Delay.h"

void EXTI_Key_Init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource4);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line=EXTI_Line4|EXTI_Line5;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	
	
	
	EXTI_Init(&EXTI_InitStructure);
	
	
  
}
void EXTI_NVIC_Config(void)
{
	
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	NVIC_InitTypeDef NVIC_InitStruvture;
	NVIC_InitStruvture.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitStruvture.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruvture.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruvture.NVIC_IRQChannelSubPriority=0;
	NVIC_Init (&NVIC_InitStruvture);

	NVIC_InitStruvture.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitStruvture.NVIC_IRQChannelPreemptionPriority=2; 
	NVIC_InitStruvture.NVIC_IRQChannelSubPriority=0;
	NVIC_Init (&NVIC_InitStruvture);
}

void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4)==SET)
	{
		Delay_ms(10);
		  if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4) == 0)
        {
           LED_Left(3);
        }
		EXTI_ClearITPendingBit(EXTI_Line4);
	}
	
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line5)==SET)
	{
	    // 消抖
        Delay_ms(10);
        if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 0)
        {
            LED_RightShift(3);  // 调用LED_RightShift函数
        }
		EXTI_ClearITPendingBit(EXTI_Line5);
	}
	
}