# DuneMaps - Scenario Editor for Dune II

**Forked from:**<br/>
https://sourceforge.net/projects/dunemaps/

## Screenshot

![Screenshot](https://github.com/fonic/dunemaps/raw/master/res/screenshot.png)

## Requirements

**Operating system:**
- Linux

**Build system:**
- [CMake](https://cmake.org/)

**Compiler:**
- [GCC](https://gcc.gnu.org/) (well tested)
- [Clang](https://llvm.org/) (less tested)

**Libraries:**
- [SDL (aka libsdl)](https://libsdl.org/)
- [wxWidgets (part of wxGTK)](https://wxwidgets.org/)


## Download Sources

Refer to the [releases](https://github.com/fonic/dunemaps/releases) section for downloads links.


## Build Sources

After downloading and extracting the release archive, run the following commands:
```
# cd dunemaps-rXX
# mkdir build
# cd build
# cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../install ..
# make
# make install
```

**NOTE:** Please use a `debug` build to report issues (provides useful debug output):
```
# ...
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../install ..
# ...
```


## Copy Game Data

_DuneMaps_ requires the following data files from _Dune II (US/EU v1.07)_:
- `DUNE2.EXE`
- `DUNE.PAK`
- `ENGLISH.PAK`
- `SCENARIO.PAK`

These files need to be stored in folder `data` alongside the `dunemaps` executable:
```
# cd dunemaps-rXX
# mkdir install/bin/data
# cp <source-path>/{DUNE2.EXE,DUNE.PAK,ENGLISH.PAK,SCENARIO.PAK} install/bin/data
```


## Run DuneMaps

Use the following commands to run _DuneMaps_:
```
# cd dunemaps-rXX
# cd install/bin
# ./dunemaps
```

## Current State / Future Plans

**Current state:**
- Compiles on both _GCC_ and _Clang_ without errors and/or severe warnings
- Works mostly fine (with some minor graphical glitches)
- Fixed countless memory leaks and crashes
- Fixed several obvious bugs (e.g. non-working _CHOAM_ dialog)
- Fixed several severe compiler warnings
- Improved scenario INI output (e.g. header comment, section spacing)
- Added useful debug features (e.g. console output, address sanitizer)
- Improved source files (e.g. added header guards, normalized line endings)
- Improved project structure (e.g. normalized files/folder names)

**Future plans:**
- Improve GUI (e.g. fix graphical glitches, correct spelling, rework dialogs)
- Improve scenario INI output to more closely match original _Dune II_ format
- Add workarounds for malformed scenario INIs (e.g. `MaxUnits` vs. `MaxUnit`)
- Add support for OSes other than Linux (PRs are welcome!)


## Original README

These are the contents of the original `README` provided by the original author (slightly reformatted):
```
DuneMaps
--------

About
-----

DuneMaps is a scenario editor for Dune II, allowing editing of existing maps,
or creation of new maps.

Required
--------

Certain files are required for execution of the editor. These files are to be
placed in the data folder, located inside the installation directory.

Only specific versions of DUNE2.EXE are supported, these include 
Dune2 v1.07 Battle of Arrakis, and Building of a Dynasty.

DUNE.PAK, SCENARIO.PAK, ENGLISH.PAK, DUNE2.EXE

Features
--------

 * Create new scenario, viewing the map as you change the seed
 * Opening scenarios directly from .PAK files
 * Edit all sections of a scenario.ini
 * Minimap for terrain overview
 * Add structures and Units
 * Zoom in and out with mouse scroll wheel
 * Loading Amiga scenario.ini
  
Controls
--------

 * Right click on units / structures / terrain for various options
 * Scroll the map by placing cursor around the edge 

Saving
------

The scenario starting screen position, and starting selected structure is
saved based on the current editor view/selected structure.

At present only saving in PC INI format is supported.
```

<br/>_Last updated: 02/01/22_
