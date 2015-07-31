/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef _USER_UART_H
#define _USER_UART_H

#include "stm32f10x.h"
//#include "platform_config.h"
//#include "stm32_eval.h"
/* Includes ------------------------------------------------------------------*/




/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void UART1_Configuration(void);
void UART1_GPIO_Configuration(void);
extern uint8_t Uart1_PutChar(uint8_t ch);
extern int _write(int file, char *ptr, int len);

#define dbg(...) printf(__VA_ARGS__)
#endif /* _USER_UART_H */
