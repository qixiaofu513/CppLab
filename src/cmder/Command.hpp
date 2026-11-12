#pragma once

#include "../core/PoseHandler.hpp"
#include "CmderOrchestrator.hpp"

namespace adas {
    class MoveCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler, const CmderOrchestrator& orchestrator) const noexcept {
            return orchestrator.Move(poseHandler);
        }
    };

    class TurnLeftCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler, const CmderOrchestrator& orchestrator) const noexcept {
            return orchestrator.TurnLeft(poseHandler);
        }
    };

    class TurnRightCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler, const CmderOrchestrator& orchestrator) const noexcept {
            return orchestrator.TurnRight(poseHandler);
        }

    };

    class FastCommand final {
    public:
        ActionGroup operator()(PoseHandler&, const CmderOrchestrator&) const noexcept {
            return ActionGroup({ActionType::BE_FAST_ACTION});
        }

    };

    class ReverseCommand final {
    public:
        ActionGroup operator()(PoseHandler&, const CmderOrchestrator&) const noexcept {
            return ActionGroup({ActionType::BE_REVERSE_ACTION});
        }

    };

    class TurnRoundCommand final {
        public:
        ActionGroup operator()(PoseHandler& poseHandler, const CmderOrchestrator& orchestrator) const noexcept {
            return orchestrator.TurnRound(poseHandler);
        }
    };
}