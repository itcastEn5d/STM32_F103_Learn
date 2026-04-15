#ifndef  __LED_H
#define  __LED_H
#include "stm32f10x.h"                  // Device header




// LED¿ØÖÆº¯Êý
void LED_Init(void);
void LED_ON(uint16_t GPIO_Pin);
void LED_OFF(uint16_t GPIO_Pin);
void LED_Toggle(uint16_t GPIO_Pin);
void LED_Left(uint8_t  times);
void LED_RightShift(uint8_t times);


#endif 

