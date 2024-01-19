AS = nasm
LD = ld
ASFLAGS = -f elf64
TARGET = helloworld.bin
SRC = helloworld.asm
OBJ = $(SRC:.asm=.o)

$(TARGET): $(OBJ)
	$(LD) -o $(TARGET) $(OBJ)

%.o: %.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
