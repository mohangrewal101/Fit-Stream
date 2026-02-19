#pragma once

#include "ISensorStream.h"

namespace fitstream
{
    class SyntheticStream : public ISensorStream
    {
        private:

        int totalSamples;
        double frequency;
        double sampleRateHz;
        double amplitude;

        int currentSample;

        public:
        SyntheticStream(int numSamples, double freq, double sampleRate);

        bool hasNext() override;
        SensorSample getNext() override;
    };

}