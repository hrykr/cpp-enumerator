cmake_minimum_required(VERSION 4.0)
project(enumerator VERSION 1.1.0 LANGUAGES CXX)

# Header-only library
add_library(enumerator INTERFACE)

# Point directly to the include/ directory
target_include_directories(enumerator INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(enumerator INTERFACE cxx_std_17)

include(GNUInstallDirs)
install(TARGETS enumerator EXPORT enumeratorTargets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT enumeratorTargets
        FILE enumeratorTargets.cmake
        NAMESPACE enumerator::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/enumerator
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/enumeratorConfigVersion.cmake"
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/enumeratorConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/enumerator
)