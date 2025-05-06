// The abstract class for CC tiles

class Tile {
    Tile() = delete;
    virtual ~Tile() = default;

    inline virtual bool isMovable() const { return false; }
    virtual void move() = 0;
};