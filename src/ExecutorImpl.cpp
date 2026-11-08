#include "ExecutorImpl.hpp"
#include "Command.hpp"

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
            std::unique_ptr<ICommand> cmder;
            if (cmd == 'M')
            {
                cmder = std::make_unique<MoveCommand>();
            }
            else if (cmd == 'L')
            {
                cmder = std::make_unique<TurnLeftCommand>();
            }
            else if (cmd == 'R')
            {
                cmder = std::make_unique<TurnRightCommand>();
            }
            else if (cmd == 'F')
            {
                cmder = std::make_unique<FastCommand>();
            }

            if (cmder)
            {
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

    void ExecutorImpl::Fast(void) noexcept
    {
        isFast = !isFast;
    }

    bool ExecutorImpl::IsFast(void) const noexcept
    {
        return isFast;
    }
}