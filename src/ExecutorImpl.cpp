#include "ExecutorImpl.hpp"
//#include "Command.hpp"
#include "CmderFactory.hpp"
#include "Singleton.hpp"

//#include <new>
//#include <memory>
//#include <unordered_map>
#include <algorithm>

namespace adas {
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {
    }

    Pose ExecutorImpl::Query(void) const noexcept {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept {
        //std::unordered_map<char, std::function<void(PoseHandler& PoseHandler)>> cmderMap {
        //    {'M', MoveCommand()},        //前进
        //    {'L', TurnLeftCommand()},    //左转
        //    {'R', TurnRightCommand()},   //右转
        //    {'F', FastCommand()},        //加速
        //    {'B', ReverseCommand()}        //倒车
        //};
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmder(commands);
        //for (const auto cmd : commands) {
        //    const auto it = cmderMap.find(cmd);
        //    if (it != cmderMap.end()) {
        //        it->second(poseHandler);
        //    }
        //}
        std::for_each(
            cmders.begin(),
            cmders.end(),
            [this](const std::function<void(PoseHandler& poseHandler)>& cmd) noexcept {
                cmd(poseHandler);
            }
        );
    }

}