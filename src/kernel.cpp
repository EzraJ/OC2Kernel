#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

uint8_t* UART_BASE = (uint8_t*)0x10000148;

void entry(){
	// set data size to 8 bits
	*((uint8_t*)0x10000151) = 0b11;
	*((uint8_t*)0x10000150) = 0b1;
	*((uint8_t*)0x10000149) = 0b1;

	*UART_BASE = 'T';

	while(true){

	}

}


void _start(){
	asm(".option push");
	asm(".option norelax");
	asm("la gp, _global_pointer");
	asm(".option pop");
	asm("la sp, _init_stack_top");
	entry();
}

