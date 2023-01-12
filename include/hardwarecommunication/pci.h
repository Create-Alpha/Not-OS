#ifndef __NOTOS__HARDWARECOMMUNICATION__PCI_H
#define __NOTOS__HARDWARECOMMUNICATION__PCI_H

#include <hardwarecommunication/port.h>
#include <common/types.h>
#include <drivers/driver.h>
#include <hardwarecommunication/interrupts.h>



namespace NotOS
{
    namespace hardwarecommunication
    {
        enum BaseAddressRegisterType
        {
            MemoryMapping = 0,
            InputOutput = 1
        };

        class BaseAddressRegister
        {
        public:
            bool prefetchable;
            NotOS::common::uint8_t* address;
            NotOS::common::uint32_t size;
            BaseAddressRegisterType type;

        };

        class PCIDeviceDescriptor
        {
        public:
            NotOS::common::uint32_t portBase;
            NotOS::common::uint32_t interrupt;

            NotOS::common::uint16_t bus;
            NotOS::common::uint16_t device;
            NotOS::common::uint16_t function;

            NotOS::common::uint16_t vendor_id;
            NotOS::common::uint16_t device_id;

            NotOS::common::uint8_t class_id;
            NotOS::common::uint8_t subclass_id;
            NotOS::common::uint8_t interface_id;

            NotOS::common::uint8_t revision;

            PCIDeviceDescriptor();
            ~PCIDeviceDescriptor();
        };

        class PCIController
        {
            Port32Bit dataPort;
            Port32Bit commandPort;
        public:
            PCIController();
            ~PCIController();

            NotOS::common::uint32_t Read(NotOS::common::uint16_t bus, NotOS::common::uint16_t device, NotOS::common::uint16_t function, NotOS::common::uint32_t registeroffset);
            void Write(NotOS::common::uint16_t bus, NotOS::common::uint16_t device, NotOS::common::uint16_t function, NotOS::common::uint32_t registeroffset, NotOS::common::uint32_t value);
            bool DeviceHasFunctions(NotOS::common::uint16_t bus, NotOS::common::uint16_t device);
            void SelectDrivers(NotOS::drivers::DriverManager* driverManager, NotOS::hardwarecommunication::InterruptManager* interrupts);
            NotOS::drivers::Driver* GetDriver(PCIDeviceDescriptor dev, NotOS::hardwarecommunication::InterruptManager* interrupts);

            PCIDeviceDescriptor GetDeviceDescriptor(NotOS::common::uint16_t bus, NotOS::common::uint16_t device, NotOS::common::uint16_t function);
            BaseAddressRegister GetBaseAddressRegister(NotOS::common::uint16_t bus, NotOS::common::uint16_t device, NotOS::common::uint16_t function, NotOS::common::uint16_t bar);
        };
    }
}



#endif
