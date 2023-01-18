#include <iostream>

#pragma pack(1)
class A
{
	long long a = 1;
	long long c = 2;
	char b = 3;
};
#pragma pack()

struct String
{
private:
	size_t m_size;
	char* m_str;
	mutable int m_counter = 0;
public:
	String(char* str)
	{
		m_size = strlen(str); // '\0'
		m_str = new char[m_size+1];
		std::copy(str, str+m_size+1, m_str); // memcpy
	}

	explicit String(char c, size_t size)  // Неявное преобразование типов из int в char
	{
		m_size = size;
		m_str = new char[size];
		for (int i = 0; i < m_size; i++)
			m_str[i] = c;
	}

	size_t Size() const		// Константный метод
	{
		return m_size;
	}

	void Print() const
	{
		m_counter++;
		std::cout << m_counter << std::endl;
		std::cout << m_str << std::endl;
	}
};

//int numOfVoices(const std::string& s) // std::string& s = str;
//{
	//s[2] = '2';
//}

int main()
{
	A a;
	std::cout << (int)*(char*)((long long*)&a + 2) << std::endl;

	std::cout << sizeof(A) << std::endl;

	String s(1000.0,5);  
	s.Print();
	std::cout << s.Size() << std::endl;

	/*const int n = 12;
	//n = 12;
	//std::cin >> n;
	//int mas[n]; // Не надо

	// Указатели
	const int* p = &n;	// Указатель на константу
	//*p = 10;
	//p += 1;
	
	int x = 10;
	int* const pp = &x;	// Константный указатель
	//*pp = 12;
	//pp += 1;

	const int* const p3 = &n; // Константный указатель на константу
	//*p3 = 13;
	//p3++;

	const int& y = n; // Ссылка на константу (говорят, Константная ссылка)
	//int& y = n; // Константная ссылка

	int t = 10;

	int& link = x; // инициализация link
	link = t; // x = t;

	//std::cout << sizeof(p) << std::endl;

	std::string str("BIG STRING");
	numOfVoices(str);*/

	return 0;
}