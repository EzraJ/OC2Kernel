CC=riscv64-linux-gnu-g++-10
LD=riscv64-linux-gnu-ld
OBJC = riscv64-unknown-elf-objcopy
LDOPTIONS= -ffreestanding -O2 -nostdlib -shared -L/usr/lib/gcc-cross/riscv64-linux-gnu/10/ -gcc
CCOPTIONS= -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -I./include/
ODIR = obj
SDIR = ./src
FILES = $(shell find $(SDIR) -type f -name "*.cpp" -printf "%p ")





makeObjects:
	$(CC) -c $(FILES) $(CCOPTIONS)

linkObjects:

	$(LD) -T ./src/script.ld -O ezraos.bin $(LDOPTIONS) $(shell find ./ -type f -name "*.o" -printf "% p")
	rm -f $(shell find ./ -type f -name "*.o" -printf "% p")

objCopy:
	$(OBJC) -O binary ezraos.bin output.bin

test:
	echo $(FILES)