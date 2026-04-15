#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#define LED1 GPIO_Pin_2
#define LED2 GPIO_Pin_3
#define LED3 GPIO_Pin_4
#define LED4 GPIO_Pin_5
void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_SetBits(GPIOE,GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5);
}

// 打开LED
void LED_ON(uint16_t GPIO_Pin)
{
   GPIO_ResetBits(GPIOE, GPIO_Pin);
	
}
// 关闭LED
void LED_OFF(uint16_t GPIO_Pin)
{
	GPIO_SetBits(GPIOE, GPIO_Pin);
}
// 翻转LED状态
void LED_Toggle(uint16_t GPIO_Pin)
{
	if (GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin) == Bit_RESET)
	{
		GPIO_SetBits(GPIOE, GPIO_Pin);//1
	}
	else
	{
		GPIO_ResetBits(GPIOE, GPIO_Pin);//0
	}
}
void LED_Left(uint8_t  times)
{
	 for (uint8_t i = 0; i < times; i++)
    {
        LED_ON(LED1);
        Delay_ms(100);
        LED_OFF(LED1);
        
        LED_ON(LED2);
        Delay_ms(100);
        LED_OFF(LED2);
        
        LED_ON(LED3);
        Delay_ms(100);
        LED_OFF(LED3);
        
        LED_ON(LED4);
        Delay_ms(100);
        LED_OFF(LED4);
    }
}

void LED_RightShift(uint8_t times)
{
    for (uint8_t i = 0; i < times; i++)
    {
        LED_ON(LED4);
        Delay_ms(100);
        LED_OFF(LED4);
        
        LED_ON(LED3);
        Delay_ms(100);
        LED_OFF(LED3);
        
        LED_ON(LED2);
        Delay_ms(100);
        LED_OFF(LED2);
        
        LED_ON(LED1);
        Delay_ms(100);
        LED_OFF(LED1);
    }
}