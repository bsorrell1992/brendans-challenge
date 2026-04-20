#include "cckit/core/Direction.hpp"

namespace cckit::core {

Position offset(Position p, Direction d) {
    switch (d) {
        case Direction::Up:    return {p.x, p.y - 1};
        case Direction::Down:  return {p.x, p.y + 1};
        case Direction::Left:  return {p.x - 1, p.y};
        case Direction::Right: return {p.x + 1, p.y};
    }
    return p;
}

}
