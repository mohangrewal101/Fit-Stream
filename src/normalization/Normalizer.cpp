#include "Normalizer.h"
#include <cmath>

namespace fitstream {

    SensorSample Normalizer::normalize(const SensorSample& sample) const {
        // Avoid copying the acceleration vector and use reference instead
        const Vector3& accel = sample.acceleration;
        double length = calculateLength(accel);

        if (length < 1e-9) {
            // Return original sample if length is too small to avoid division by zero
            return sample;
        }

        // Normalize each component
        double normX = accel.x / length;
        double normY = accel.y / length;
        double normZ = accel.z / length;

        return SensorSample(sample.timestamp, normX, normY, normZ);
    }

    double Normalizer::calculateLength(const Vector3& vector) const {
        return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    }
}