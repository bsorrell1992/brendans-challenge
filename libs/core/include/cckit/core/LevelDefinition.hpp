#pragma once
#include "cckit/core/GameElements.hpp"
#include <vector>

namespace cckit {
    namespace core {
        class LevelDefinition {
        public:
            LevelDefinition(int width, int height);

            int width() const;
            int height() const;

            TileKind tileAt(Position p) const;
            void setTile(Position p, TileKind tile);

            void setPlayerStart(Position p);
            Position playerStart() const;

            void setRequiredChips(int count);
            int requiredChips() const;
        
        private:
            int m_width;
            int m_height;
            std::vector<TileKind> m_tiles;
            Position m_playerStart;
            int m_requiredChips = 0;
        };
    }
}