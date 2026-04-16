#include "stm32f10x.h"                  // Device header
#include "Led.h"
#include "Delay.h"

void EXTI_Key_Init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开启AFIO的时钟

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource4);//选择一个 GPIO 引脚，把它用作外部中断线。
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);//选择GPIOCPinSource5作为外部中断线
	//配置EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line=EXTI_Line4|EXTI_Line5;//选择EXTI_Line4|EXTI_Line5作为中断线
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	
	EXTI_Init(&EXTI_InitStructure);
	
	
  
}
void EXTI_NVIC_Config(void)
{
	//NVIC分组
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	//配置NVIC
	NVIC_InitTypeDef NVIC_InitStruvture;
	NVIC_InitStruvture.NVIC_IRQChannel=EXTI4_IRQn;//选择EXTI4_IRQn作为中断通道
	NVIC_InitStruvture.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruvture.NVIC_IRQChannelPreemptionPriority=1;//配置抢占优先级
	NVIC_InitStruvture.NVIC_IRQChannelSubPriority=0;//配置响应优先级
	NVIC_Init (&NVIC_InitStruvture);

	NVIC_InitStruvture.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitStruvture.NVIC_IRQChannelPreemptionPriority=2; 
	NVIC_InitStruvture.NVIC_IRQChannelSubPriority=0;
	NVIC_Init (&NVIC_InitStruvture);
}

//中断服务函数
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4)==SET)//确认EXTI_Line4是否被触发
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