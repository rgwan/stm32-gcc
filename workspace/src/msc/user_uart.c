/****************************************Copyright (c)**************************************************
**                       思 蜕 盟 豆 皮 开 发 小 组
**                             stmfans 论坛
**
**                   QQ 群: 65081316  StmFans思蜕盟 1组
**                   QQ 群: 68584951  StmFans思蜕盟 2组
**                      http://www.stmfans.com/bbs/
**
** This program was produced by the
** IAR Embedded Workbench 4.0 Kickstart 442
** Copyright 2008-2009 stmfans 
** Chip type           : STM32F103VB
** Program type        : Application
** Clock frequency     : 8.000000 MHz
** Memory model        : 
** External SRAM size  : 
** Data Stack size     : 
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: user_uart.c
**创   建   人: 陈海
**最后修改日期: 2008年10月23日
**描        述: 豆皮开发板教程
**              
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: 陈海
** 版  本: v0.01
** 日　期: 2008年10月23日
** 描　述: 原始版本
**
**--------------当前版本信息----------------------------------------------------------------------------
** 创建人: 陈海
** 版  本: v0.01
** 日　期: 2008年10月23日
** 描　述: 当前版本
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "user_uart.h"

#include <errno.h>
/*******************************************************************************
* Function Name  : UART1_Configuration
* Description    : Configures the uart1 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UART1_Configuration(void)
{
  USART_InitTypeDef USART_InitStructure;
  /* USART1 configured as follow:
        - BaudRate = 9600 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No ;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  
  /* Configure the USART1*/ 
  USART_Init(USART1, &USART_InitStructure);

  
  /* Enable the USART1 */
  USART_Cmd(USART1, ENABLE);  
}


/*******************************************************************************
* Function Name  : UART1_GPIO_Configuration
* Description    : Configures the uart1 GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UART1_GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
     // Enable USART1 clocks 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  
  // Configure USART1_Tx as alternate function push-pull 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//PA9 TX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  // Configure USART1_Rx as input floating 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10 RX
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);  
}


/*******************************************************************************
* Function Name  : Uart1_PutChar
* Description    : dbg a char to the uart.
* Input          : ch 需要发送的字符 
* Output         : None
* Return         : None
*******************************************************************************/
uint8_t Uart1_PutChar(uint8_t ch)
{
  /* Write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);
  while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
  {
  }
  return ch;
}

/*******************************************************************************
* Function Name  : Uart1_PutString
* Description    : print a string to the uart1
* Input          : buf为发送数据的地址 , len为发送字符的个数
* Output         : None
* Return         : None
*******************************************************************************/
void Uart1_PutString(uint8_t* buf , uint8_t len)
{
	uint8_t i;
    for(i=0;i<len;i++)
    {
        Uart1_PutChar(*buf++);
    }
}
int _write(int file, char *ptr, int len)
{
	int i;

	if (file == 1) {
		for (i = 0; i < len; i++)
			Uart1_PutChar(ptr[i]);
		return i;
	}

	errno = EIO;
	return -1;
}
void* _sbrk(intptr_t increment)
{
	errno = ENOMEM;
	return (void *)-1;
}
int _close(int fd) 
{
	errno = EIO;
	return -1;
}
int _fstat(char *handle, void *buff)
{
	errno = EIO;
	return -1;
}
int _isatty(int desc)
{
	return 0;
}
int _read(int fd, void *buf, size_t count)
{
	errno = EIO;
	return -1;
}
int _lseek(int handle, int offset, int fromwhere)
{
	errno = EIO;
	return -1;
}
