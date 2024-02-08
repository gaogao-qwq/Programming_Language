#include <emscripten/em_macros.h>
#include <stdlib.h>

int main(void) {
	return 0;
}

int EMSCRIPTEN_KEEPALIVE accumulate(int *arr, int n) {
	int sum = 0;
	while (n) {
		sum += arr[--n];
	}
	return sum;
}

const char *EMSCRIPTEN_KEEPALIVE getString() {
	return "Hello, wasm!";
}

void *EMSCRIPTEN_KEEPALIVE wasmmalloc(size_t size) {
	return malloc(size);
}

void EMSCRIPTEN_KEEPALIVE wasmfree(void *ptr) {
	free(ptr);
}
