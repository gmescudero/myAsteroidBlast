cmake_minimum_required(VERSION 3.10.0)
project(AsteroidBlast)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

# add_library(etsidi SHARED lib/ETSIDI.lib)
# add_library(glut SHARED lib/glut32.lib)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/lib)
# link_directories(${CMAKE_SOURCE_DIR}/lib)

set(SOURCES 
        src/Asteroidblast.cpp 
        src/DisparoG.cpp 
        src/ListaBonus.cpp 
        src/ObjetoMovil.cpp
        src/Bonus.cpp 
        src/DisparoM.cpp 
        src/ListaDisparos.cpp src/Pared.cpp
        src/ColorRGB.cpp 
        src/Esfera.cpp 
        src/ListaEsferas.cpp 
        src/Spawn.cpp
        src/Coordinador.cpp 
        src/Interaccion.cpp 
        src/Mundo.cpp 
        src/Vector2D.cpp
        src/Disparo.cpp 
        src/Limites.cpp 
        src/Nave.cpp 
        src/Vidas.cpp
        src/PrintText.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})
# target_include_directories(${PROJECT_NAME} PUBLIC inc src lib)
# target_link_libraries(${PROJECT_NAME} glut32.lib ETSIDI.lib)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)