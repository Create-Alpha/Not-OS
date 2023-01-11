
#ifndef __NOTOS__DRIVERS__KEYBOARD_H
#define __NOTOS__DRIVERS__KEYBOARD_H

#include <common/types.h>
#include <drivers/driver.h>
#include <hardwarecommunication/interrupts.h>
#include <hardwarecommunication/port.h>

namespace NotOS
{

    namespace drivers
    {
        class KeyboardEventHandler
        {
        public:
            KeyboardEventHandler();

            virtual void OnKeyDown(char);
            virtual void OnKeyUp(char);
        };

        class KeyboardDriver : public NotOS::hardwarecommunication::InterruptHandler, public Driver
        {
            NotOS::hardwarecommunication::Port8Bit dataport;
            NotOS::hardwarecommunication::Port8Bit commandport;

            KeyboardEventHandler* handler;
        public:
            KeyboardDriver(NotOS::hardwarecommunication::InterruptManager* manager, KeyboardEventHandler *handler);
            ~KeyboardDriver();
            virtual NotOS::common::uint32_t HandleInterrupt(NotOS::common::uint32_t esp);
            virtual void Activate();
        };
    }
}

#endif
