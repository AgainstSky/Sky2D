add_library(Sky2D STATIC)

file(GLOB_RECURSE SKY2D_SOURCES
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

target_sources(Sky2D
        PRIVATE
        ${SKY2D_SOURCES}
)

target_include_directories(Sky2D
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(Sky2D
        PUBLIC
        cxx_std_20
)

target_link_libraries(Sky2D
        PUBLIC
        raylib
)



#add_library(Sky2D STATIC)
#
#
#
#target_sources(Sky2D
#        PRIVATE
#
#        # Core
#        src/core/Engine.cpp
#        src/core/Time.cpp
#        src/core/ResourceManager.cpp
##        src/Core/Time.cpp
##
##        # Scene
##        src/Scene/Scene.cpp
##        src/Scene/GameObject.cpp
##
##        # Component
##        src/Component/SpriteRenderer.cpp
##
##        # Rendering
##        src/Rendering/Renderer2D.cpp
##        src/Rendering/Camera2D.cpp
##
##        # Resources
##        src/Resources/ResourceManager.cpp
##
##        # Input
##        src/Input/Input.cpp
##
##        # Audio
##        src/Audio/AudioManager.cpp
#)
#
#
#target_include_directories(Sky2D
#        PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/include
#)
#
#target_compile_features(Sky2D
#        PUBLIC
#        cxx_std_20
#)
#
#target_link_libraries(Sky2D
#        PUBLIC
#        raylib
#)