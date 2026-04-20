#include "cckit/core/LevelState.hpp"

namespace cckit::core {

LevelState::LevelState(const LevelDefinition& def)
    : m_width(def.width()), m_height(def.height()), m_player{0, ActorKind::Player, def.playerStart()},
      m_requiredChips(def.requiredChips()) {
    
    m_tiles.resize(m_width * m_height, TileKind::Floor);
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            m_tiles[y * m_width + x] = def.tileAt({x, y});
        }
    }
}

const ActorState& LevelState::player() const { return m_player; }
ActorState& LevelState::player() { return m_player; }

TileKind LevelState::tileAt(Position p) const {
    if (p.x >= 0 && p.x < m_width && p.y >= 0 && p.y < m_height) {
        return m_tiles[p.y * m_width + p.x];
    }
    return TileKind::Wall;
}

void LevelState::setTile(Position p, TileKind tile) {
    if (p.x >= 0 && p.x < m_width && p.y >= 0 && p.y < m_height) {
        m_tiles[p.y * m_width + p.x] = tile;
    }
}

int LevelState::collectedChips() const { return m_collectedChips; }
void LevelState::addCollectedChip() { ++m_collectedChips; }

int LevelState::requiredChips() const { return m_requiredChips; }

bool LevelState::isComplete() const { return m_complete; }
void LevelState::markComplete() { m_complete = true; }

}
