//Mishaal Aslam
//BITF21M526
//ITF21(Morning)
//Homework 1

#include "iostream"
#include "string"

using namespace std;

//Class
class Employee
{
private:
	string name;
	int id;
	string department;
	string position;

public:

	//Default Constructor
	Employee()
	{
		setName("");
		setId(0);
		setDepartment("");
		setPosition("");
		//cout << "Dafault Constructor '2' executed....." << endl;
	}


	//Parameterized Constructor '1'
	Employee(string employeeName, int idNumber, string depart, string posit)
	{
		setName(employeeName);
		setId(idNumber);
		setDepartment(depart);
		setPosition(posit);

		//cout << "Parameterized Constructor '1' executed....." << endl;
	}


	//Parameterized Constructor '2'
	Employee(string empName, int idNum)
	{
		setName(empName);
		setId(idNum);
		setDepartment("");
		setPosition("");

		//cout << "Parameterized Constructor '2' executed....." << endl;
	}


	//Copy Constructor
	Employee(const Employee  &obj)
	{
		setName(obj.name);
		setId(obj.id);
		setDepartment(obj.department);
		setPosition(obj.position);

		//cout << "Copy Constructor executed....." << endl;
	}


	//Setters
	//1.setname
	void setName(string nameEmp)
	{
		name = nameEmp;
	}

	//2.setid
	void setId(int idnmbr)
	{
		if (idnmbr > 0)
		{
			id = idnmbr;
		}
		else
		{
			id = 0;
		}
	}

	//3.setDapartment
	void setDepartment(string depart)
	{
		department = depart;
	}

	//4.getPosition
	void setPosition(string posit)
	{
		position = posit;
	}


	//Getters
	//1.getname
	string getName()
	{
		return name;
	}

	//2.getid
	int getId()
	{
		return id;
	}

	//3.getDapartment
	string getDepartment()
	{
		return department;
	}

	//4.getPosition
	string getPosition()
	{
		return position;
	}


	//setinfo function for setting data
	void setInfo(string nameEmployee,int idEmployee,string departEmployee,string positEmployee)
	{
		setName(nameEmployee);
		setId(idEmployee);
		setDepartment(departEmployee);
		setPosition(positEmployee);
	}


	//getinfo function for getting data from user
	void getInfo()
	{
		string nameEmployee, departEmployee, positEmployee;
		int idEmployee;

		cout << "Enter name of Employee: ";
		getline(cin, nameEmployee);
		setName(nameEmployee);

		cout << "Enter id of Employee: ";
		cin >> idEmployee;
		setId(idEmployee);

		cout << "Enter department of Employee: ";
		cin.ignore();
		getline(cin, departEmployee);
		setDepartment(departEmployee);

		cout << "Enter position of Employee: ";
		getline(cin, positEmployee);
		setPosition(positEmployee);
	}


	//putinfo function for displaying data
	void putInfo()
	{
		cout << name << "\t" << id << "\t" << department << "\t" << position << endl;
	}


	//Destructor
	~Employee()
	{
		cout << "Destructor executed....." << endl;
	}
};


int main()
{
	
	Employee per1("Umair Babar", -1, "PUCIT", "Assistant Professor"), per2; 
	per2.getInfo();

	Employee per3(per2), per4("Ayesha", 10),per5;
	per4.setDepartment("IBA");
	per4.setPosition("Professor");

	per2.setName("Usman");
	per2.setPosition("Student");
	per5.getInfo();

	//Displaying Table
	cout << "\nName \t ID \t Department \t Position " << endl;

	cout << per1.getName() << "\t" <<per1.getId() << "\t" << per1.getDepartment() <<"\t" << per1.getPosition() << endl;
	per2.putInfo();
	per3.putInfo();
	per4.putInfo();
	per5.putInfo();

	cout << "\n";

	return 0;
}