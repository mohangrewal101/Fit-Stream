// Generates synthetic data

#define _USE_MATH_DEFINES
#include "SyntheticStream.h"
#include <cmath>

namespace fitstream
{
    SyntheticStream::SyntheticStream(int numSamples, double freq, double sampleRate)
        : totalSamples(numSamples), frequency(freq), sampleRateHz(sampleRate), amplitude(3.0), currentSample(0) {

        }

    bool SyntheticStream::hasNext()
    {
        return currentSample < totalSamples;
    }

    SensorSample SyntheticStream::getNext()
    {
        double millisBetweenSamples = 1000.0 / sampleRateHz;
        Timestamp timestamp = static_cast<Timestamp>(currentSample * millisBetweenSamples);

        double timeInSeconds = timestamp / 1000.0;

        // Calculates how far through exercise cycle we are
        double zAccel = amplitude * std::sin(2 * M_PI * frequency * timeInSeconds);
        SensorSample sample(timestamp, 0.0, 0.0, zAccel);

        currentSample++;
        
        return sample;
    }
}