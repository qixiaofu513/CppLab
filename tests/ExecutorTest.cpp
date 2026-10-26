#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
    //重载运算符==，用于比较两个Pose对象是否相等
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
    //测试用例1
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        //given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        //when

        //then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    //测试用例2
    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        //given
        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        //when

        //then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    //测试用例3
    TEST(ExecutorTest, should_return_x_plus_1_given_command_M_and_facing_E)
    {
        //given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        
        //when
        executor->Execute("M");

        //then
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
}