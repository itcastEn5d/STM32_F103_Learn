#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Led.h"
#include "Key.h"
#include "bsp_exti.h"

int main(void)
{
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
		LED_Init();
	  KEY_Init();
	EXTI_Key_Init();
	EXTI_NVIC_Config();
	while(1){
				// D1闪烁
		LED_Toggle(GPIO_Pin_2);
		Delay_ms(500);
		if(Key_GetNum()==1)
		{
			for (int i = 0; i < 3; i++)
			{
				// 打开所有LED
				LED_ON(GPIO_Pin_2);
				LED_ON(GPIO_Pin_3);
				LED_ON(GPIO_Pin_4);
				LED_ON(GPIO_Pin_5);
				Delay_ms(300);
				
				// 关闭所有LED
				LED_OFF(GPIO_Pin_2);
				LED_OFF(GPIO_Pin_3);
				LED_OFF(GPIO_Pin_4);
				LED_OFF(GPIO_Pin_5);
				Delay_ms(300);
		}
		
	}
	
}
	
}