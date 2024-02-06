#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int dev = open("/dev/device_number_module", O_RDONLY);
	if (dev == -1) {
		printf("Device opening failed.\n");
		return dev;
	}
	printf("Device opening successed.");
	close(dev);
	return 0;
}
