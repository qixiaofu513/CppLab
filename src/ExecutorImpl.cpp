#include "ExecutorImpl.hpp"

#include <new>

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
            switch (cmd)
            {
                case 'M':
                    Move();
                    break;
                case 'L':
                    TurnLeft();
                    break;
                case 'R':
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
                    break;
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
}