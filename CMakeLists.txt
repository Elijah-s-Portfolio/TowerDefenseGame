cmake_minimum_required(VERSION 3.16)

# Set the output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

# Project setup
project(TowerDefense)
set(EXECUTABLE_NAME ${PROJECT_NAME})

# Add source files
add_executable(${EXECUTABLE_NAME}
    src/main.cpp
)

# SDL Core
add_subdirectory(SDL EXCLUDE_FROM_ALL)

# SDL_ttf
set(SDLTTF_VENDORED OFF)
add_subdirectory(SDL_ttf EXCLUDE_FROM_ALL)

# SDL_mixer
set(SDLMIXER_VENDORED OFF)
add_subdirectory(SDL_mixer EXCLUDE_FROM_ALL)

# SDL_image
set(SDLIMAGE_VENDORED OFF)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

# Link all SDL libraries
target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf
        SDL3_mixer::SDL3_mixer
        SDL3_image::SDL3_image
)

target_include_directories(${EXECUTABLE_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/SDL/include
    ${CMAKE_SOURCE_DIR}/SDL_image/include
    ${CMAKE_SOURCE_DIR}/SDL_ttf/include
    ${CMAKE_SOURCE_DIR}/SDL_mixer/include
)