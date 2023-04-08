#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

// 1. unique_ptr
// только 1 указатель

template<typename T>
struct SmartPointer
{
private:
	T* p;
	int* count;
public:
	SmartPointer(int n) : p(new T), count(new int(1))
	{
		p = new int[n];
		std::cout << "constr";
	}
	SmartPointer(const SmartPointer&) = delete;
	SmartPointer& operator=(const SmartPointer&) = delete;

	~SmartPointer()
	{
		if (*count == 1)
		{
			delete[] p;
			std::cout << "destr";
		}
	}
};

void f(int x)
{
	// RAII = Resource Acquition Is Initialization
	//SmartPointer p(100);
	//int* p = new int[100]; // p - на стеке, 
	// p указывает на область памяти в хипе
	if (x == 0)
	{
		//delete[] p;
		throw std::exception("some...");
	}

	//delete[] p;

}

struct Student;

struct Teacher
{
	std::weak_ptr<Student> m_student;
	Teacher(std::shared_ptr<Student>& student)
	{
		m_student = student;
	}
	~Teacher()
	{
		std::cout << "Teacher destr " << m_student.use_count() << std::endl;
	}
};

struct Student
{
	std::string name = "Pasha";
	std::shared_ptr<Teacher> m_teacher;
	Student()
	{
	}
	void Setup(std::shared_ptr<Teacher>& teacher)
	{
		m_teacher = teacher;
	}
	~Student()
	{
		std::cout << "Student destr " << m_teacher.use_count() << std::endl;
	}
};

int main()
{
	auto student = std::make_shared<Student>();
	auto teacher = std::make_shared<Teacher>(student);
	student->Setup(teacher);

	std::cout << teacher.use_count() << " " << student.use_count() << std::endl;

	return 0;
}