cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(CPPSDL LANGUAGES CXX)

# Définir le type de build (par exemple Debug ou Release)
set(CMAKE_BUILD_TYPE Unspecified)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Chemins vers SDL2 et ses bibliothèques
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src/include/SDL2")
set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/src/lib/libSDL2.a")
set(SDL2_IMAGE_LIBRARY "${CMAKE_SOURCE_DIR}/src/lib/libSDL2_image.a")
set(SDL2_TTF_LIBRARY "${CMAKE_SOURCE_DIR}/src/lib/libSDL2_ttf.a")

# Inclure les répertoires d'en-têtes des bibliothèques trouvées
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# Ajouter les fichiers source du projet
add_executable(${PROJECT_NAME}
    main.cpp
    src/Element.cpp
    src/EventHandler.cpp
    src/Game.cpp
    src/GameBoard.cpp
    src/GameGraphic.cpp
    src/GameOptions.cpp
    src/IntroScreenGraphic.cpp
    src/Tile.cpp
    src/Window.cpp
)

# Vérifier si les fichiers de bibliothèque existent
if(NOT EXISTS ${SDL2_LIBRARY})
  message(FATAL_ERROR "SDL2 library not found at ${SDL2_LIBRARY}")
endif()

if(NOT EXISTS ${SDL2_IMAGE_LIBRARY})
  message(FATAL_ERROR "SDL2_image library not found at ${SDL2_IMAGE_LIBRARY}")
endif()

if(NOT EXISTS ${SDL2_TTF_LIBRARY})
  message(FATAL_ERROR "SDL2_ttf library not found at ${SDL2_TTF_LIBRARY}")
endif()

# Lier les bibliothèques SDL2, SDL2_image, SDL2_ttf et les bibliothèques Windows nécessaires
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} 
                      Winmm Uuid Imm32 Cfgmgr32 Rpcrt4 SetupAPI Version)


# Générer le fichier compile_commands.json pour IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
