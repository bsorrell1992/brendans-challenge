add_library(rules_ms 
    src/BasicMsRuleset.cpp
)

target_include_directories(rules_ms PUBLIC include)
target_link_libraries(rules_ms PUBLIC core)
