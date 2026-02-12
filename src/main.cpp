#include <iostream>
#include "core/Types.h"
#include "core/SensorSample.h"


int main() {
    // Test the basic types and structures
    using namespace fitstream; // only applies to main function
    
    Vector3 gravity(0.0, 0.0, -9.81);
    std::cout << "Gravity: (" << gravity.x << ", " 
              << gravity.y << ", " << gravity.z << ")\n";

    SensorSample sample(123456789, gravity);
    std::cout << "Sample timestamp: " << sample.timestamp << "\n";
    std::cout << "Sample acceleration: (" 
              << sample.acceleration.x << ", "
              << sample.acceleration.y << ", "
              << sample.acceleration.z << ")\n";
    
    std::cout << "\nFitStream core types initialized successfully!\n";
    return 0;
}