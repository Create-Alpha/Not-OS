
#ifndef __NOTOS__HARDWARECOMMUNICATION__INTERRUPTMANAGER_H
#define __NOTOS__HARDWARECOMMUNICATION__INTERRUPTMANAGER_H

#include <gdt.h>
#include <multitasking.h>
#include <common/types.h>
#include <hardwarecommunication/port.h>

namespace NotOS {
    namespace hardwarecommunication {
        class InterruptManager;

        class InterruptHandler
        {
        protected:
            NotOS::common::uint8_t InterruptNumber;
            InterruptManager* interruptManager;
            InterruptHandler(InterruptManager* interruptManager, NotOS::common::uint8_t InterruptNumber);
            ~InterruptHandler();
        public:
            virtual NotOS::common::uint32_t HandleInterrupt(NotOS::common::uint32_t esp);
        };


        class InterruptManager
        {
            friend class InterruptHandler;
            protected:

                static InterruptManager* ActiveInterruptManager;
                InterruptHandler* handlers[256];
                TaskManager *taskManager;

                struct GateDescriptor
                {
                    NotOS::common::uint16_t handlerAddressLowBits;
                    NotOS::common::uint16_t gdt_codeSegmentSelector;
                    NotOS::common::uint8_t reserved;
                    NotOS::common::uint8_t access;
                    NotOS::common::uint16_t handlerAddressHighBits;
                } __attribute__((packed));

                static GateDescriptor interruptDescriptorTable[256];

                struct InterruptDescriptorTablePointer
                {
                    NotOS::common::uint16_t size;
                    NotOS::common::uint32_t base;
                } __attribute__((packed));

                NotOS::common::uint16_t hardwareInterruptOffset;
                static void SetInterruptDescriptorTableEntry(
                    NotOS::common::uint8_t interrupt,
                    NotOS::common::uint16_t codeSegmentSelectorOffset,
                    void (*handler)(),
                    NotOS::common::uint8_t DescriptorPrivilegeLevel,
                    NotOS::common::uint8_t DescriptorType
                );


                static void InterruptIgnore();

                static void HandleInterruptRequest0x00();
                static void HandleInterruptRequest0x01();
                static void HandleInterruptRequest0x02();
                static void HandleInterruptRequest0x03();
                static void HandleInterruptRequest0x04();
                static void HandleInterruptRequest0x05();
                static void HandleInterruptRequest0x06();
                static void HandleInterruptRequest0x07();
                static void HandleInterruptRequest0x08();
                static void HandleInterruptRequest0x09();
                static void HandleInterruptRequest0x0A();
                static void HandleInterruptRequest0x0B();
                static void HandleInterruptRequest0x0C();
                static void HandleInterruptRequest0x0D();
                static void HandleInterruptRequest0x0E();
                static void HandleInterruptRequest0x0F();
                static void HandleInterruptRequest0x31();

                static void HandleException0x00();
                static void HandleException0x01();
                static void HandleException0x02();
                static void HandleException0x03();
                static void HandleException0x04();
                static void HandleException0x05();
                static void HandleException0x06();
                static void HandleException0x07();
                static void HandleException0x08();
                static void HandleException0x09();
                static void HandleException0x0A();
                static void HandleException0x0B();
                static void HandleException0x0C();
                static void HandleException0x0D();
                static void HandleException0x0E();
                static void HandleException0x0F();
                static void HandleException0x10();
                static void HandleException0x11();
                static void HandleException0x12();
                static void HandleException0x13();

                static NotOS::common::uint32_t HandleInterrupt(NotOS::common::uint8_t interrupt, NotOS::common::uint32_t esp);
                NotOS::common::uint32_t DoHandleInterrupt(NotOS::common::uint8_t interrupt, NotOS::common::uint32_t esp);

                Port8BitSlow programmableInterruptControllerMasterCommandPort;
                Port8BitSlow programmableInterruptControllerMasterDataPort;
                Port8BitSlow programmableInterruptControllerSlaveCommandPort;
                Port8BitSlow programmableInterruptControllerSlaveDataPort;

            public:
                InterruptManager(NotOS::common::uint16_t hardwareInterruptOffset, NotOS::GlobalDescriptorTable* globalDescriptorTable, NotOS::TaskManager* taskManager);
                ~InterruptManager();
                NotOS::common::uint16_t HardwareInterruptOffset();
                void Activate();
                void Deactivate();
        };
    }
}


#endif
