#pragma once
#include "cckit/core/LevelState.hpp"
#include "cckit/core/Events.hpp"
#include "cckit/core/GameElements.hpp"

namespace cckit {
    namespace core {
        class IRuleset {
        public:
            virtual ~IRuleset() = default;

            virtual TickResult step(LevelState& state, const PlayerAction& action) = 0;
        };
    }
}