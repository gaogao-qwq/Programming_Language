all:
	emcc wrapping.c -o wrapping.out.js -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=[ccall,cwrap]

clean:
	rm wrapping.out.js wrapping.out.wasm
