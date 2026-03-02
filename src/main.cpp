#include <iostream>
#include <cmath>
#include "core/Types.h"
#include "core/SensorSample.h"
#include "ingestion/ISensorStream.h"
#include "ingestion/SyntheticStream.h"
#include "normalization/NormalizationPipeline.h"


int main() {
    using namespace fitstream;
    
    // Create a TEST synthetic stream: 500 samples, 0.25 Hz frequency, 100 Hz sample rate
    // This should show ONE squat
    SyntheticStream stream(500, 0.25, 100.0);
    
    std::cout << "Generating synthetic squat data:\n";
    std::cout << "Time(s), Z-Acceleration(m/s²)\n";
    std::cout << "--------------------------------------------------------\n";
    
    // Create a normalization pipeline
    NormalizationPipeline pipeline;

    std::cout << "Testing Normalization Pipeline:\n";
    std::cout << "Time(s) | Raw_Z | Normalized_Z | Raw_Length | Note\n";
    std::cout << "--------------------------------------------------------\n";

    int sampleNum = 0;
    while (stream.hasNext()) {
        SensorSample rawSample = stream.getNext();

        // Process sample through normalization pipeline
        SensorSample normalizedSample = pipeline.process(rawSample);
        
        // Print every 40th sample (shows ~10 points every 4 seconds)
        // Negative values indicate upward movement
        // Positive values indicate downward movement
        if (sampleNum % 40 == 0) {
            double timeSec = rawSample.timestamp / 1000.0;

            // Calculate raw vector length for comparison
            double rawLength = std::sqrt(rawSample.acceleration.x * rawSample.acceleration.x +
                                         rawSample.acceleration.y * rawSample.acceleration.y +
                                         rawSample.acceleration.z * rawSample.acceleration.z);
            
            // Determine squat phase
            const char* phase = "";

            if (timeSec < 0.5) phase = "Standing/Start";
            else if (timeSec < 1.5) phase = "Descending";
            else if (timeSec < 2.5) phase = "Transition";
            else if (timeSec < 3.5) phase = "Ascending";
            else phase = "Back to standing";
            
            std::cout << timeSec << "s | " 
                      << rawSample.acceleration.z << " | " 
                      << normalizedSample.acceleration.z << " | "
                      << rawLength << " | "
                      << phase << "\n";
        }
        
        sampleNum++;
    }
    
    return 0;
}