#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "uart/uart.hpp"

extern "C"{
	void kmain(void){
		uart_init(UART_ADDR);
		uart_putc(UART_ADDR, 'H');
		uart_putc(UART_ADDR, 'e');
		uart_putc(UART_ADDR, 'l');
		uart_putc(UART_ADDR, 'l');
		uart_putc(UART_ADDR, 'o');

		while(true){
			
		}
	}
}


extern "C"{
	void _start(){
		asm(".option push");
		asm(".option norelax");
		asm("la gp, _global_pointer");
		asm(".option pop");
		asm("la sp, _init_stack_top");
		/*asm("lla t0, _bss_start");
		asm("lla t1, _bss_end");
		asm("0: bgeu t0, t1, 1f");
		asm("sb zero, (t0)");
		asm("addi t0, t0, 1");
		asm("j 0b");
		asm("1: ");*/
		//asm("tail kmain");
		//uart_init(UART_ADDR);
		//uart_putc(UART_ADDR, 'H');
		kmain();
	}
}
