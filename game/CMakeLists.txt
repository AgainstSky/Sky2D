add_executable(SkyGame)

target_sources(SkyGame
        PRIVATE
        src/main.cpp
)

target_link_libraries(SkyGame
        PRIVATE
        Sky2D
)

target_compile_features(SkyGame
        PRIVATE
        cxx_std_20
)