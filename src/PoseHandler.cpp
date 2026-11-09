#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose& pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
    {
    }

    Pose PoseHandler::Query(void) const noexcept
    {
        return {point.GetX(), point.GetY(), facing->GetHeading()};
    }

    void PoseHandler::Forward(void) noexcept
    {
        point += facing->Move();
    }

    void PoseHandler::Backward(void) noexcept
    {
        point -= facing->Move();
    }

    void PoseHandler::TurnLeft(void) noexcept
    {
        facing = &facing->LeftOne();
    }

    void PoseHandler::TurnRight(void) noexcept
    {
        facing = &facing->RightOne();
    }

    void PoseHandler::Fast(void) noexcept
    {
        isFast = !isFast;
    }

    void PoseHandler::Reverse(void) noexcept
    {
        isReverse = !isReverse;
    }

    bool PoseHandler::IsFast(void) const noexcept
    {
        return isFast;
    }

    bool PoseHandler::IsReverse(void) const noexcept
    {
        return isReverse;
    }
}