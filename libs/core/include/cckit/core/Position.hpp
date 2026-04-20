#pragma once

namespace cckit {
    namespace core {
        struct Position {
            int x;
            int y;

            bool operator==(const Position& other) const = default;
        };
    }
}