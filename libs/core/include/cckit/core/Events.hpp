#pragma once
#include "cckit/core/Position.hpp"
#include <vector>

namespace cckit {
    namespace core {
        enum class GameEventType {
            PlayerMoved,
            MovementBlocked,
            ChipCollected,
            SocketOpened,
            LevelCompleted
        };

        struct GameEvent {
            GameEventType type;
            Position pos{};
        };

        struct TickResult {
            std::vector<GameEvent> events;
        };
    }
}