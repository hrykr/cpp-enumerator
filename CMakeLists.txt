cmake_minimum_required(VERSION 3.14...4.0)
project(enumerator VERSION 1.2.0 LANGUAGES CXX)

# Header-only library
add_library(enumerator INTERFACE)
add_library(enumerator::enumerator ALIAS enumerator)

# Point directly to the include/ directory
target_include_directories(enumerator INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(enumerator INTERFACE cxx_std_17)

include(GNUInstallDirs)
install(TARGETS enumerator
        EXPORT enumeratorTargets
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/enumerator
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.hpp"
)

install(EXPORT enumeratorTargets
        FILE enumeratorTargets.cmake
        NAMESPACE enumerator::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/enumerator
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/enumeratorConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/enumeratorConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/enumeratorConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/enumerator
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/enumeratorConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/enumeratorConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/enumerator
)

set(ENUMERATOR_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE INTERNAL "Enumerator include directory")