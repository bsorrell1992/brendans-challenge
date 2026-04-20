#pragma once
#include "cckit/core/LevelDefinition.hpp"

namespace cckit {
    namespace core {
        class LevelState {
        public:
            explicit LevelState(const LevelDefinition& def);

            const ActorState& player() const;
            ActorState& player();

            TileKind tileAt(Position p) const;
            void setTile(Position p, TileKind tile);

            int collectedChips() const;
            void addCollectedChip();

            int requiredChips() const;

            bool isComplete() const;
            void markComplete();

        private:
            int m_width;
            int m_height;
            std::vector<TileKind> m_tiles;
            ActorState m_player;
            int m_collectedChips = 0;
            int m_requiredChips = 0;
            bool m_complete = false;
        };
    }
}