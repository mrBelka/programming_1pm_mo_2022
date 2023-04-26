#include "httplib.h"

int cnt = 0;

void f(const httplib::Request& req, httplib::Response& res)
{
	cnt++;
	std::cout << "Get request f" << std::endl;

	std::string s;
	s = "<html><body style=\"background-color:red\"><h1>Hello, world!</h1><a href=\"/main\">hi</a></body></html>";

	res.set_content(s, "text/html");
	return;
}

void g(const httplib::Request& req, httplib::Response& res)
{
	cnt++;
	std::cout << "Get request g" << std::endl;

	std::string s;
	s = "<html><body style=\"background-color:blue\"><h1>g</h1><a href=\"/hi\">hi</a></body></html>";

	res.set_content(s, "text/html");
	return;
}

int main()
{
	// HTTP
	httplib::Server svr;


	svr.Get("/hi", f);

	svr.Get("/main", g);

	svr.listen("192.168.1.15", 8080);

	return 0;
}