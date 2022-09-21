#include <iostream>
//#define N 3  // не самое лучшее решение

int main()
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,0 };

	int mas[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int index = rand() % 10; //
		mas[i] = list[index];
	}

	for (int i = 0; i < 10; i++)
		std::cout << mas[i] << " ";

	/*// Многомерные массивы
	int matrix[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			std::cin >> matrix[i][j];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}*/

	//int m[2][2] = { {1,2}, {3,4} };

	/*int mas[10] = { 2,3,4,5,1,5 }; // Инициализация

	// Инициализация массива случайными числами
	srand(time(NULL));
	int mas_rand[1000];
	for (int i = 0; i < 1000; i++)
	{
		mas_rand[i] = rand(); // 0..32767
		mas_rand[i] = rand() % 10; // 0..9
		mas_rand[i] = rand() % 100 + 200; // 200..299
	}*/

	/*// Ввести n целых чисел (0 < n < 10000) и отсортировать по возрастанию


	const int N = 10000; // Более хорошее решение для определения констант
	int mas[N];		// Массивы фиксированный длины
	int digits[N];

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> mas[i];
		
		// Вытащить первую цифру
		int tmp = mas[i];
		while (tmp > 9)
			tmp /= 10;
		digits[i] = tmp;
		std::cout << digits[i] << std::endl;
	}

	// Сортировка обменами (swap sort)
	// треугольный цикл, (n^2)/2
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			// Сложный ключ
			if ((digits[i] > digits[j]) ||
				(digits[i] == digits[j] && mas[i] > mas[j]))
			{
				// обмен
				//std::swap(mas[i], mas[j]);
				int tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
				tmp = digits[i];
				digits[i] = digits[j];
				digits[j] = tmp;
			}

	for (int i = 0; i < n; i++)
		std::cout << mas[i] << std::endl;*/

	/*// Посчитать сумму цифр в числе
	// Алгоритм распаковки натурального числа
	int n = 12345;
	int sum = 0; // Инициализация

	while (n > 0)
	{
		int digit = n % 10;
		sum += digit;
		n /= 10; // n = n / 10
	}
	std::cout << sum << std::endl;

	// isPrime() isProst

	int x = 5;
	bool isPrime = true; // Предположение, что число простое
	// Пытаемся опровергнуть преположение
	for(int d=2;d<=sqrt(x);d++)
		if (x % d == 0)
		{
			isPrime = false;
			break;
		}
	if (isPrime)
		std::cout << "Prime" << std::endl;
	else
		std::cout << "Not prime" << std::endl;

	// Поиск максимума в последовательности натуральных чисел
	// последовательность целых чисел
	int N;
	std::cin >> N;
	int max = INT_MIN;  // 1

	// 2
	bool isFirstNumber = true;
	for (int i = 0; i < N; i++)
	{
		int a;
		std::cin >> a;
		if (isFirstNumber)
		{
			isFirstNumber = false;
			max = a;
		}

		if (a > max)
			max = a;
	}
	std::cout << max << std::endl;*/
}