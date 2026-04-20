add_library(core 
    src/Direction.cpp
    src/LevelDefinition.cpp
    src/LevelState.cpp
)

target_include_directories(core PUBLIC include)
