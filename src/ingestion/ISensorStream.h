#pragma once

#include "core/SensorSample.h"

namespace fitstream {

    class ISensorStream {
    public:

        // Check if more data is available
        virtual bool hasNext() = 0; 

        // Get the next sensor sample
        virtual SensorSample getNext() = 0;

        
        virtual ~ISensorStream() = default;
    };

} 