// Contains building blocks every other file will use

#pragma once
#include <cstdint>

namespace fitstream
{
    // Timestamp in milliseconds
    using Timestamp = uint64_t;

    // 3D Vector for Movement
    struct Vector3
    {
        double x;
        double y;
        double z;

        Vector3() : x(0.0), y(0.0), z(0.0) {}

        Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    };
};