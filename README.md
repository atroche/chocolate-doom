# microdoom

An extremely WIP fork of [chocolate-doom](https://github.com/chocolate-doom/chocolate-doom/) which:

* uses CMake instead of autotools
* doesn't split the application up into static libraries
* uses the SDL2 branch of chocolate-doom
* removes:
  * Windows support
  * Strife / Hexen / Heretic etc. support
  * Old soundcard emulation code
  * The terminal-based setup GUI
  * A couple of external dependencies
  * DeHackEd
  * a lot of legacy systems support in general

## Running it

```
mkdir build
cd build
cmake ..
make
./microdoom
```

