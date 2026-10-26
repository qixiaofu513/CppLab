#pragma once
#include <string>
namespace adas
{
    /*汽车姿态*/
    struct Pose
    {
        int x;//x坐标
        int y;//y坐标
        char heading;//'N' 'E' 'S' 'W'
    };
    /*执行器*/
    class Executor
    {
        public:
            //创建新的执行器实例
            static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;
        public:
            //默认构造函数和析构函数，禁止拷贝构造和赋值
            Executor(void) = default;
            virtual ~Executor(void) = default;
            Executor(const Executor &) = delete;
            Executor &operator=(const Executor &) = delete;
        public:
            //执行器的接口函数
            virtual Pose Query(void) const noexcept = 0;
    };
}