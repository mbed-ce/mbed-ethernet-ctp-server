cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19)

# Initialize Mbed OS build system. 
# Note: This block must be before the include of app.cmake
set(MBED_APP_JSON_PATH mbed_app.json5)

# If you have a custom target, add its subdirectories and upload method configs here.

include(mbed-os/tools/cmake/app.cmake)
add_subdirectory(mbed-os)

project(mbed-ethernet-ctp-server)

add_executable(ctp-server
    src/main.cpp)

target_link_libraries(ctp-server
    mbed-os
    mbed-netsocket
    mbed-emac-test-utils)

mbed_set_post_build(ctp-server)

mbed_finalize_build()