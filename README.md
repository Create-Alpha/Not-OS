# NotOS-Real
A simple system using asm &amp; c++

## How to install (VirtualBox)
First, install **VirtualBox**.

Next, get **.iso file** (Releases or build yourself)

Create a new virtual machine in vbox, change its type to **Other/Unknown**.

Then rename it to **"NotOS"**. Set the **dvd storage** to the .iso file.

Run it. If it works, you may see something like these:

```
NotOS v0.7.0-alpha
Hello, World!   From NoFun
__________________________
(c) 2023 Create Alpha Tech
   
Initalizing Hardware, Stage 1.. 2.. 3
```

## How to build
Need: **Linux with git, g++, make, binutils, grub2, and xorriso**.

Enter this to install them: `sudo apt-get install g++ make binutils xorriso grub2-common git`

Then clone project: `git clone git@github.com:kklsuid/NotOS-Real.git`

If you're ready, change to project's dir, and enter this to build a .iso file.

`make mykernel.iso`

Or you want a .bin file, enter

`make mykernel.bin`
