all:

helloworld: helloworld.asm
		nasm -t helloworld.asm
		ld -m elf_i386 -s -o helloworld helloworld.o