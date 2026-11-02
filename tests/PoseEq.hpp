#pragma once
#include "Executor.hpp"

namespace adas
{
    //重载运算符==，用于比较两个Pose对象是否相等
    bool operator==(const Pose &lhs, const Pose &rhs);
}