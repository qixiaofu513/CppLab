#pragma once

#include "Executor.hpp"
#include "./core/PoseHandler.hpp"
#include <string>

namespace adas {
    /*Executor类的具体实现*/
    class ExecutorImpl final : public Executor {
        public:
            //构造函数，初始化汽车姿态
            explicit ExecutorImpl(const Pose &pose) noexcept;
            //析构函数
            ~ExecutorImpl(void) noexcept = default;
            ExecutorImpl(const ExecutorImpl &) = delete;
            ExecutorImpl &operator=(const ExecutorImpl &) = delete;

            //重写Query函数，返回当前汽车姿态
            Pose Query(void) const noexcept override;
            //重写Execute函数，执行给定的命令
            void Execute(const std::string &commands) noexcept override;
        private:
            PoseHandler poseHandler;//汽车姿态处理器
            
    };
}