#include <iostream>
#include <vector>

struct Granny
{
	int a = 1;
	virtual void f()
	{

	}
};

struct Mother : virtual Granny
{
	int a = 2;
	void f() override
	{
		std::cout << "Mother" << std::endl;
	}
};

struct Father : virtual Granny
{
	int a = 3;
	/*void f() override
	{
		std::cout << "Father" << std::endl;
	}*/
};

struct Son : public Father, public Mother
{
	int a = 4;
};

void h(Granny* g)
{
	Son* s = dynamic_cast<Son*>(g);
	if (s != nullptr)
	{
		// work
	}
	std::cout << s << std::endl;
}

int main()
{
	Mother* fp = new Mother();
	h(fp);


	/*Son* son = new Son();
	std::cout << son << std::endl;

	// dynamic_cast
	Father* fp = dynamic_cast<Father*>(son);
	std::cout << fp << " " << fp->a << std::endl;

	Mother* fm = dynamic_cast<Mother*>(son);
	std::cout << fm << " " << fm->a << std::endl;*/

	//Granny* g = dynamic_cast<Granny*>(son);
	


	//std::cout << sizeof(Son) << std::endl;

	return 0;
}