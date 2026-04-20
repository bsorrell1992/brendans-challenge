#include "cckit/rules_ms/BasicMsRuleset.hpp"

namespace cckit::rules_ms {

TickResult BasicMsRuleset::step(LevelState& state, const PlayerAction& action) {
    TickResult result;
    if (action.type == PlayerActionType::Wait) {
        return result;
    }
    
    Position target = targetPosition(state.player().pos, action);
    TileKind targetTile = state.tileAt(target);

    if (canEnter(targetTile, state)) {
        state.player().pos = target;
        result.events.push_back({GameEventType::PlayerMoved, target});
        
        if (targetTile == TileKind::Chip) {
            state.addCollectedChip();
            state.setTile(target, TileKind::Floor);
            result.events.push_back({GameEventType::ChipCollected, target});
            
            if (state.collectedChips() >= state.requiredChips()) {
                result.events.push_back({GameEventType::SocketOpened, target});
            }
        } else if (targetTile == TileKind::Exit) {
            state.markComplete();
            result.events.push_back({GameEventType::LevelCompleted, target});
        }
    } else {
        result.events.push_back({GameEventType::MovementBlocked, target});
    }

    return result;
}

bool BasicMsRuleset::canEnter(TileKind tile, const LevelState& state) const {
    if (tile == TileKind::Wall) return false;
    if (tile == TileKind::Socket && state.collectedChips() < state.requiredChips()) return false;
    return true;
}

Position BasicMsRuleset::targetPosition(Position from, const PlayerAction& action) const {
    switch (action.type) {
        case PlayerActionType::MoveUp:    return {from.x, from.y - 1};
        case PlayerActionType::MoveDown:  return {from.x, from.y + 1};
        case PlayerActionType::MoveLeft:  return {from.x - 1, from.y};
        case PlayerActionType::MoveRight: return {from.x + 1, from.y};
        default: return from;
    }
}

}
