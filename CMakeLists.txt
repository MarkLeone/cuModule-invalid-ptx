# Using the latest CMake is highly recommended, to ensure up-to-date CUDA language support.
cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(cuModuleInvalidPTX LANGUAGES CXX CUDA)
set(CMAKE_CXX_STANDARD 11)

find_package( CUDAToolkit 11.7 REQUIRED )
set(CMAKE_CUDA_ARCHITECTURES "60-virtual")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMake)
set( OTK_BUILD_TESTS OFF CACHE BOOL "Enable build of OptiXToolkit tests" )
add_subdirectory("DemandLoading")

add_library(kernelLib OBJECT)
target_sources(kernelLib PRIVATE kernel.cu)
target_link_libraries(kernelLib OptiXToolkit::DemandLoading)
set_property(TARGET kernelLib PROPERTY CUDA_PTX_COMPILATION ON)

add_executable(cuModuleInvalidPTX main.cpp)

target_compile_options(cuModuleInvalidPTX PRIVATE "-DPTX_FILENAME=\"$<TARGET_OBJECTS:kernelLib>\"")

target_link_libraries(cuModuleInvalidPTX
  CUDA::cuda_driver
  CUDA::cudart
  )

