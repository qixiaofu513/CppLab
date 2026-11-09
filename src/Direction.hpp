#pragma once

#include "Point.hpp"

namespace adas
{
    /*方向类*/
    class Direction final
    {
        public:
            static const Direction& GetDirection(const char heading) noexcept;  //获取方向

            Direction(const unsigned index, const char heading) noexcept;  //构造函数

            const Point& Move(void) const noexcept;  //当前朝向对应的移动向量
            const Direction& LeftOne(void) const noexcept;  //当前朝向对应的转向
            const Direction& RightOne(void) const noexcept;  

            const char GetHeading(void) const noexcept;  //获取当前朝向
        private:
            unsigned index;  //当前朝向的索引 0 1 2 3
            char heading;  //当前朝向 E S W N
    };
}