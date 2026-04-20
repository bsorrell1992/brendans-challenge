#include "cckit/core/LevelDefinition.hpp"

namespace cckit::core {

LevelDefinition::LevelDefinition(int width, int height) 
    : m_width(width), m_height(height), m_tiles(width * height, TileKind::Floor), m_playerStart({0, 0}) {}

int LevelDefinition::width() const { return m_width; }
int LevelDefinition::height() const { return m_height; }

TileKind LevelDefinition::tileAt(Position p) const {
    if (p.x >= 0 && p.x < m_width && p.y >= 0 && p.y < m_height) {
        return m_tiles[p.y * m_width + p.x];
    }
    return TileKind::Wall;
}

void LevelDefinition::setTile(Position p, TileKind tile) {
    if (p.x >= 0 && p.x < m_width && p.y >= 0 && p.y < m_height) {
        m_tiles[p.y * m_width + p.x] = tile;
    }
}

void LevelDefinition::setPlayerStart(Position p) { m_playerStart = p; }
Position LevelDefinition::playerStart() const { return m_playerStart; }

void LevelDefinition::setRequiredChips(int count) { m_requiredChips = count; }
int LevelDefinition::requiredChips() const { return m_requiredChips; }

}
