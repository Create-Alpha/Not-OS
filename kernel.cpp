
#include "types.h"
#include "gdt.h"
#include "interrupts.h"
#include "driver.h"
#include "keyboard.h"
#include "mouse.h"

// lesson 8 - learning


// print something to screen
void printf(char* str)
{
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    static uint8_t x=0,y=0;

    for(int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n':
                x = 0;
                y++;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }

        if(x >= 80)
        {
            x = 0;
            y++;
        }

        if(y >= 25)
        {
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}

void printfHex(uint8_t key)
{
    char* foo = "00";
    char* hex = "0123456789ABCDEF";
    foo[1] = hex[(key >> 4) & 0x0F];
    foo[2] = hex[key & 0x0F];
    printf(foo);
}



typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}


// Main of all the system.
extern "C" void kernelMain(const void* multiboot_structure, uint32_t /*multiboot_magic*/)
{
    printf("NotOS v0.1.6b\n");
    printf("Hello, World!   From NoFun\n");
    printf("__________________________\n");
    printf("(c) 2023 Create Alpha Tech\n\n");

    GlobalDescriptorTable gdt;
    InterruptManager interrupts(&gdt);

    printf("Initalizing Hardware, Stage 1");

    DriverManager drvManager;  // Setting up drivers

        KeyboardDriver keyboard(&interrupts);
        drvManager.AddDriver(&keyboard);

        MouseDriver mouse(&interrupts);
        drvManager.AddDriver(&mouse);

        printf(".. 2");

        drvManager.ActivateAll();

    printf(".. 3\n");
    interrupts.Activate();

    while(1);
}
