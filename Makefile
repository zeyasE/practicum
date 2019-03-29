all: count-sw.hex light-3.hex light-8.hex
%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

%.flash: %.hex
	avrdude -p atmega328p -c usbasp -U flash:w:$<

%.elf: %.o peri.o
	avr-gcc -mmcu=atmega328p -O2 -o $@ $^

%.o: %.c peri.h
	avr-gcc -mmcu=atmega328p -O2 -c -o $@ $<

clean:
	rm -f *~ *.o *.elf *.hex
