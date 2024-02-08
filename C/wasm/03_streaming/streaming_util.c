#include <emscripten/em_macros.h>

int EMSCRIPTEN_KEEPALIVE add(int a, int b) {
	return a + b;
}

int EMSCRIPTEN_KEEPALIVE sub(int a, int b) {
	return a - b;
}

int EMSCRIPTEN_KEEPALIVE mul(int a, int b) {
	return a * b;
}

int EMSCRIPTEN_KEEPALIVE div(int a, int b) {
	return a / b;
}

