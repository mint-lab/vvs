## VVS: A Very Very Simple Unit Testing Tool for C/C++
_VVS_ aims to provide a very small and simple framework for unit testing in C and C++. It consists of a single header file, `vvs.h`, which only utilize C standard libraries. Just include the file to your project. It will work without complex configuration and dependency. VVS is [Beerware](http://en.wikipedia.org/wiki/Beerware) so that it is free to use and distribute.

* Homepage: <https://github.com/sunglok/vvs>

### File Description
* `vvs.h` includes all functions and definitions of VVS.
* `vvs_example.c` contains examples of using VVS.
* `README.md` is this file which describes basic introduction of VVS.
* `CMakeList.txt` is a [CMake](https://cmake.org/) script to build `vvs_example.c`.

### Running an Example
* In Microsoft Visual Studio, open a solution file, `msvs/vvs_example.sln`, and run the solution.
* In Linux and its neighbors, build `vvs_example.c` with `mkdir build && cd build && cmake .. && make`, and run it with `./vvs_example`

### License
* [Beerware](http://en.wikipedia.org/wiki/Beerware)

### Contact
* [Sunglok Choi](http://sites.google.com/site/sunglok/) (sunglok AT hanmail DOT net)
