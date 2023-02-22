#include <iostream>

// 1.
template<typename T, typename U> // !!!!!
void swap(T& a, U& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// 2.
template<typename T, int N, int M>
class Matrix
{
	T m_matrix[N][M];
public:
	void Print()
	{
		std::cout << N << " " << M << std::endl;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				std::cout << m_matrix[i][j];
	}

	double determinant()
	{
		if (N == 2 && M == 2)
		{

		}
		else if (N == 3 && M == 3)
		{
			m_matrix[2][2];
		}
	}
};

using Matrix22i = Matrix<int, 2, 2>; // typedef
using Vector2i = Matrix<int, 2, 1>;

// 3. Специализация шаблонов
template<class T>
class vector
{
public:
	vector()
	{
		std::cout << "all types without bool" << std::endl;
	}
};

template<>
class vector<bool>
{
public:
	vector()
	{
		std::cout << "only bool" << std::endl;
	}
};

struct RRR
{

};

int main()
{
	vector<RRR> v;


	Matrix22i M;
	//M.Print();


	int a = 5;
	double b = 10;
	swap(a, b);
}