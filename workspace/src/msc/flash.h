/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Andrzej Surowiec <emeryth@gmail.com>
 * Copyright (C) 2013 Pavol Rusnak <stick@gk2.sk>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __FLASH_H
#define __FLASH_H

#include <stdint.h>

extern int ramdisk_init(void);
extern int ramdisk_read(uint8_t *copy_to,uint32_t offset,
	const uint32_t length);
extern int ramdisk_write(const uint8_t *copy_from, 
	const uint32_t offset, const uint32_t length);
extern int ramdisk_blocks(void);

#define APP_ADDRESS				0x08002000
#define Blk_OK	0
#endif
