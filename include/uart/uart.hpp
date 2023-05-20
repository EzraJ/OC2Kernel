#ifndef UART_H
#define UART_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define UART_ADDR 0x10000148

extern "C"{

    void uart_init(size_t base_addr);
    void uart_putc(size_t base_addr, uint8_t c);
    void uart_print(const char* str);

}

#endif