#pragma once
#include "cckit/core/Position.hpp"

namespace cckit {
    namespace core {
        enum class Direction {
            Up,
            Down,
            Left,
            Right
        };

        Position offset(Position p, Direction d);
    }
}