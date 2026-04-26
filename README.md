## Overview

This project appears to be a simple command-line based dinosaur game, likely inspired by the classic game "Dino Chrome Dinosaur Game". The source code is written in C and utilizes platform-specific build configurations for Linux, Windows, Wine (for running on Windows on Linux), WebAssembly, and a custom build system.

## Features

- Command-line interface
- Basic game mechanics similar to the classic dinosaur game
- Platform-specific build support
- Use of `Makefile` for project building across different environments

## Project Structure

The project directory is organized as follows:

```
<Project>/
├── src/                # Source code directory containing C files
│   ├── Main.c          # Entry point of the program
│   └── Settings.h      # Header file containing global settings and typedefs
├── Makefile.linux      # Linux build configuration
├── Makefile.windows    # Windows build configuration
├── Makefile.wine       # Wine cross-compile build configuration for Windows on Linux
├── Makefile.web        # Emscripten WebAssembly build configuration
└── README.md           # This file
```

## Prerequisites

- C/C++ Compiler (GCC or Clang)
- Make utility
- Standard development tools
- Libraries needed in specific projects (none explicitly listed)

## Build & Run

### Linux

To build and run the project on Linux:

```sh
cd <Project>
make -f Makefile.linux all
make -f Makefile.linux exe
```

### Windows

To build and run the project on Windows, you can use either MSYS2 or a native Windows environment.

#### Using MSYS2

1. Install MSYS2 from [msys2.org](https://www.msys2.org/).
2. Open the MSYS2 shell.
3. Navigate to your project directory.
4. Run:

    ```sh
    make -f Makefile.windows all
    make -f Makefile.windows exe
    ```

#### Using a Native Windows Environment

1. Ensure you have MinGW installed with GCC and other necessary tools.
2. Open the MinGW command prompt or PowerShell.
3. Navigate to your project directory.
4. Run:

    ```sh
    make -f Makefile.windows all
    make -f Makefile.windows exe
    ```

### Wine (Windows on Linux)

To build and run the project using Wine on a Linux system:

1. Install Wine if not already installed:
    ```sh
    sudo apt-get install wine64
    ```
2. Navigate to your project directory.
3. Run:

    ```sh
    make -f Makefile.wine alldebug
    WINEPREFIX=~/wine64 WINEARCH=win64 wine $(TARGET)
    ```

### WebAssembly (Emscripten)

To build and run the project as WebAssembly using Emscripten:

1. Install Emscripten following the instructions on [emscripten.org](https://emscripten.org/docs/getting_started/downloads.html).
2. Navigate to your project directory.
3. Run:

    ```sh
    make -f Makefile.web all
    wasmtime $(TARGET)
    ```

These steps should allow you to build and run the project across different environments as specified by the platform-specific `Makefile` configurations.