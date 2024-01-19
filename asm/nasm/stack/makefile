AS = nasm
LD = ld
ASFLAGS = -f elf64
TARGET = stack.bin
SRC = stack.asm
OBJ = $(SRC:.asm=.o)

$(TARGET): $(OBJ)
	$(LD) -o $(TARGET) $(OBJ)

%.o: %.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
