
#include "keyboard.h"

KeyboardEventHandler::KeyboardEventHandler()
{

}

void KeyboardEventHandler::OnKeyDown(char)
{

}

void KeyboardEventHandler::OnKeyUp(char)
{

}


KeyboardDriver::KeyboardDriver(InterruptManager* manager, KeyboardEventHandler *handler)
: InterruptHandler(0x21, manager),
dataport(0x60),
commandport(0x64)
{
    this->HandleInterrupt //FIXME 27:54 Lesson 8
}

KeyboardDriver::~KeyboardDriver()
{

}

void printf(char*);

void printfHex(uint8_t);

void KeyboardDriver::Activate()
{
    while(commandport.Read() & 0x1)
        dataport.Read();
    commandport.Write(0xAE); // Activate interrupts
    commandport.Write(0x20); // Get current state
    uint8_t status = (dataport.Read() | 1) & ~0x10;
    commandport.Write(0x60); // Set state
    dataport.Write(status);

    dataport.Write(0xF4);
}

uint32_t KeyboardDriver::HandleInterrupt(uint32_t esp)
{
    uint8_t key = dataport.Read();

    switch(key)
    {
        case 0x02: printf("1"); break;
        case 0x03: printf("2"); break;
        case 0x04: printf("3"); break;
        case 0x05: printf("4"); break;
        case 0x06: printf("5"); break;
        case 0x07: printf("6"); break;
        case 0x08: printf("7"); break;
        case 0x09: printf("8"); break;
        case 0x0A: printf("9"); break;
        case 0x0B: printf("0"); break;

        case 0x10: printf("q"); break;
        case 0x11: printf("w"); break;
        case 0x12: printf("e"); break;
        case 0x13: printf("r"); break;
        case 0x14: printf("t"); break;
        case 0x15: printf("y"); break;
        case 0x16: printf("u"); break;
        case 0x17: printf("i"); break;
        case 0x18: printf("o"); break;
        case 0x19: printf("p"); break;

        case 0x1E: printf("a"); break;
        case 0x1F: printf("s"); break;
        case 0x20: printf("d"); break;
        case 0x21: printf("f"); break;
        case 0x22: printf("g"); break;
        case 0x23: printf("h"); break;
        case 0x24: printf("j"); break;
        case 0x25: printf("k"); break;
        case 0x26: printf("l"); break;

        case 0x2C: printf("z"); break;
        case 0x2D: printf("x"); break;
        case 0x2E: printf("c"); break;
        case 0x2F: printf("v"); break;
        case 0x30: printf("b"); break;
        case 0x31: printf("n"); break;
        case 0x32: printf("m"); break;
        case 0x33: printf(","); break;
        case 0x34: printf("."); break;
        case 0x35: printf("-"); break;

        case 0x1C: printf("\n"); break;
        case 0x39: printf(" "); break;

        //ignored
        case 0x45: //NumLock
            break;

        default:
        {
            if(key < 0x80)
            {
                printf("KEYBOARD 0x");
                printfHex(key);
            }
            break;

        }
    }
    return esp;
}