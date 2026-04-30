# TrussCalculator

A 2D truss structure analysis application built with C++ and Qt. It provides an interactive graphical interface for defining truss systems (nodes, rods, bearings, forces) and solves them using the Finite Element Method (FEM) with the Eigen linear algebra library.

## Author

Written by [bernhard1536](https://github.com/bernhard1536), originally developed around 2018-2019.

## Features

- Interactive graphical editor for placing nodes, rods, bearings, and forces
- FEM solver: assembles element/global stiffness matrices and solves K*U = F
- Visualization of inner forces with color-mapped rods
- Deformed system overlay
- Support types: locating bearing, floating bearing, fixed clamping
- Rod and rope (cable) elements
- Dimension and label annotations
- Save/load projects as JSON
- Print support

## Building

### Prerequisites

- C++14 compiler (GCC, Clang, or MSVC)
- Qt 5 (tested with Qt 5.15; Qt 5.6+ should work)
  - Modules: Core, GUI, Widgets, PrintSupport
- qmake
- Eigen is bundled in `libs/Eigen/` (no separate install needed)

### Linux

Install the Qt 5 development packages:

```bash
# Debian / Ubuntu
sudo apt install build-essential qt5-qmake qtbase5-dev libqt5printsupport5

# Fedora
sudo dnf install gcc-c++ make qt5-qtbase-devel

# Arch
sudo pacman -S base-devel qt5-base
```

Build:

```bash
mkdir -p builds && cd builds
qmake ../TrussCalculator.pro
make -j$(nproc)
```

Run:

```bash
./TrussCalculator
```

### Windows

#### Option A: Qt Creator (recommended)

1. Install [Qt](https://www.qt.io/download-qt-installer) with Qt 5.15 and MinGW or MSVC kit
2. Open `TrussCalculator.pro` in Qt Creator
3. Configure the project with your kit and click Build/Run

#### Option B: Command line with MSVC

1. Install Qt 5 and add `qmake` to your PATH
2. Open a Developer Command Prompt for Visual Studio:

```cmd
mkdir builds && cd builds
qmake ..\TrussCalculator.pro -spec win32-msvc
nmake
```

#### Option C: Command line with MinGW

1. Install Qt 5 with MinGW and add both `qmake` and MinGW `bin/` to your PATH:

```cmd
mkdir builds && cd builds
qmake ..\TrussCalculator.pro -spec win32-g++
mingw32-make -j%NUMBER_OF_PROCESSORS%
```

## License

TrussCalculator is free software: you can redistribute it and/or modify it under the terms of the **GNU General Public License v3** (or, at your option, any later version) as published by the Free Software Foundation. See the [`LICENSE`](LICENSE) file for the full license text.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

Copyright (C) 2018-2019 [bernhard1536](https://github.com/bernhard1536).

### Third-party components

The bundled [Eigen](https://eigen.tuxfamily.org/) library in `libs/Eigen/` is distributed under its own terms (primarily MPL2, with some files under BSD or LGPL). See the license files inside `libs/Eigen/` for details.
