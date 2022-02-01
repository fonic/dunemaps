# -------------------------------------------------------------------------
#                                                                         -
#  Created by Fonic <https://github.com/fonic>                            -
#  Date: 01/19/22 - 02/01/22                                              -
#                                                                         -
#  Based on (amonst various other sources):                               -
#  https://github.com/pragmaticlinuxblog/cmake_wxwidgets                  -
#                                                                         -
# -------------------------------------------------------------------------

# Specify minimum required CMake version
cmake_minimum_required(VERSION 3.7)

# Specify project name (also executable name)
project(dunemaps C CXX)

# Specify source files
set(
    PROG_SRCS
    "src/appDuneMaps.cpp"
    "src/dialogBasics.cpp"
    "src/dialogChoam.cpp"
    "src/dialogHouses.cpp"
    "src/dialogNewScenario.cpp"
    "src/dialogReinforcement.cpp"
    "src/dialogReinforcements.cpp"
    "src/dialogTeam.cpp"
    "src/dialogTeams.cpp"
    "src/frameDuneMaps.cpp"
    "src/panelMinimap.cpp"
    "src/panelSurface.cpp"
    "src/dune/dune.cpp"
    "src/dune/map.cpp"
    "src/dune/minimap.cpp"
    "src/dune/resourceExe.cpp"
    "src/dune/resources.cpp"
    "src/dune/screenPlayfield.cpp"
    "src/dune/eastwood/CpsFile.cpp"
    "src/dune/eastwood/Decode.cpp"
    "src/dune/eastwood/Exception.cpp"
    "src/dune/eastwood/Font.cpp"
    "src/dune/eastwood/IcnFile.cpp"
    "src/dune/eastwood/IniFile.cpp"
    "src/dune/eastwood/PakFile.cpp"
    "src/dune/eastwood/PalFile.cpp"
    "src/dune/eastwood/ShpFile.cpp"
    "src/dune/eastwood/StringFile.cpp"
    "src/dune/eastwood/WsaFile.cpp"
    "src/dune/engine/house.cpp"
    "src/dune/engine/mapGenerator.cpp"
    "src/dune/engine/objects/mapCell.cpp"
    "src/dune/engine/objects/object.cpp"
    "src/dune/engine/objects/structure.cpp"
    "src/dune/engine/objects/unit.cpp"
    "src/dune/engine/scenario.cpp"
    "src/dune/engine/scenarioAmiga.cpp"
    "src/dune/engine/team.cpp"
    "src/dune/graphics/scale/scale2x.c"
    "src/dune/graphics/scale/scale3x.c"
    "src/dune/graphics/scale/scalebit.c"
    "src/dune/graphics/surface.cpp"
    "src/dune/graphics/tools.cpp"
)

# Specify include directories
#include_directories(
#    "src"
#    "src/images"
#    "src/dune"
#    "src/dune/engine"
#    "src/dune/engine/objects"
#    "src/dune/graphics"
#    "src/dune/graphics/scale"
#    "src/dune/eastwood"
#)

# Specify compile flags (defaults, debug, release)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Og -g -ggdb -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -g -ggdb -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -s")
# Additions for debug builds to suppress less relevant warnings
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Wno-unused-but-set-variable")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Wno-unused-but-set-variable")

# Find wxWidgets library
find_package(wxWidgets COMPONENTS core base xrc REQUIRED)

# Include wxWidgets library
include(${wxWidgets_USE_FILE})

# Find SDL library
find_package(SDL REQUIRED)

# Include SDL library
include_directories(${INCLUDE_DIRECTORIES} ${SDL_INCLUDE_DIRS})

# Specify executable to be built (and its sources)
add_executable(${PROJECT_NAME} ${PROG_SRCS})

# Specify libraries to be linked to executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${SDL_LIBRARIES})

# Specify how to install the build
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
