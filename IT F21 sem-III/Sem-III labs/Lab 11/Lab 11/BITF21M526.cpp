#include"iostream"
#include"string"

using namespace std;

class Employee
{
private:
	string firstname;
	string lastname;
	string ssn;

public:
	Employee(string firstname, string lastname, string ssn)
	{
		this->firstname = firstname;
		this->lastname = lastname;
		this->ssn = ssn;
	}

	string getFirstName()
	{
		return firstname;
	}

	string getLastName()
	{
		return lastname;
	}

	string getSSN()
	{
		return ssn;
	}

	void setFirstName(string firstname)
	{
		this->firstname = firstname;
	}

	void setLastName()
	{
		this->lastname = lastname;
	}

	void setSSN()
	{
		this->ssn = ssn;
	}

	virtual void print()
	{
		cout << "Name : " << firstname << "\t" << lastname << endl;
		cout << "SSN : " << ssn << endl;
	}


	virtual double earnings() = 0;

};

class SalariedEmployee : public Employee
{
private:
	double weeklySalary;

public:
	SalariedEmployee(string firstname="", string lastname = "", string ssn = "", double weeklysalary = 0) :Employee(firstname, lastname, ssn)
	{
		this->weeklySalary = weeklysalary;
	}

	double getWeeklySalary()
	{
		return weeklySalary;
	}
	
	void setWeeklySalary(double weeklySalary)
	{
		this->weeklySalary = weeklySalary;
	}

	void print()
	{
		this->Employee::print();
		cout << "Weekly salary: " << weeklySalary << endl;
	}

	double earnings()
	{
		return 4 * weeklySalary;
	}
};

class HourlyEmployee : public Employee
{
private:
	double wage;
	double hours;

public:
	HourlyEmployee(string firstname = "", string lastname = "", string ssn = "", double wage = 0, double hours = 0) :Employee(firstname, lastname, ssn)
	{
		this->wage = wage;
		this->hours = hours;
	}

	double getWage()
	{
		return wage;
	}

	void setWage(double wage)
	{
		this->wage = wage;
	}

	double getHours()
	{
		return hours;
	}

	void setHours(double hours)
	{
		this->hours = hours;
	}

	void print()
	{
		this->Employee::print();
		cout << "Wage: " << wage <<"\tHours = "<<hours<< endl;
	}

	double earnings()
	{
		return wage * hours;
	}

};


class CommissionEmployee :public Employee
{
private:
	double grossSales;
	double commissionRate;

public:
	CommissionEmployee(string firstname = "", string lastname = "", string ssn = "", double grossSales = 0, double commissionRate = 0) :Employee(firstname, lastname, ssn)
	{
		this->grossSales = grossSales;
		this->commissionRate = commissionRate;
	}


	double getGrossSales()
	{
		return grossSales;
	}

	void setGrossSales(double grossSales)
	{
		this->grossSales = grossSales;
	}

	double getCommissionRate()
	{
		return commissionRate;
	}

	void setCommissionRate(double commissionRate)
	{
		this->commissionRate = commissionRate;
	}

	void print()
	{
		this->Employee::print();
		cout << "GrossSales: " << grossSales << "\tCommissionRate = " << commissionRate << endl;
	}

	double earnings()
	{
		return grossSales * commissionRate;
	}
};

class BasePlusCommissionEmployee :public CommissionEmployee
{
private:
	double baseSalary;

public:
	BasePlusCommissionEmployee(string firstname = "", string lastname = "", string ssn = "", double grossSales = 0, double commissionRate = 0, double baseSalary=0) :CommissionEmployee(firstname, lastname, ssn, grossSales, commissionRate)
	{
		this->baseSalary = baseSalary;
	}

	double getBaseSalary()
	{
		return baseSalary;
	}

	void setBaseSalary(double baseSalary)
	{
		this->baseSalary = baseSalary;
	}

	void print()
	{
		this->CommissionEmployee::print();
		cout << "BaseSalary: " << baseSalary << endl;
	}

	double earnings()
	{
		return CommissionEmployee::earnings() + baseSalary;
	}
};


int main()
{
	
	SalariedEmployee s1("Zainab", "Zulfiqar", "21", 1000);
	HourlyEmployee h1("Muhammad", "Bilal", "22", 100.5,3);
	CommissionEmployee c1("Abdul", "Qadir", "23", 23,0.5);
	BasePlusCommissionEmployee b1("Rayyan", "Shabbir", "24", 25, 0.6,20);

	Employee* em[4];
	em[0] = &s1;
	em[1] = &h1;
	em[2] = &c1;
	em[3] = &b1;

	for (int i = 0; i < 4; i++)
	{
		em[i]->print();
		cout << "earnings() = " << em[i]->earnings() << endl << endl;
	}


	return 0;
}