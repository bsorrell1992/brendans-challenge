#include <gtest/gtest.h>
#include "cckit/core/LevelDefinition.hpp"
#include "cckit/core/LevelState.hpp"
#include "cckit/core/GameElements.hpp"

using namespace cckit::core;

TEST(LevelStateTest, Initialization) {
    LevelDefinition def(5, 5);
    def.setPlayerStart({1, 1});
    def.setRequiredChips(10);
    
    LevelState state(def);
    
    EXPECT_EQ(state.player().pos.x, 1);
    EXPECT_EQ(state.player().pos.y, 1);
    EXPECT_EQ(state.requiredChips(), 10);
}
