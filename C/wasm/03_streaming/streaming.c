#include <emscripten/em_macros.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int EMSCRIPTEN_KEEPALIVE sumOfNInts(int n) {
	// return n * (n + 1) / 2;
	return div(mul(n, add(n, 1)), 2);
}
