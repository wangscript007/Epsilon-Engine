#pragma once
#include <pch.hpp>
#include <Helpers.hpp>

namespace Epsilon
{
    namespace Console
    {

        static void Log_(std::string label, std::string message, const char *file, int line, const char *func)
        {
            std::cout << "CONSOLE::LOG =>"
                      << " From file: " << file << " => In function: " << func << " => From line: " << line << " TAG: " << Helpers::to_upper(label) << ": " << message << std::endl;
        }

#define Log(label, message) Log_(label, message, __FILE__, __LINE__, __FUNCTION__)
    }; // namespace Console
} // namespace Epsilon
