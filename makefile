
.SILENT:

PSPDEV=/home/groepaz/pspdev/bin

all:
	$(PSPDEV)/psp-gcc -Os -W -Wall -G0 -fno-pic -mno-abicalls -w -S main.c -o main.s
	$(PSPDEV)/psp-as main.s -o main.o
	$(PSPDEV)/psp-ld -T psp20bin.x main.o -o main.elf
	$(PSPDEV)/psp-strip -s main.elf
	$(PSPDEV)/psp-objcopy -O binary main.elf h.bin

clean:
	rm -rf *~ *.o *.elf *.bin *.s *.bin
 
