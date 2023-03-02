#include <iostream>
#include "log.hpp"
#include <vector>

int main()
{
	Log::SetLogPath("log.txt");
	Log::SetLogLevel(LogLevel::RELEASE);


	Log::Info("11111111111111");
	Log::Debug("11111111111111");
	Log::Write("11111111111111");
	Log::Write("11111111111111");

	return 0;
}