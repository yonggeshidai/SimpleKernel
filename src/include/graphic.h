
// This file is apart of MRNIU/SimpleKernel (https://github.com/MRNIU/SimpleKernel).

// graphic.h for MRNIU/SimpleKernel.


#include "kernel.h"
#include "stdint.h"
#include "stddef.h"

#ifndef _GRAPHIC_H
#define _GRAPHIC_H


// 设置颜色，详解见 '颜色设置与位运算.md'
// fg-font
// bg-back
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return fg | (bg << 4);
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

// 获取字符串长度
size_t strlen(const char* str)
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

#endif