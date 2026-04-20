#pragma once
#include "cckit/core/Position.hpp"

namespace cckit {
    namespace core {
        enum class TileKind {
            Floor,
            Wall,
            Chip,
            Socket,
            Exit
        };

        enum class ActorKind {
            Player
        };

        struct ActorState {
            int id;
            ActorKind kind;
            Position pos;
        };

        enum class PlayerActionType {
            MoveUp,
            MoveDown,
            MoveLeft,
            MoveRight,
            Wait
        };

        struct PlayerAction {
            PlayerActionType type;
        };
    }
}