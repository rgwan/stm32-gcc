#include <stm32f10x.h>

int main(void) {
	/*!< At this stage the microcontroller clock setting is already configured, 
	  this is done through SystemInit() function which is called from startup
	  file (startup_stm32f10x_xx.s) before to branch to application main.
	  To reconfigure the default setting of SystemInit() function, refer to
	  system_stm32f10x.c file
	  */     

	while (1) {
	}

	return 0;
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line) { 
	/* User can add his own implementation to report the file name and line number,
	 * ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1){
	}
}
#endif
