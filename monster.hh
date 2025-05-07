// The abstract class for CC monsters

#include "tile.hh"

class Monster : public Tile {
public:
    Monster() = delete;
    virtual ~Monster() = default;

    inline virtual bool isMovable() const { return true; }
};