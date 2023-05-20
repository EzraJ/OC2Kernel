#include "uart/uart.hpp"

extern "C"{


    void uart_init(size_t base_addr){
        volatile uint8_t *ptr = (uint8_t *)base_addr;
        const uint8_t LCR = 0b11;
        ptr[3] = LCR;
        ptr[2] = 0b1;
        ptr[1] = 0b1;
    }

    void uart_putc(size_t base_addr, uint8_t c){
        *(uint8_t *)base_addr = c;
    }

    void uart_print(const char *str){
        
    }

}