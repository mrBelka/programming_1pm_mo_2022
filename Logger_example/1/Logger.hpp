#pragma once
#include <fstream>
#include <sstream>

namespace utils
{

    enum class Level
    {
        DEBUG,
        RELEASE
    };

    class Logger
    {

        static std::ofstream m_out;
        static Level m_level;

    public:
        static void SetLogFile(const std::string& path = "log.txt")
        {
            m_out.open(path);
        }

        static void SetLogLevel(Level level)
        {
            m_level = level;
        }

        static void Write(const std::string& msg)
        {
            if(m_level != Level::RELEASE) {
                std::cout << msg << std::endl;
                m_out << msg << std::endl;
            }
        }


    };

    std::ofstream Logger::m_out;
    Level Logger::m_level = Level::DEBUG;


    enum class LogType
    {
        INFO,
        DEBUG
    };

    class Log
    {
        std::stringstream m_ss;
        LogType m_logType;

    public:

        explicit Log(LogType logType) : m_logType(logType)
        {
            std::cout << "Constuctor" << std::endl;
        }

        ~Log()
        {

            switch (m_logType) {
                case LogType::INFO:
                    std::cerr << "[INFO]" << m_ss.str() << std::endl;
                case LogType::DEBUG:
                    std::cerr << "[DEBUG]" << m_ss.str() << std::endl;
            }
        }

        template<typename T>
        Log& operator<<(const T& t)
        {
            m_ss << t;
            return *this;
        }

    };
}

utils::Log logInfo()
{
    return utils::Log(utils::LogType::INFO);
}

utils::Log logDebug()
{
    return utils::Log(utils::LogType::DEBUG);
}