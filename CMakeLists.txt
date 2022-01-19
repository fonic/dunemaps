# -------------------------------------------------------------------------
#                                                                         -
#  Created by Fonic <https://github.com/fonic>                            -
#  Date: 01/19/22                                                         -
#                                                                         -
#  Based on:                                                              -
#  https://github.com/pragmaticlinuxblog/cmake_wxwidgets                  -
#                                                                         -
# -------------------------------------------------------------------------

# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.7)

# Specify the project name
project(dunemaps-linux C CXX)

# Specify source files
set(
    PROG_SRCS
    src/appDuneMaps.cpp
    src/dialogBasics.cpp
    src/dialogChoam.cpp
    src/dialogHouses.cpp
    src/dialogNewScenario.cpp
    src/dialogReinforcement.cpp
    src/dialogReinforcements.cpp
    src/dialogTeam.cpp
    src/dialogTeams.cpp
    src/frameDuneMaps.cpp
    src/panelMinimap.cpp
    src/panelSurface.cpp
    src/dune/dune.cpp
    src/dune/map.cpp
    src/dune/minimap.cpp
    src/dune/resourceExe.cpp
    src/dune/resources.cpp
    src/dune/screenPlayfield.cpp
    src/dune/eastwood/CpsFile.cpp
    src/dune/eastwood/Decode.cpp
    src/dune/eastwood/Exception.cpp
    src/dune/eastwood/Font.cpp
    src/dune/eastwood/IcnFile.cpp
    src/dune/eastwood/IniFile.cpp
    src/dune/eastwood/PakFile.cpp
    src/dune/eastwood/PalFile.cpp
    src/dune/eastwood/ShpFile.cpp
    src/dune/eastwood/StringFile.cpp
    src/dune/eastwood/WsaFile.cpp
    src/dune/engine/house.cpp
    src/dune/engine/mapGenerator.cpp
    src/dune/engine/objects/mapCell.cpp
    src/dune/engine/objects/object.cpp
    src/dune/engine/objects/structure.cpp
    src/dune/engine/objects/unit.cpp
    src/dune/engine/scenario.cpp
    src/dune/engine/scenarioAmiga.cpp
    src/dune/engine/team.cpp
    src/dune/graphics/scale/scale2x.c
    src/dune/graphics/scale/scale3x.c
    src/dune/graphics/scale/scalebit.c
    src/dune/graphics/surface.cpp
    src/dune/graphics/tools.cpp
)

# Specify include directories
#include_directories(src/dune)

# Specify compile flags
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-write-strings -Og -ggdb -g -rdynamic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-write-strings -Og -ggdb")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-write-strings -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-write-strings")


# Find wxWidgets library
find_package(wxWidgets COMPONENTS core base xrc REQUIRED)

# Include wxWidgets library
include(${wxWidgets_USE_FILE})


# Find SDL library
find_package(SDL REQUIRED)

# Include SDL library
include_directories(${INCLUDE_DIRECTORIES} ${SDL_INCLUDE_DIRS})


# Specify what is needed to create the main target
add_executable(${PROJECT_NAME} ${PROG_SRCS})

# Specify how to link the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${SDL_LIBRARIES})


# Specify how to install the build
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
