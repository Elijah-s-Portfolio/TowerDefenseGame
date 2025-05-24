cmake_minimum_required(VERSION 3.16)


# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

project(TowerDefense)
set(EXECUTABLE_NAME ${PROJECT_NAME})# Executable name set to project name

target_sources(${EXECUTABLE_NAME} 
PRIVATE 
    src/main.cpp
)

# Call's SDL CMake File
add_subdirectory(SDL EXCLUDE_FROM_ALL)

#SDL_ttf
set(SDLTTF_VENDORED ON)
add_subdirectory(SDL_ttf EXCLUDE_FROM_ALL)

#SDL_mixer
set(SDLMIXER_VENDORED ON)
add_subdirectory(SDL_mixer EXCLUDE_FROM_ALL)

#SDL_image
set(SDLIMAGE_VENDORED ON)

# Create your game executable target as usual
add_executable(${PROJECT_NAME} main.c)

# Link to the actual SDL3 library.
target_link_libraries(${EXECUTABLE_NAME} PUBLIC 
	SDL3_ttf::SDL3_ttf      
	SDL3_mixer::SDL3_mixer  
	SDL3_image::SDL3_image	
    SDL3::SDL3             
)