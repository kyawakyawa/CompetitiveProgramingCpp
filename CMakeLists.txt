cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramingCpp LANGUAGES CXX C)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release")
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# CCACHE
option(USE_CCACHE "Use ccache to accelerate a build(if available)" ON)
find_program(CCACHE_EXE ccache)
if(USE_CCACHE AND CCACHE_EXE)
    message(STATUS "ccache: Enabled")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_EXE}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_EXE}")
else()
    message(STATUS "ccache: Disabled")
    set(USE_CCACHE OFF)
endif()

# Overall compile options
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Og -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -O0")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Check C++17 support
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++17" COMPILER_SUPPORTS_CXX17)
if (COMPILER_SUPPORTS_CXX17)
    message(STATUS "C++17 support: OK (-std=c++17)")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++17 support. Please use a different C++ compiler.")
endif()

# Stack Trace logger (Glog)
option(USE_STACK_TRACE_LOGGER "Enable automatic stack trace logger of google-glog" OFF)
if(USE_STACK_TRACE_LOGGER)
    message(STATUS "Stack trace logger: ENABLED")
    # Glog
    find_package(Glog REQUIRED)
else()
    message(STATUS "Stack trace logger: DISABLED")
endif()

add_subdirectory(atcoder)
add_subdirectory(yukicoder)
add_subdirectory(library)
