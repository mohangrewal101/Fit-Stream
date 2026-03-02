
#include "NormalizationPipeline.h"

namespace fitstream
{
    SensorSample NormalizationPipeline::process(const SensorSample &sample) const
    {
        return normalizer.normalize(sample);
    }
}