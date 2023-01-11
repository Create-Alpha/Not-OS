#ifndef __NOTOS__GDT_H
#define __NOTOS__GDT_H

#include "common/types.h"

namespace NotOS {

    class GlobalDescriptorTable
    {
        public:

            class SegmentDescriptor
            {
                private:
                    NotOS::common::uint16_t limit_lo;
                    NotOS::common::uint16_t base_lo;
                    NotOS::common::uint8_t base_hi;
                    NotOS::common::uint8_t type;
                    NotOS::common::uint8_t limit_hi;
                    NotOS::common::uint8_t base_vhi;

                public:
                    SegmentDescriptor(NotOS::common::uint32_t base, NotOS::common::uint32_t limit, NotOS::common::uint8_t type);
                    NotOS::common::uint32_t Base();
                    NotOS::common::uint32_t Limit();
            } __attribute__((packed));

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;

        public:

            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            NotOS::common::uint16_t CodeSegmentSelector();
            NotOS::common::uint16_t DataSegmentSelector();
    };
}

#endif
