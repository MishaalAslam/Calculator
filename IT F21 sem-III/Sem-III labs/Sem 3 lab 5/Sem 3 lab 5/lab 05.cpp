#include "iostream"
#include "string"

using namespace std;


class Student
{
private:
	int regNo;
	string firstName;
	string lastName;
	string program;
	float cgpa;

public:
	void setRegNo(int rNo)
	{
		if (rNo >= 501 && rNo <= 565)
		{
			regNo = rNo;
		}
		else
		{
			regNo = 0;
		}
	}

	void setFirstName(string fName)
	{
		firstName = fName;
	}

	void setLastName(string lName)
	{
		lastName = lName;
	}

	void setProgram(string prog)
	{
		program = prog;
	}

	void setCgpa(float st_cgpa)
	{
		if (st_cgpa >= 0.00 && st_cgpa <= 4.00)
		{
			cgpa = st_cgpa;
		}
		else
		{
			cgpa = -1;
		}
		
	}

	
	int getRegNo()
	{
		return regNo;
	}

	string getFirstName()
	{
		return firstName;
	}

	string getLastName()
	{
		return lastName;
	}

	string getProgram()
	{
		return program;
	}

	float getCgpa()
	{
		return cgpa;
	}

	Student(int st_regNo, string fName, string lName, string prog)
	{
		setRegNo(st_regNo);
		setFirstName(fName);
		setLastName(lName);
		setProgram(prog);
		setCgpa(-1);
	}

	Student(int st_regNo, string fName, string prog)
	{
		setRegNo(st_regNo);
		setFirstName(fName);
		setLastName("");
		setProgram(prog);
		setCgpa(-1);
	}

	Student(int st_regNo, string fName, string lName, string prog,float st_cgpa)
	{
		setRegNo(st_regNo);
		setFirstName(fName);
		setLastName(lName);
		setProgram(prog);
		setCgpa(st_cgpa);
	}

	Student(const Student &st)
	{
		regNo = st.regNo;
		firstName = st.firstName;
		lastName = st.lastName;
		program = st.program;
		cgpa = st.cgpa;
	}

	~Student()
	{
		cout << "Destructor executed....";
	}


	void setStudent(int st_regNo, string fName, string lName, string prog, float st_cgpa)
	{
		setRegNo(st_regNo);
		setFirstName(fName);
		setLastName(lName);
		setProgram(prog);
		setCgpa(st_cgpa);
	}

	void readInput()
	{
		int st_regNo;
		string fName, lName, prog;
		float st_cgpa;

		cout << "Enter registration Number: ";
		cin >> st_regNo;
		setRegNo(st_regNo);

		cin.ignore();

		cout << "Enter First Name: ";
		getline(cin, fName);
		setFirstName(fName);

		//cin.ignore();

		cout << "Enter Last Name: ";
		getline(cin, lName);
		setLastName(lName);

		//cin.ignore();
		//cin.ignore();

		cout << "Enter Program: ";
		getline(cin, program);
		setProgram(prog);

		//cin.ignore();

		cout << "Enter CGPA: ";
		cin >> st_cgpa;
		setCgpa(st_cgpa);
	}

	void writeData()
	{
		cout << "Registration Number = "<<regNo << "\t\tFirst Name = " << firstName << "\t\tLast Name = " << lastName << "\t\tProgram = " << program << "\t\tCGPA = " << cgpa << endl;
	}

	bool isFirstSemester()
	{
		if (cgpa == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	float getPercentage()
	{
		float cgpaPer = 0;
		if (cgpa >= 0.0)
		{
			cgpaPer = cgpa / 4.00;
			cgpaPer = cgpaPer * 100;

			return cgpaPer;
		}
		else
		{
			return -1;
		}
	}

	bool isPromoted()
	{
		if (cgpa >= 2.00)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


};






int main()
{

	Student st1(526,"Mishaal","Aslam","IT",3.93);
	Student st2(512, "Adeena", "Tanveer", "IT");
	Student st3(st2);
	Student st4(551,"Afroza ","IT");

	st4.readInput();

	st3.setRegNo(504);
	st3.setFirstName("Sameen");
	st3.setLastName("Shahzad");
	st3.setCgpa(3.88);


	//Student 01
	cout << "\n";
	st1.writeData();
	
	cout << st1.getPercentage() << "\t\t";

	if (st1.isFirstSemester() == 1)
	{
		cout << "First sem student\t\t";
	}
	else
	{
		cout << "Not a First sem student\t\t";
	}
	
	if (st1.isPromoted() == 1)
	{
		cout << "Yes Promoted\n" << endl;
	}
	else
	{
		cout << "Not Promoted\n" << endl;
	}
	

	//Student 02
	st2.writeData();

	cout << st2.getPercentage() << "\t\t";

	if (st2.isFirstSemester() == 1)
	{
		cout << "First sem student\t\t";
	}
	else
	{
		cout << "Not a First sem student\t\t";
	}

	if (st2.isPromoted() == 1)
	{
		cout << "Yes Promoted\n" << endl;
	}
	else
	{
		cout << "Not Promoted\n" << endl;
	}


	//Student 03
	cout << st3.getRegNo() << "\t\t" << st3.getFirstName() << "\t\t" << st3.getLastName() << "\t\t" << st3.getProgram() << "\t\t" << st3.getCgpa() << "\t\t" << st3.getPercentage() << endl;
	if (st3.isFirstSemester() == 1)
	{
		cout << "First sem student\t\t";
	}
	else
	{
		cout << "Not a First sem student\t\t";
	}

	if (st3.isPromoted() == 1)
	{
		cout << "Yes Promoted\n" << endl;
	}
	else
	{
		cout << "Not Promoted\n" << endl;
	}


	//Student 4
	st4.writeData();

	cout << st4.getPercentage() << "\t\t";

	if (st4.isFirstSemester() == 1)
	{
		cout << "First sem student\t\t";
	}
	else
	{
		cout << "Not a First sem student\t\t";
	}

	if (st4.isPromoted() == 1)
	{
		cout << "Yes Promoted\n" << endl;
	}
	else
	{
		cout << "Not Promoted\n" << endl;
	}




	return 0;
}