#pragma once

#include "../core/PoseHandler.hpp"
#include "ActionGroup.hpp"

namespace adas {
    class MoveCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            const auto action = poseHandler.IsReverse()?
                ActionType::BACKWARD_1_STEP_ACTION:
                ActionType::FORWARD_1_STEP_ACTION;
            if (poseHandler.IsFast()) {
                actionGroup.PushAction(action);
            }
                actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class TurnLeftCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            if (poseHandler.IsFast()) {
                actionGroup.PushAction(poseHandler.IsReverse()?
                    ActionType::BACKWARD_1_STEP_ACTION:
                    ActionType::FORWARD_1_STEP_ACTION);
            }
            actionGroup.PushAction(poseHandler.IsReverse()?
                ActionType::REVERSE_TURNLEFT_ACTION:
                ActionType::TURNLEFT_ACTION);
            return actionGroup;
        }

    };

    class TurnRightCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            if (poseHandler.IsFast()) {
                actionGroup.PushAction(poseHandler.IsReverse()?
                    ActionType::BACKWARD_1_STEP_ACTION:
                    ActionType::FORWARD_1_STEP_ACTION);
            }
            actionGroup.PushAction(poseHandler.IsReverse()?
                ActionType::REVERSE_TURNRIGHT_ACTION:
                ActionType::TURNRIGHT_ACTION);
            return actionGroup;
        }

    };

    class FastCommand final {
    public:
        ActionGroup operator()(PoseHandler&) const noexcept {
            return ActionGroup({ActionType::BE_FAST_ACTION});
        }

    };

    class ReverseCommand final {
    public:
        ActionGroup operator()(PoseHandler&) const noexcept {
            return ActionGroup({ActionType::BE_REVERSE_ACTION});
        }

    };

    class TurnRoundCommand final {
        public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            if (poseHandler.IsReverse()) {
                return ActionGroup();
            }
            if (poseHandler.IsFast()) {
                return ActionGroup({
                    ActionType::FORWARD_1_STEP_ACTION,
                    ActionType::TURNLEFT_ACTION,
                    ActionType::FORWARD_1_STEP_ACTION,
                    ActionType::TURNLEFT_ACTION
                });
            }
            return ActionGroup({
                ActionType::TURNLEFT_ACTION,
                ActionType::FORWARD_1_STEP_ACTION,
                ActionType::TURNLEFT_ACTION
            });
        }
    };
}