#include <iostream>
#include "core/Types.h"
#include "core/SensorSample.h"
#include "ingestion/ISensorStream.h"
#include "ingestion/SyntheticStream.h"


int main() {
    using namespace fitstream;
    
    // Create a TEST synthetic stream: 500 samples, 0.25 Hz frequency, 100 Hz sample rate
    // This should show ONE squat
    SyntheticStream stream(500, 0.25, 100.0);
    
    std::cout << "Generating synthetic squat data:\n";
    std::cout << "Time(s), Z-Acceleration(m/s²)\n";
    
    int sampleNum = 0;
    while (stream.hasNext()) {
        SensorSample sample = stream.getNext();
        
        // Print every 40th sample (shows ~10 points every 4 seconds)
        // Negative values indicate upward movement
        // Positive values indicate downward movement
        if (sampleNum % 40 == 0) {
            double timeSec = sample.timestamp / 1000.0;
            std::cout << timeSec << "s, " 
                      << sample.acceleration.z << "\n";
        }
        
        sampleNum++;
    }
    
    return 0;
}