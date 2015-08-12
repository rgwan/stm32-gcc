/******************** (C) COPYRIGHT 2011 STMicroelectronics ********************
* File Name          : usb_init.c
* Author             : MCD Application Team
* Version            : V3.3.0
* Date               : 21-March-2011
* Description        : Initialization routines & global variables
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "user_uart.h"
#define USBINIT_DEBUG 0
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/*  The number of current endpoint, it will be used to specify an endpoint */
 uint8_t	EPindex;
/*  The number of current device, it is an index to the Device_Table */
/* uint8_t	Device_no; */
/*  Points to the DEVICE_INFO structure of current device */
/*  The purpose of this register is to speed up the execution */
DEVICE_INFO *pInformation;
/*  Points to the DEVICE_PROP structure of current device */
/*  The purpose of this register is to speed up the execution */
DEVICE_PROP *pProperty;
/*  Temporary save the state of Rx & Tx status. */
/*  Whenever the Rx or Tx state is changed, its value is saved */
/*  in this variable first and will be set to the EPRB or EPRA */
/*  at the end of interrupt process */
uint16_t	SaveState ;
uint16_t  wInterrupt_Mask;
DEVICE_INFO	Device_Info;
USER_STANDARD_REQUESTS  *pUser_Standard_Requests;

/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : USB_Init
* Description    : USB system initialization
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void USB_Init(void)
{
      #ifdef  USBINIT_DEBUG 
      dbg("usb init set\r\n");
     #endif
      
  pInformation = &Device_Info;
  pInformation->ControlState = 2;//设为IN_DATA状态
  pProperty = &Device_Property;//结构体中存储的为操作函数指针
  pUser_Standard_Requests = &User_Standard_Requests;//是用户对标准请求的实现
  /* Initialize devices one by one */
  pProperty->Init();//调用MASS_init（）函数 usb_prop.c中，实现usb初始化
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
