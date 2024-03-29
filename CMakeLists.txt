project(ChessEngine)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "Sources/*.cpp")
file(GLOB_RECURSE HEADERS "Sources/*.h")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_IMG REQUIRED SDL2_image)
PKG_SEARCH_MODULE(SDL2_TTF REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2_MIX REQUIRED SDL2_mixer)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS}
    ${SDL2_IMG_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${SDL2_MIX_INCLUDE_DIRS})

LINK_DIRECTORIES (${SDL2_LIBRARY_DIRS}
    ${SDL2_IMG_LIBRARY_DIRS}
    ${SDL2_TTF_LIBRARY_DIRS}
    ${SDL2_MIX_LIBRARY_DIRS})

target_link_libraries (${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2_IMG_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIX_LIBRARIES})


