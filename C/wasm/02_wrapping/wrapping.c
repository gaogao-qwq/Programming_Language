#include <stdio.h>
#include <emscripten.h>

int EMSCRIPTEN_KEEPALIVE addNums(int a, int b) {
	return a + b;
}

int EMSCRIPTEN_KEEPALIVE subtractNums(int a, int b) {
	return a - b;
}

int EMSCRIPTEN_KEEPALIVE main() {
	printf("Hello, World!%d\n", addNums(3, 5));
	return 0;
}
