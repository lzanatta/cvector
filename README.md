# cvector
A simple vector implementation for the C language.

## Building shared lib and examples 

**Work in progress**

Using `make` (or `mingw32-make` on Windows with MinGW-w64):

### Release builds:

```
build_folders make && make
```

Builds the `test_static` example.

### Debug builds:

```
build_folders make && make debug
```

Builds `test_static_debug` if you need to debug something.

Configuration files for working with Visual Studio Code (compiling, debugging, code completion) are also available.

Currently developed and tested on Windows 10 using MinGW-w64 (gcc 8.1.0 x86_64-posix-seh-rev0) only.

## License

[MIT](LICENSE)
