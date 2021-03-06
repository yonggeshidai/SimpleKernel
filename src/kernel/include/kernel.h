
// This file is a part of Simple-XX/SimpleKernel
// (https://github.com/Simple-XX/SimpleKernel).
//
// kernel.h for Simple-XX/SimpleKernel.

#ifndef _KERNEL_H_
#define _KERNEL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "console.h"
#include "multiboot2.h"
#include "arch_init.h"
#include "pmm.h"

void kernel_main(uint32_t magic, uint32_t addr);

void showinfo(void);
void showinfo(void) {
    // 输出一些基本信息
    printk_color(magenta, "SimpleKernel\n");
    printk_info("kernel in memory(VMA==LMA) start: 0x%08X, end 0x%08X\n",
                &kernel_start, &kernel_end);
    printk_info(".text in memory(VMA==LMA) start: 0x%08X, end 0x%08X\n",
                &kernel_text_start, &kernel_text_end);
    printk_info(".data in memory(VMA==LMA) start: 0x%08X, end 0x%08X\n",
                &kernel_data_start, &kernel_data_end);
    printk_info("kernel in memory size: %d KB, %d pages\n",
                (&kernel_end - &kernel_start) / 1024,
                (&kernel_end - &kernel_start) / PMM_PAGE_SIZE);
}

#ifdef __cplusplus
}
#endif

#endif /* _KERNEL_H_ */
