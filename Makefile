
CC = arm-none-eabi-gcc 
CC_PATH = gcc-arm-none-eabi-9-2020-q2-update/bin
LINKER = arm-none-eabi-ld 
CC_FLAGS = -c -g -mcpu=cortex-m0plus -mthumb -o
LINKER_FLAGS = -o 
BIN = bin
SRC = src


my_blink: startup.o main.o
	$(CC_PATH)/$(LINKER) -T$(SRC)/t_link.ld $(LINKER_FLAGS) $(BIN)/my_blink.elf $(BIN)/startup.o $(BIN)/main.o
	gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-objcopy -O ihex $(BIN)/my_blink.elf $(BIN)/my_blink.hex


main.o: $(SRC)/main.c
	$(CC_PATH)/$(CC) $(CC_FLAGS)  $(BIN)/main.o $(SRC)/main.c
	

startup.o : $(SRC)/startup.S
	$(CC_PATH)/$(CC) $(CC_FLAGS) $(BIN)/startup.o $(SRC)/startup.S
	

clean:
	rm -f $(BIN)/*

flash:
	teensy_loader_cli-master/teensy_loader_cli --mcu=mkl26z64 -w -v $(BIN)/my_blink.hex

