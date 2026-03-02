cmake_minimum_required(VERSION 3.20)
project(FitStream VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CORE_SOURCES
    src/core/Types.h
    src/core/SensorSample.h
)

set(INGESTION_SOURCES
    src/ingestion/ISensorStream.h
    src/ingestion/SyntheticStream.h
    src/ingestion/SyntheticStream.cpp
)

set(NORMALIZATION_SOURCES
    src/normalization/Normalizer.h
    src/normalization/Normalizer.cpp
    src/normalization/NormalizationPipeline.h
    src/normalization/NormalizationPipeline.cpp 
)

# Add more source files as we implement them

# Build the executable with only the files we have
add_executable(fitstream
    src/main.cpp
    ${CORE_SOURCES}
    ${INGESTION_SOURCES}
    ${NORMALIZATION_SOURCES}
)

target_include_directories(fitstream PRIVATE src)

if(MSVC)
    target_compile_options(fitstream PRIVATE /W4)
else()
    target_compile_options(fitstream PRIVATE -Wall -Wextra -pedantic)
endif()