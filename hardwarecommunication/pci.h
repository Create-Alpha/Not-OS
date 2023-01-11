#ifndef __NOTOS__HARDWARECOMMUNICATION__PCI_H
#define __NOTOS__HARDWARECOMMUNICATION__PCI_H

#include "port.h"
#include "../common/types.h"
#include "../drivers/driver.h"
#include "interrupts.h"


namespace NotOS
{
    namespace hardwarecommunication
    {
        class PCIDeviceDescriptor
        {
        public:
            common::uint32_t portBase;
            common::uint32_t interrupt;

            common::uint16_t bus;
            common::uint16_t device;
            common::uint16_t function;

            common::uint16_t vendor_id;
            common::uint16_t device_id;

            common::uint8_t class_id;
            common::uint8_t subclass_id;
            common::uint8_t interface_id;

            common::uint8_t revision;

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

            common::uint32_t Read(common::uint16_t bus, common::uint16_t device, common::uint16_t function, common::uint32_t registeroffset);
            void Write(common::uint16_t bus, common::uint16_t device, common::uint16_t function, common::uint32_t registeroffset, common::uint32_t value);
            bool DeviceHasFunctions(common::uint16_t bus, common::uint16_t device);
            void SelectDrivers(NotOS::drivers::DriverManager* driverManager);

            PCIDeviceDescriptor GetDeviceDescriptor(common::uint16_t bus, common::uint16_t device, common::uint16_t function);
        };
    }
}



#endif
