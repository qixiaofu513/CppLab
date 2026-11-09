#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <new>
#include <memory>
#include <unordered_map>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose)
    {
    }

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        //表驱动
        std::unordered_map<char, std::function<void(PoseHandler& PoseHandler)>> cmderMap{
            {'M', MoveCommand()},        //前进
            {'L', TurnLeftCommand()},    //左转
            {'R', TurnRightCommand()},   //右转
            {'F', FastCommand()},        //加速
        };
        
        for (const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end())
            {
                it->second(poseHandler);
            }
        }
    }

}