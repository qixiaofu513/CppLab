#pragma once

#include "Executor.hpp"

namespace adas
{
    class PoseHandler final
    {
        Pose pose;//汽车姿态
        bool isFast{false};//是否位于加速状态

        public:
            PoseHandler(const Pose& pose) noexcept;
            PoseHandler(const PoseHandler&) = delete;            //禁止拷贝构造
            PoseHandler& operator=(const PoseHandler&) = delete; //禁止拷贝赋值
        public:
            Pose Query(void) const noexcept;//查询汽车姿态
            void Move(void) noexcept;//移动汽车
            void TurnLeft(void) noexcept;//左转汽车
            void TurnRight(void) noexcept;//右转汽车
            void Fast(void) noexcept;//加速汽车
            bool IsFast(void) const noexcept;//判断是否位于加速状态
    };
}