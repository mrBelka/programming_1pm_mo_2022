#include <iostream>

struct A
{
	A(int a, int b) {}
};

struct String
{
private:
	size_t m_size;
	char* m_str = nullptr;
	
public:
	// Конструктор по умолчанию
	String() = default;
	// Запрещенный конструктор
	String(int c, size_t size) = delete;

	// Конструктор (Неявное преобразование типов из int в char)
	String(char c, size_t size) : m_size(size), m_str(new char[size+1])
	{
		std::cout << "Constructor #1" << std::endl;
		std::fill(m_str, m_str + m_size, c); // memset
		m_str[m_size] = 0;
	}

	// Member initializer list (список инициализации членов класса)
	String(char* str) : m_size(strlen(str)), m_str(new char[m_size+1])
	{
		std::cout << "Constructor #2" << std::endl;
		std::copy(str, str+m_size, m_str); // memcpy
		m_str[m_size] = 0;
	}

	// Конструктор копирования + делегирующий конструктор
	String(const String& other) : String(other.m_str)
	{
		std::cout << "Copy Constructor" << std::endl;
	}

	String& operator=(String temp)
	{
		// Идиома Copy-and-swap
		std::cout << "Copy assigment operator" << std::endl;	
		std::swap(m_size, temp.m_size);
		std::swap(m_str, temp.m_str);
		return *this;
	}

	~String() {
		std::cout << "Destructor" << std::endl;
		if(m_str != nullptr)
			delete[] m_str;
	}

	size_t Size() const		// Константный метод
	{
		return m_size;
	}

	void Print() const
	{
		for (int i = 0; i < m_size; i++)
			std::cout << m_str[i];
	}
};

void f(String s)
{
	s.Print();
}

int main()
{
	String s1("Hello, world!");
	String s2("test");
	String s3("111");

	s3 = s2 = s1;

	s1.Print();
	s2.Print();
	s3.Print();

	return 0;
}