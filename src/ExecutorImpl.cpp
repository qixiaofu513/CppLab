#include "ExecutorImpl.hpp"

#include <new>
#include <memory>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) , isFast(false)
    {
    }

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            if (cmd == 'M')
            {
                std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
                cmder->DoOperate(*this);
            }
            else if (cmd == 'L')
            {
                std::unique_ptr<TurnLeftCommand> cmder = std::make_unique<TurnLeftCommand>();
                cmder->DoOperate(*this);
            }
            else if (cmd == 'R')
            {
                std::unique_ptr<TurnRightCommand> cmder = std::make_unique<TurnRightCommand>();
                cmder->DoOperate(*this);
            }
        }
    }

    void ExecutorImpl::Move(void) noexcept
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
        }
    }

    void ExecutorImpl::TurnLeft(void) noexcept
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
        }
    }

    void ExecutorImpl::TurnRight(void) noexcept
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
        }
    }
}