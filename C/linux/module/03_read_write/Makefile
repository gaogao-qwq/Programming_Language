obj-m += read_write.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	insmod read_write.ko

uninstall:
	rmmod read_write
