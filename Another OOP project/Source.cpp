#include <iostream>
#include <string>
#include <iterator>
#include <vector>

// ������ 1.
class Person 
{
protected: // ��� �� ����� ��������� ��������� ���������.
	std::string name;
	int age;
public:
	Person(std::string name, int age)
	{
		this->name = name; // ��� ���������� ��� ��������� ��� ���. ��� ������� ����, ��� ���� ���������� ���������. (this->)
		this->age = age; // ��� ���������� ��� ��������� ��� ���. ��� ������� ����, ��� ���� ���������� ���������. (this->)
	}

	virtual void ShowData() = 0; // ���� �������� � ��� ���������� ���� � ������ �������� �� ����� ��������� (Virtual), ��� �� � ����������� ����� ��������.

};

class Student : public Person // ��� ���� � ������ ����������� ���������.
{
private:
	std::vector <int> _marks;
public:
	Student(std::string name, int age, std::vector <int>& marks) : Person (name,age)
	{
		_marks = marks;
	}

	void ShowData() override // (override) ��� ��� ����� �������� � �������, �� ��� ��� �����.
	{
		std::cout << "Name: " << name << "\n";
		std::cout << "Age: " << age << "\n";
		std::cout << "Marks: ";
		for (const auto& it : _marks)
			std::cout << it << ". ";
	}
};

class Proffecor : public Person
{
private:
	std::string _degree;
public:
	Proffecor(std::string name, int age, std::string degree) : Person(name, age)
	{
		_degree = degree;
	}

	void ShowData() override
	{
		std::cout << "Name: " << name << "\n";
		std::cout << "Age: " << age << "\n";
		std::cout << "Degree: " << _degree << "\n";
	}
};

// ������ 2.

class Worker
{
private:
	std::string _name;
	int _age;
	float _bill;
public:
	Worker(std::string name, int age) : _name(name), _age(age) {} // _bill(0)  ����� ����� Geterov.

	virtual void Work() = 0; // ������ ����������� �������.

	void Bill(int hoursOfWork)
	{
		_bill = 250.0f * hoursOfWork;
		std::cout << "Bill: " << _bill << "\n";
	}

	// ����� ����� Geterov.

	/*
	std::string GetName() {
		return _name;
	}

	int GetAge() {
		return _age;
	}

	float GetBill() {
		return _bill;
	}
	*/
};

class Buyer : public Worker
{
public: 
	Buyer(std::string name, int age) : Worker(name, age) {}

	void Work() override
	{
		// std::cout << GetName() << " - " << GetAge()<< " years old" << ": " << "is buying something: " << "\n"; ����� ����� Geterov.
		std::cout << "Buying something: " << "\n";
	}
};

class Builder : public Worker
{
public:
	Builder(std::string name, int age) : Worker (name, age) {}

	void Work() override 
	{
		// std::cout << GetName() << " - " << GetAge() << " years old" << ": " << "is Building something: " << "\n"; ����� ����� Geterov.
		std::cout << "Building something: " << "\n";
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	// ������ 1.
	/*std::vector <int> marks = { 12, 5, 7, 4, 7, 3 };
	Student student("John" , 29, marks);
	Proffecor proffecor ("Alex", 18 , "Doctor");
	std::cout << "Student: " << "\n";
	student.ShowData();
	std::cout << "\n\nProffecor: " << "\n";
	proffecor.ShowData();*/

	Buyer buy("John", 20);
	Builder build("Alex", 34);
	buy.Work();
	buy.Bill(20);
	std::cout << std::endl;
	build.Work();
	build.Bill(30);


	return {};
}