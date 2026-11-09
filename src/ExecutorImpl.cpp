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
        std::unordered_map<char, /*std::unique_ptr<ICommand>*/ std::function<void(PoseHandler& PoseHandler)>> cmderMap;
        //建立操作M和前进指令的映射关系
        //cmderMap.emplace('M', std::make_unique<MoveCommand>());
        MoveCommand moveCommand;
        cmderMap.emplace('M', moveCommand.operate);
        //建立操作L和左转指令的映射关系
        //cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
        TurnLeftCommand turnLeftCommand;
        cmderMap.emplace('L', turnLeftCommand.operate);
        //建立操作R和右转指令的映射关系
        //cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
        TurnRightCommand turnRightCommand;
        cmderMap.emplace('R', turnRightCommand.operate);
        //建立操作F和快速移动指令的映射关系
        //cmderMap.emplace('F', std::make_unique<FastCommand>());
        FastCommand fastCommand;
        cmderMap.emplace('F', fastCommand.operate);
        for (const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end())
            {
                //it->second->DoOperate(poseHandler);
                it->second(poseHandler);
            }
        }
    }

}