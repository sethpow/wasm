Calling C++ functions with JavaScript

use a tool called:
    - embind
        - part of emscripten toolchain
        - allows for C++ functions to be called from JS
        - uses the --bind option when calling emcc
        - mainly for C++11 and C++14 (17 & 20 not supported yet)