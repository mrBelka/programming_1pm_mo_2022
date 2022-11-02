#include <Car.hpp>
#include <iostream>
#define N 1

int main()
{
	mt::Car cars[N];
	for (int i = 0; i < N; i++)
	{
		std::string model;
		std::cin >> model;
		cars[i].SetModel(model);
		
		double acceleration;
		std::cin >> acceleration;
		cars[i].SetAcceleration(acceleration);

		int n;
		std::cin >> n;
		cars[i].SetPersonsQuantity(n);
	}

	for (int i = 0; i < N; i++)
	{
		cars[i].Info();
	}

	
	return 0;
}