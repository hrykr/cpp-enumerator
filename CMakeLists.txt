cmake_minimum_required(VERSION 3.15)
project(enumerate VERSION 1.0.0 LANGUAGES CXX)

# Header-only library
add_library(enumerate INTERFACE)

# Point directly to the include/ directory
target_include_directories(enumerate INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(enumerate INTERFACE cxx_std_20)

include(GNUInstallDirs)

install(TARGETS enumerate EXPORT enumerateTargets)
install(EXPORT enumerateTargets FILE enumerateTargets.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/enumerate)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})