#pragma once

#include <pch.hpp>

#include <time.h>


namespace Epsilon {

    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    static const std::string currentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        //tstruct = *localtime(&now);
        std::tm bt{};
#if defined(__unix__)
        localtime_r(&now, &tstruct);
#elif defined(_MSC_VER)
        localtime_s(&tstruct, &now);
#else
        static std::mutex mtx;
        std::lock_guard<std::mutex> lock(mtx);
        tstruct = *std::localtime(&now);
#endif
        // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
        // for more information about date/time format
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

        return buf;
    }

    class Log
    {
    public:
        static void OpenFile(std::string path)
        {
            sOutFile.open(path.c_str());
        }

        static void WriteToLog(std::string logmesage, uint8_t dest = FILE)
        {
            if(dest & FILE){
                sOutFile << currentDateTime() << ":  " << logmesage << std::endl;
            }
            if(dest & CONSOLE) {
                std::cout << currentDateTime() << ":  " << logmesage << std::endl;
            }
            if(dest & CERROR) {
                std::cerr << currentDateTime() << ":  " << logmesage << std::endl;
            }
        }

        static const unsigned FILE =     0x00000001;
        static const unsigned CONSOLE =  0x00000010;
        static const unsigned CERROR =    0x00000100;

        static std::ofstream sOutFile;
    };
}

