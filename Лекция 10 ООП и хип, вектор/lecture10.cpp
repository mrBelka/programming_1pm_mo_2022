#include <iostream>
#include <vector>

/*class String
{
private:
	int m_size;
	char* m_str;
public:
	String(char* str)
	{
		strcpy(m_str, str);
		m_size = strlen(str);
	}
};*/

class Patient
{
private:
	unsigned int m_id;
	std::string m_name;

public:
	Patient(int id, std::string name)
	{
		m_id = id;
		m_name = name;
	}

	std::string Name()
	{
		return m_name;
	}
};

class Doctor
{
private:
	unsigned int m_id;
	std::string m_name;
	std::vector<Patient*> m_patients;

public:
	Doctor(int id, std::string name)
	{
		m_id = id;
		m_name = name;
	}

	void AddPatient(Patient*& patient)
	{
		std::cout << "2 " << patient << std::endl;
		patient = nullptr;
		std::cout << "3 " << patient << std::endl;
		//m_patients.push_back(patient);	
	}

	void PrintPatient()
	{
		for (size_t i = 0; i < m_patients.size(); i++)
			std::cout << m_patients[i]->Name() << std::endl;
	}
};

int main()
{
	//Doctor doctor(0, "Pavel");
	//Patient patient1(0, "Pasha");
	//Patient patient2(1, "Petr");

	Doctor* doctor = new Doctor(0, "Pavel");

	doctor->PrintPatient();

	Patient* patient1 = new Patient(1, "Pasha");

	std::cout << "1 " << patient1 << std::endl;

	doctor->AddPatient(patient1);

	std::cout << "4 " << patient1 << std::endl;

	doctor->PrintPatient();

	std::cout << sizeof(*patient1) << std::endl;

	/*int a = 5, b = 10;
	std::swap(a, b);

	double c = 1.2, d = 5.8;
	std::swap(c, d);

	std::swap(a, c);*/

	delete doctor;

	return 0;
}