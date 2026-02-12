// Defines sample data for a sensor readings
#pragma once
#include "Types.h"

namespace fitstream
{
    struct SensorSample
    {
        Timestamp timestamp; // When this data was recorded
        Vector3 acceleration;

        SensorSample() : timestamp(0), acceleration() {}

        SensorSample(Timestamp timestamp, const Vector3 &acceleration)
            : timestamp(timestamp), acceleration(acceleration) {}

        SensorSample(Timestamp timestamp, double ax, double ay, double az)
            : timestamp(timestamp), acceleration(ax, ay, az) {}
    };
}