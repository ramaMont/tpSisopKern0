# build an executable named kern0 from kern0.c and boot.S
all: kern0.c 
	gcc -g -m32 -O1 -c kern0.c boot.S
	ld -m elf_i386 -Ttext 0x100000 kern0.o boot.o -o kern0

clean: 
	$(RM) myprog
