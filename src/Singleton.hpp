#pragma once

namespace adas
{
    //泛型支持
    template <typename T>
    class Singleton final {
        Singleton() = default;
        ~Singleton() = default;

        public:
        //单例模式
        static T& Instance(void) noexcept {
            static T instance;
            return instance;
        }

        //删除构造方式
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    };
}