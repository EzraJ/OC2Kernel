CC=riscv64-linux-gnu-g++-10
LD=riscv64-linux-gnu-ld
OBJC = riscv64-unknown-elf-objcopy
LDOPTIONS= -nostdlib -L/usr/lib/gcc-cross/riscv64-linux-gnu/10/ -lgcc
CCOPTIONS= -ffreestanding -Wall -Wextra -I./include/
ODIR = obj
SDIR = ./src
FILES = $(shell find $(SDIR) -type f -name "*.cpp" -printf "%p ")

build:
	$(MAKE) makeObjects
	$(MAKE) linkObjects
	$(MAKE) objCopy

makeObjects:
	$(CC) $(FILES) $(CCOPTIONS)

linkObjects:

	$(LD) -T ./src/script.ld $(LDOPTIONS) $(shell find ./ -type f -name "*.o" -printf "%p ") -o ezraos.bin

objCopy:
	$(OBJC) -O binary ezraos.bin output.bin

.PHONY: clean

clean:
	rm output.bin ezraos.bin
