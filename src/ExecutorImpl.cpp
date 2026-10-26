#include "ExecutorImpl.hpp"

#include <new>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose)
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
                    break;
                
            }
        }
    }
}