#include "httplib.h"

int main()
{
	// HTTP
	httplib::Client cli("localhost:8080");

	auto res = cli.Post("/hi", "2 2", "text/plain");

	std::cout << res << std::endl;
	if (res == nullptr)
		return -1;

	std::cout << res->status << std::endl;
	std::cout << res->body << std::endl;

	return 0;
}