# Not OS

[![Last updated](https://img.shields.io/badge/dynamic/json?color=red&label=Last%20Updated&query=updated_at&url=https%3A%2F%2Fapi.github.com%2Frepos%2FCreate-Alpha%2FNot-OS)](https://github.com/Create-Alpha/Not-OS/releases/latest)

A simple system using asm &amp; c++

## How to install (VirtualBox)

First, install **VirtualBox**.

Next, get **.iso file** (Releases or build yourself)

Create a new virtual machine in vbox, change its type to **Other/Unknown**.

Then rename it to **"NotOS"**. Set the **dvd storage** to the .iso file.

Run it. If it works, you may see something like these:

```text
NotOS v0.7.0-alpha
Hello, World!   From NoFun
__________________________
(c) 2023 Create Alpha Tech
   
Initializing Hardware, Stage 1.. 2.. 3
```

## How to build

Need: **Linux with git, g++, make, binutils, grub2, and xorriso**.

Enter this to install them: `sudo apt-get install g++ make binutils xorriso grub2-common git`

Then clone project: `git clone git@github.com:kklsuid/NotOS-Real.git`

If you're ready, change to project's dir, and enter this to build a .iso file.

`make mykernel.iso`

Or you want a .bin file, enter

`make mykernel.bin`
