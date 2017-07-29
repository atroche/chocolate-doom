# microdoom

An extremely WIP fork of [chocolate-doom](https://github.com/chocolate-doom/chocolate-doom/) which:

* uses CMake instead of autotools
* doesn't split the application up into static libraries
* uses the SDL2 branch of chocolate-doom
* uses IWYU (“Include What You Use”) to keep headers sane
* uses clang-format with --style=llvm
* removes:
  * Windows support
  * Strife / Hexen / Heretic etc. support
  * Old soundcard emulation code
  * The terminal-based setup GUI
  * A couple of external dependencies
  * DeHackEd
  * a lot of legacy systems support in general

* amibitions:
  * have it run in the browser, with hyperlinks between WADs
  * Doom + WebVR
  * automated testing

## Building

Native build (only tested on OSX, should be fine on Linux):
```
mkdir build
cd build
cmake ..
make
./microdoom
```

WebAsembley build:

Install emscripten

Good guides from [WebAssembly.org](http://webassembly.org/getting-started/developers-guide/) and [emscripten.org](https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html).

Download and build SDL2_mixer using emscripten

```
wget https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.1.tar.gz
tar xf SDL2_mixer-2.0.1.tar.gz
cd SDL2_mixer-2.0.1.tar.gz
cp build/.libs/libSDL2_mixer.a /usr/local/lib/libSDL2_mixer_wasm.a
```

I appended WASM on the end of the libSDL2_mixer_wasm.a so that it doesn't wipe you (ptentially) installed SDL2_mixer.

Now from the root of the microdoom folder, run:

```
mkdir wasm-build
emcmake cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo -DEMSCRIPTEN
emmake make VERBOSE=1
wget http://doomgod.com/wads/iwads/doom2.7z
xz x doom2.7z

```

Now run this:

```
emrun --no_browser --port 8080 microdoom.html
```

And visit [this link](http://localhost:8080/microdoom.html).



