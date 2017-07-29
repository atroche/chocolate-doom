# microdoom

An extremely WIP fork of [chocolate-doom](https://github.com/chocolate-doom/chocolate-doom/) which aims to keep stripping back features until mere mortals like myself can understand what's going on.

I am to be highly responsive to any and all queries via GitHub Issue, and promise to code review and pull requests :)

## Differences to Chocolate Doom

* uses CMake instead of autotools
* uses the SDL2 branch of chocolate-doom
* uses [IWYU](https://include-what-you-use.org/) (“Include What You Use”) to keep headers sane
* uses clang-format with --style=llvm
* doesn't split the application up into static libraries
* removes:
  * Windows support
  * Strife / Hexen / Heretic etc. support
  * Old soundcard emulation code
  * The terminal-based setup GUI
  * The C libraries bundled by default in chocolate-doom
  * DeHackEd 
  * other legacy system support

* amibitions:
  * have it run in the browser, with hyperlinks between levels and WADs
    * The WorldWideWad: The Information Superhighway to Hell
  * Doom + WebVR
  * automated integration testing so these radical changes don't break everything
  * remove even more legacy-compatibility stuff!
  * enable JavaScript (and ClojureScript!) scripting
  * have other people besides me working on this :D

## Building

### Native build 

Only tested on OSX, should be fine on Linux.

```
mkdir build
cd build
cmake ..
make
./microdoom
```

### WebAsembley build

#### Install emscripten

There are good guides at [WebAssembly.org](http://webassembly.org/getting-started/developers-guide/) and [emscripten.org](https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html).

#### Download and build SDL2_mixer using emscripten

```
wget https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.1.tar.gz
tar xf SDL2_mixer-2.0.1.tar.gz
cd SDL2_mixer-2.0.1
emconfigure ./configure --disable-shared --enable-static
make
cp build/.libs/libSDL2_mixer.a /usr/local/lib/libSDL2_mixer_wasm.a
```

I appended WASM on the end of the libSDL2_mixer_wasm.a so that it doesn't wipe your (potentially) installed SDL2_mixer.

If you don't like putting these funny files in your /usr/local/ directories, you can also do cleverer things around Emscripten's linking search paths, but I feel that's outside the scope of this readme.

#### Compiling mindoom with Emscripten settings

Now, from the root of the repo you cloned (microdoom):

```
mkdir wasm-build
cd wasm-build
emcmake cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo -DEMSCRIPTEN
emmake make VERBOSE=1
wget http://doomgod.com/wads/iwads/doom2.7z
xz x doom2.7z
```

#### Running

Now run this:

```
emrun --no_browser --port 8080 microdoom.html
```

And visit [this link](http://localhost:8080/microdoom.html). You might want to open a developer terminal first to see more loggging / stacktraces.

Be warned that with some of my messing around I've managed to complete crash the chrome tab. Something to do with block threads, it seems?


