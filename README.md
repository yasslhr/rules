Rules
==============

### change the copyrigth user creator in the conf.py

Why
---
The c year project 2021-2022 by Nassim Daoud-Jonathan Filion-Yasin Lahrouri-Tom Lavergne-Aaron Randrianarisona-Yannis Rouhier

Usage
-----

### Installation

~~~bash
$ cd path of your project
$ cd docs
$ pip3 install -r requirements.txt
~~~


### Compilation

~~~bash
$ mkdir build
$ cd build
$ cmake ../ -DUSE_VALGRIND=1 -DRUN_CPPCHECK=1 -DCMAKE_INSTALL_PREFIX=~/.local 
$ make
~~~

### Build documentation

~~~bash
$ make docs
~~~

### Run test

~~~bash
$ make test
~~~

### Run rules.c
~~~bash
$ cd build/src/main
$ ./rules --rules path-of-your-file-rules \
$                  --facts path-of-your-file-facts \
$                  --output path-of-your-file-output 

~~~


-------------------------
