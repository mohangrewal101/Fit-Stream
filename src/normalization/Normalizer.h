
#pragma once

#include "core/SensorSample.h"

namespace fitstream {

    class Normalizer {
        public:
        // Normalize acceleration vector to unit vector
        // Returns a new SensorSample with normalized acceleration
        SensorSample normalize(const SensorSample& sample) const;

        private: 
        // Calculate the length (magnitude) of the vector
        double calculateLength(const Vector3& vector) const;
    };
}