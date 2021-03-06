#pragma once

#include <Driver/API/Context.hpp>

namespace Epsilon
{
    class Engine
    {
    public:
        static Engine &Get()
        {
            return instance;
        }

        Engine(Engine&&) = delete;
        Engine(const Engine&) = delete;

        API::CONTEXT_TYPE ContextType() {
            return mContextType;
        }

        void ContextType(API::CONTEXT_TYPE type) {
            mContextType = type;
        }

        unsigned Width() { return WindowWidth; }
        unsigned Height() { return WindowHeight; }
        
        void Width(unsigned w) { WindowWidth = w; }
        void Height(unsigned h) { WindowHeight = h; }

    private:
        Engine() = default;

        API::CONTEXT_TYPE mContextType;
        static Engine instance;

        unsigned WindowWidth = 800;
        unsigned WindowHeight = 600;
    };
} // namespace Epsilon