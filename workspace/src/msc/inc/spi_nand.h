#ifndef SPI_NAND_H_
#define SPI_NAND_H_

#include <stddef.h>
typedef struct
{
  uint8_t Manufacture_ID;
  uint8_t Device_ID;
} NAND_IDTypeDef;
//----------Hardware Define ------------------
#define DUMMY_BYTE                      0x00
#define WRITE_ENABLE                    0x06
#define WRITE_DISABLE                   0x04
#define GET_FEATURES                    0x0f
#define SET_FEATURES                    0x1f
#define PAGE_READTOCACHE                0x13
#define READ_FROM_CACHE                 0x03
#define READ_ID                         0x9f
#define PROGRAM_LOAD                    0x02
#define PROGRAM_LOAD_X4                 0x32
#define PROGRAM_EXEXUTE                 0x10
#define PROGRAM_LOAD_RANDOM_DATA        0x84
#define PROGRAM_LOAD_RANDOM_DATA_X4     0xc4
#define PROGRAM_LOAD_RANDOM_DATA_QIO    0x72
#define BLOCK_ERASE                     0xd8
#define RESET                           0xff

#define PROTECTION_REG					0xa0
#define FEATURE_REG						0xb0
#define STATUS_REG						0xc0

#define SPI_CS_ENABLE GPIO_ResetBits(GPIOA, GPIO_Pin_4)
#define SPI_CS_DISABLE GPIO_SetBits(GPIOA, GPIO_Pin_4)

#define SPI_HOLD_ENABLE GPIO_ResetBits(GPIOA, GPIO_Pin_3)
#define SPI_HOLD_DISABLE GPIO_SetBits(GPIOA, GPIO_Pin_3)

#define SPI_WP_ENABLE GPIO_ResetBits(GPIOA, GPIO_Pin_2)
#define SPI_WP_DISABLE GPIO_SetBits(GPIOA, GPIO_Pin_2)
//-------------Software define 
//FLASH块数
#define FLASH_BLOCKS		1024

//FLASH每块页数
#define FLASH_PAGES_PER_BLOCK 64

//FLASH页大小，为2KB
#define FLASH_PAGE_SIZE 0x800

//扇区大小
#define SECTOR_SIZE 0x200

//用做交换区的块数
#define FLASH_SWAP_BLOCKS 16

//用做坏块重新影射的块数
#define FLASH_BAD_BLOCKS_REMAP 64

//交换区开始块
#define FLASH_SWAP_OFFSET (FLASH_BLOCKS - FLASH_BAD_BLOCKS_REMAP - FLASH_SWAP_BLOCKS)

//重映射区开始块
#define FLASH_BAD_BLOCKS_REMAP_OFFSET (FLASH_BLOCKS - FLASH_BAD_BLOCKS_REMAP)

typedef uint16_t nand_block_t;
typedef uint32_t nand_page_t;

#define NAND_OK			0
#define NAND_E_ECC 		-1
#define NAND_E_BAD_BLK	-2
#define NAND_E_TIMEOUT	-3
#define NAND_E_NO_REMAP	0xffffUL

/* 状态
 * 正在读 
 * 需要擦除块
 * 已擦除，写入未跳页
 * 已擦除，写入需跳页
 * 已擦除，写入需跳块
 */
#define	FLASH_READING  		0
#define	FLASH_NEED_ERASE	1
#define	FLASH_IN_PAGE		2
#define	FLASH_IN_BLOCK		3
#define	FLASH_OUT_BLOCK		4



void NAND_Reset(void);
void NAND_WriteEnable(void);
void NAND_WriteDisable(void);
uint8_t NAND_GetFeatures(uint8_t Address);
void NAND_SetFeatures(uint8_t Address, uint8_t fData);
void NAND_ReadID(NAND_IDTypeDef* NAND_ID);
void nand_init();
int nand_is_bad(nand_block_t b);
int nand_mark_bad(nand_block_t b);
void nand_read_from_cache(size_t offset, size_t length,uint8_t *data);
int nand_read_to_cache(nand_page_t p);
void nand_write_to_cache(size_t offset, size_t length, const uint8_t *data);
int nand_write_from_cache(nand_page_t p);
int nand_erase(nand_block_t b);
int nand_copy(nand_page_t src, nand_page_t dst);

int ftl_read(uint8_t *copy_to,uint32_t sector);
int ftl_write(const uint8_t *copy_from, 
	const uint32_t sector);
nand_block_t ftl_deal_badblock(nand_block_t b, uint8_t method);
int ftl_getblocks(void);
#endif /* SPI_NAND_H_ */
