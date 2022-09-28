#include <iostream>
#include <string>
#include <fstream>

int main()
{
	/*char c;
	//std::cin >> c;
	//std::cout << (int)c; // преобразовать символ c в целое число int

	scanf_s("%hhd", &c); // спецификатор, адрес переменной с
	//printf("%d", c);

	std::cout << (int)c;

	// (int)c - c-style,
	// int a = 1000;
	// char b = (char)a;
	std::cout << static_cast<int>(c);

	char a = '0';
	if ('a' < 'b') // 48 < 49
	{
		std::cout << "a < b" << std::endl;
	}

	//char c = 11; // char c = 'a'; char c = 97;
	//std::cout << c;

	char str[14] = "Hello, world!";
	//str[4] = '\0'; // = 0;
	std::cout << strlen(str); // Длина строки
	if (strlen(str) > 10)
	{
		std::cout << "Big string";
	}*/
	// Конкатенация

	/*char a[100] = "Hello, ";
	char b[100] = "world!";
	strcat_s(a, b);
	std::cout << a << std::endl;

	// Копирование строк
	strcpy_s(a, b);
	std::cout << a << std::endl;

	for (int i = 0; i < strlen(a) + 5; i++)
	{
		std::cout << static_cast<int>(a[i]) << " ";
	}*/

	/*char s1[2];
	char s2[14] = "Hello, world!";
	strcpy_s(s1, s2);
	std::cout << s1;*/

	/*char a[5] = "abc";
	char b[5] = "aba";
	std::cout << strcmp(a, b) << std::endl;*/

	/*// Как считать строку?
	char str[100];
	//std::cin >> str; // Считывает до пробела
	gets_s(str, 100);  // Считать строку до символа '\n'
	std::cout << str;*/

	// Файловый ввод-вывод
	/*char str[100];  // '\n'
	std::ifstream in("input.txt", std::ios::in); // имя файла и спецификатор (для чтения)
	//in >> str; // Считывает до пробела
	//in.getline(str, 100);

	std::ofstream out("output.txt", std::ios::out);
	
	while (!in.eof())
	{
		in.getline(str, 100);
		out << str << '\n';
	}*/

	/*// Дана строка из строчных букв, преобразовать ее буквы в заглавные
	char str[100] = "abc";
	for (int i = 0; i < strlen(str); i++)
		str[i] -= 32;

	std::cout << str;*/

	/*// Посчитать количество гласных букв в слове
	char str[100] = "abcdefghij";
	char volwes[7] = "aeioyu";
	int cnt = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		//if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i')
		//	i++;
		for(int j=0;j<strlen(volwes);j++)
			if (str[i] == volwes[j])
			{
				cnt++;
				break;
			}
	}*/

	// std::string
	// #include <string>

	/*std::string s = "Hello, world!";
	std::string s1 = "H";
	std::string s2 = "e";
	std::cout << s1 + s2 << std::endl;
	s1 = s2;
	std::cout << s1;*/

	/*std::string s = "abcdefghij";
	std::string volwes = "aeioyu";
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		std::cout << volwes.find(s[i]) << std::endl;
		if (volwes.find(s[i]) != std::string::npos)
			cnt++;
	}
	std::cout << cnt;*/

	std::string s = "abcdefghij";
	std::string volwes = "aeioyu";
	int cnt = 0;
	for (int i = 0; i < volwes.length(); i++)
	{
		std::cout << s.find(volwes[i]) << std::endl;
		//if (volwes.find(s[i]) != std::string::npos)
		//	cnt++;
	}
	//std::cout << cnt;

	std::string subs = s.substr(0, 3);
	std::cout << subs;

	std::ifstream in("input.txt", std::ios::in);
}