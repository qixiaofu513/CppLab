#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose), isFast(false)
    {
    }

    Pose PoseHandler::Query(void) const noexcept
    {
        return pose;
    }

    void PoseHandler::Move(void) noexcept
    {
        switch (pose.heading)
        {
            case 'N':
                pose.y++;
                break;
            case 'E':
                pose.x++;
                break;
            case 'S':
                pose.y--;
                break;
            case 'W':
                pose.x--;
                break;
            default:
                break;
        }
    }

    void PoseHandler::TurnLeft(void) noexcept
    {
        switch (pose.heading)
        {
            case 'N':
                pose.heading = 'W';
                break;
            case 'E':
                pose.heading = 'N';
                break;
            case 'S':
                pose.heading = 'E';
                break;
            case 'W':
                pose.heading = 'S';
                break;
            default:
                break;
        }
    }

    void PoseHandler::TurnRight(void) noexcept
    {
        switch (pose.heading)
        {
            case 'N':
                pose.heading = 'E';
                break;
            case 'E':
                pose.heading = 'S';
                break;
            case 'S':
                pose.heading = 'W';
                break;
            case 'W':
                pose.heading = 'N';
                break;
            default:
                break;
        }
    }

    void PoseHandler::Fast(void) noexcept
    {
        isFast = !isFast;
    }

    bool PoseHandler::IsFast(void) const noexcept
    {
        return isFast;
    }
}