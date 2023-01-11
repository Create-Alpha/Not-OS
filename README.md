# NotOS-Real
A simple system using asm &amp; c++

## How to install (VirtualBox)
First, install VirtualBox.

Create a new virtual machine, change its type to Other/Other.

Then rename it to "NotOS".

## How to build
Need: Linux with g++, make, binutils, and xorriso.

Enter this to install them: `sudo apt-get install g++ make binutils xorriso`

Clone project: `git clone git@github.com:kklsuid/NotOS-Real.git`

If you're ready, change to project's dir, and enter this to build a .iso file.

`make build`

Or you want a .bin file, enter

`make mykernel.bin`
