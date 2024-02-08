#include <emscripten/em_macros.h>

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
