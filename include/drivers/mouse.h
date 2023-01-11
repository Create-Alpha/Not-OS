
#ifndef __NOTOS__DRIVERS__MOUSE_H
#define __NOTOS__DRIVERS__MOUSE_H

#include <common/types.h>
#include <drivers/driver.h>
#include <hardwarecommunication/interrupts.h>
#include <hardwarecommunication/port.h>

namespace NotOS
{

    namespace drivers
    {
        class MouseEventHandler
        {

        public:
            MouseEventHandler();

            virtual void OnActivate();
            virtual void OnMouseDown(NotOS::common::uint8_t button);
            virtual void OnMouseUp(NotOS::common::uint8_t button);
            virtual void OnMouseMove(int x, int y);
        };

        class MouseDriver : public NotOS::hardwarecommunication::InterruptHandler, public Driver
        {
            NotOS::hardwarecommunication::Port8Bit dataport;
            NotOS::hardwarecommunication::Port8Bit commandport;

            NotOS::common::uint8_t buffer[3];
            NotOS::common::uint8_t offset;
            NotOS::common::uint8_t buttons;

            MouseEventHandler* handler;

        public:
            MouseDriver(NotOS::hardwarecommunication::InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();
            virtual NotOS::common::uint32_t HandleInterrupt(NotOS::common::uint32_t esp);
            virtual void Activate();
        };
    }
}



#endif
