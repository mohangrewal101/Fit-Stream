
#pragma once

#include "Normalizer.h"
#include "core/SensorSample.h"

namespace fitstream
{
    class NormalizationPipeline
    {
    private:
        Normalizer normalizer;

    public:
        // Process sample through pipline and return normalized sample
        SensorSample process(const SensorSample &sample) const;
    };
}
