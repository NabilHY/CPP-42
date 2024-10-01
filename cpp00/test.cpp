#include <iostream>

class AbstractEmployee
{
	virtual void promoteEmployee() = 0;
};

class Employee : AbstractEmployee
{
	// Attributes
  private:
	std::string Name;
	std::string Company;
	int Age;

  public:
	// Behavior
	Employee()
	{
		Age = 9999;
		Name = "John Doe";
		Company = "Morgue";
	}
	Employee(std::string name, std::string company, int age)
	{
		Name = name;
		Company = company;
		Age = age;
	}
	void promoteEmployee()
	{
		if (Age >= 25)
			std::cout << "Elegible for a promotion\n";
		else
			std::cout << "Not Elegible\n";
	}
	void displayInfo()
	{
		std::cout << 
	}
	void setName(std::string name)
	{
		Name = name;
	}
	std::string getName()
	{
		return (Name);
	}
	void setAge(int age)
	{
		Age = age;
	}
	int getAge()
	{
		return (Age);
	}
	void info()
	{
		std::cout << "Name " << Name << std::endl;
		std::cout << "Company " << Company << std::endl;
		std::cout << "Age " << Age << std::endl;
	}
	// Constructor
};

int	main(void)
{
	Employee	employee1;
	Employee	employee2;

	employee1 = Employee("Nabil", "Oracle", 25);
	employee2 = Employee("Jeffrey", "Meta", 18);
	//std::cout << employee1.getName() << std::endl;
	//employee1.promoteEmployee();
	employee1.displayInfo();
	return (0);
}

/* Encapsulation
	Encapsulation is one of the fundamental concepts in object-oriented programming (OOP). It refers to the bundling of data,
		and the methods that operate on that data,
		into a single unit known as a class. In C++,
		this is achieved by using classes.
*/