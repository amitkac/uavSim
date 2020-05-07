# UAV Motion Simulator 

[![License](https://poser.pugx.org/ali-irawan/xtra/license.svg)](https://poser.pugx.org/ali-irawan/xtra/license.svg)
<img src= "img/C-blue.svg">

This simulator is based on our work considering UAV motion in atmosphere. The Turbulence caused by wind gusts was modelled by very 
famous Dryden wind model. More details about this Dryden model can be found in https://en.wikipedia.org/wiki/Dryden_Wind_Turbulence_Model.


## Table of contents
* [General info](#general-info)
* [Prerequisites](#Prerequisites)
* [Setup](#setup)
* [Sample output](#sample-output)

## General info
This is a simple C++ programme that utilizes ```open source SDL library``` used for `games` to create the  UAV motion simulation 
under wind gusts. The wind gusts is modelled by Dryden wind motion. 
* Most importantly, you need to install `SDL2` and `SDL2_image` library before starting out.
* Also, you need to have `gcc` compiler.

	
## Prerequisites
The following packages are required:
* C: gcc compiler
* SDL2: https://www.libsdl.org/download-2.0.php
* SDL2_image: https://www.libsdl.org/projects/SDL_image/ 
* ROS log files in ```.csv``` format without empty columns (I still need to work better with the csvReader module)

	
## Setup
To run this project, download the repository to any folder. Open the folder and run the following main script from terminal/command line/ide:
```
$make
```

once done, run
```
$make cleanall
```

## Sample output

Here is an one instance of the map. Check all those big circles near the ocean side than the inland one.

<img src= "img/orig.gif" align='center'> 

These experiments were done in a lab on a robotic arm which emulated the UAV motion under wind gusts.





