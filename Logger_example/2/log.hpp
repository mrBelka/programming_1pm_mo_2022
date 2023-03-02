#pragma once
#include <fstream>
#include <iostream>

enum class LogLevel
{
	DEBUG,
	RELEASE
};

class Log
{
private:
	static std::ofstream m_out; // RAII
	static LogLevel m_logLevel;
public:
	Log()
	{
		std::cout << "Constr" << std::endl;
	}
	static void SetLogLevel(LogLevel logLevel)
	{
		m_logLevel = logLevel;
	}
	static void SetLogPath(const std::string& path)
	{
		m_out.open(path);
	}
	// Статический метод
	static void Write(const std::string& msg)
	{
		// Время
		// Раскрашивать консоль
		if(m_logLevel == LogLevel::DEBUG)
			std::cerr << msg << std::endl;
		m_out << msg << std::endl;
		m_out.flush();
		//m_out.flush(); // сбросить в файл все что есть в буфере
	}
	static void Info(const std::string& msg)
	{
		// Время
		// Раскрашивать консоль
		if (m_logLevel == LogLevel::DEBUG)
			std::cerr << msg << std::endl;
		m_out << msg << std::endl;
		m_out.flush();
		//m_out.flush(); // сбросить в файл все что есть в буфере
	}
	~Log()
	{
		std::cout << "Destr" << std::endl;
	}
};