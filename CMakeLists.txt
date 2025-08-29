cmake_minimum_required(VERSION 4.0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3 -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -O0")

# Collect driver sources
file(GLOB DRIVER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Create static library
add_library(mpu6050 STATIC ${DRIVER_SOURCES})

# MCU-specific flags (propagate to parent)
target_compile_options(mpu6050 PUBLIC
    -mcpu=cortex-m3
    -mthumb
)

# Expose include folder
target_include_directories(mpu6050 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)