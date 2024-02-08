var memory = new WebAssembly.Memory({
  initial: 256,
  maximum: 512
});

var exports;
WebAssembly.instantiateStreaming(
  fetch("malloc.out.wasm"), {
    js: {
      mem: memory
    },
    env: {
      emscripten_resize_heap: memory.grow
    }
  },
).then(results => {
  exports = results.instance.exports;
  memory = results.instance.exports.memory;
});

function run_wasm() {
  var arr = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20];
  var ptr = encodeArray(arr, 10, 4);
  var sum = exports.accumulate(ptr, 10);
  exports.wasmfree(ptr);
  document.querySelector("#ret").innerHTML += `${sum}<br>`;
}

function get_string() {
  var str = decodeString(exports.getString());
  console.log(str);
  navigator.clipboard.writeText(str);
}

function encodeArray(arr, len, sizeof = 1) {
  var ptr;
  var out;
  if (sizeof == 8) {
    ptr = exports.wasmmalloc(len * 8);
    out = new BigUint64Array(memory.buffer, ptr);
  } else if (sizeof == 4) {
    ptr = exports.wasmmalloc(len * 4);
    out = new Uint32Array(memory.buffer, ptr);
  } else {
    ptr = exports.wasmmalloc(len);
    out = new Uint8Array(memory.buffer, ptr);
  }

  for (var i = 0; i < len; i++) {
    out[i] = arr[i];
  }
  return ptr;
}

function decodeArray(ptr, len) {
  return new Uint8Array(memory.buffer).slice(ptr, ptr + len);
}

function decodeString(ptr, len) {
  return new TextDecoder("utf8").decode(decodeArray(ptr, len));
}

function decodeString(ptr) {
  var bytes = new Uint8Array(memory.buffer, ptr);
  var strlen = 0;
  while (bytes[strlen] != 0) strlen++;
  return new TextDecoder("utf8").decode(bytes.slice(0, strlen));
}
