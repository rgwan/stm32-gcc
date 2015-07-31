#include <stm32f10x.h>

#define RCC_GPIO_LED                                 RCC_APB2Periph_GPIOB
#define GPIO_LED_PORT                                GPIOB     
#define GPIO_LED2                                    GPIO_Pin_3    
#define GPIO_LED3                                    GPIO_Pin_4    
#define GPIO_LED4                                    GPIO_Pin_12
#define GPIO_LED_ALL                        GPIO_LED2 |GPIO_LED3 |GPIO_LED4 
void delay(void)
{
	uint32_t i;
	for(i = 0; i < 3000000L; i++) 
	{
	}
}
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	SystemInit();
	/* Enable GPIOB, GPIOC and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_GPIO_LED | RCC_APB2Periph_AFIO , ENABLE);  
	
	/* LEDs pins configuration */
	GPIO_InitStructure.GPIO_Pin = GPIO_LED_ALL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_LED_PORT, &GPIO_InitStructure);
	
	for(;;)
	{
		GPIO_SetBits(GPIO_LED_PORT, GPIO_LED_ALL);
		delay();
		GPIO_ResetBits(GPIO_LED_PORT, GPIO_LED_ALL);
        delay();
	}	
}
