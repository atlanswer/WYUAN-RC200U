cmake_minimum_required(VERSION 3.1.0)
if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

cmake_policy(SET CMP0054 NEW)

project(wyuan-test VERSION 0.1.0
                   DESCRIPTION "Windows DLL test."
                   LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include(CTest)
enable_testing()

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PUBLIC "${SOURCES}")

target_include_directories(${PROJECT_NAME}
PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
                                      VERSION ${PROJECT_VERSION}
                                      SOVERSION ${PROJECT_VERSION})

# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different "${LIB_DIR}/shared.dll" $<TARGET_FILE_DIR:cpptest3>
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
