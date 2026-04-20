add_executable(CoreTests
    LevelStateTest.cpp
)

target_link_libraries(CoreTests
    GTest::gtest_main
    core
    rules_ms
)

include(GoogleTest)
gtest_discover_tests(CoreTests)
