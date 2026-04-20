#pragma once
#include "cckit/core/IRuleset.hpp"

namespace cckit {
    namespace rules_ms {
        using namespace cckit::core;

        class BasicMsRuleset : public IRuleset {
        public:
            TickResult step(LevelState& state, const PlayerAction& action) override;

        private:
            bool canEnter(TileKind tile, const LevelState& state) const;
            Position targetPosition(Position from, const PlayerAction& action) const;
        };
    }
}