# Code and basic functions




The program written in C language aims to find the shortest path🛤 between two points in the map of University of Leeds campus🏫. The  program can calculate the length of the shortest route and locations  along the route after the user enters the ids of two locations🏟. With  the help of the gnuplot command script provided and gnuplot  software📃data visualization graph of the original path and calculated  path will be shown. There will be corresponding error message when  there are data file error, illegal input.

# Environment
GCC 8.1.0<br/>
Cmake 2.8.12

# Directions for use
## Linux
under project2 folder
```
mkdir build
```


```
cd build
```


```
cmake ..
```


```
make
```

move the Final_Map.map into the build folder


```
./project2
```

```
./unitTest
```

move the plot.plt into the build folder, open it with gnuplot

## Windows
Generate executable files with the help of **Cmake**

# Code directory structure
project2:
│  CMakeLists.txt</br>
│  Final_Map.map</br>
│  plot.plt</br>
│  README.md</br>
│  </br>
├─include</br>
│      adjList.h</br>
│      global.h</br>
│      interface.h</br>
│      </br>
├─src</br>
│      adjList.c</br>
│      interface.c</br>
│      main.c</br>
│      </br>
└─unitTest</br>
    │  unity.c</br>
    │  unity.h</br>
    │  unity_internals.h</br>
    │  unit_tests.c</br>
    │  </br>
    └─unity</br>

This project contains four parts, **header files** are in the **include** folder, which consists of declaration of variables and functions. global.h is used for macro definition in the program, adjList.h is for the processing of the file and data structure, interface.h is the interface of the program. The **src** folder is the **source file**. <br/>
The complication and run of the program involves in multiple files, and the **CMakeList.txt** will be helpful for the compiling instead of manually compiling. 

# Version control
- 4.21</br>
  basic functions</br>
- 5.2</br>
  add unit test</br>
- 5.3</br>
  handling of isolated points</br>
- 5.4</br>
  const and static modifiers</br>
- 5.5</br>
  mouse hover display id</br>
- 5.6</br>
  add README file</br>

# Copyright
Copyright © 2021 Bamboo. All rights reserved.

# Reference
XJCO1921 Programming Project, University of Leeds

# Project leader
bambooliulala@gmail.com

# Git repository url
https://github.com/Isabella156/coursework2
# Commit history
![avatar](https://i.niupic.com/images/2021/05/06/9h5J.png)</br>
Everyone is welcome to contact me to submit a bug post🤪, although most of the time I am busy with my homework👨‍💻