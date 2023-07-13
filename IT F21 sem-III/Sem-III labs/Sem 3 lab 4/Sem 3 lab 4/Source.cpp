//Lab 04

#include "iostream"
#include "string"

using namespace std;


class Car
{

private:
	int yearModel;
	string make;
	int speed;

public:

	//Parameterized Constructor
	Car(int yModel, string carMake)
	{
		yearModel = yModel;
		make = carMake;
		speed = 0;
	}

	//copy Constructor
	Car(const Car &obj2)
	{
		yearModel = obj2.yearModel;
		make = obj2.make;
		speed = obj2.speed;
	}

	//Accessor
	//1. getYear
	int getYearModel()
	{
		return yearModel;
	}

	//2.getMake
	string getMake()
	{
		return make;
	}

	//3. getSpeed
	int getSpeed()
	{
		return speed;
	}

	//Mutator
	//1. setYearModel
	void setYearModel(int model)
	{
		if (model > 0)
		{
			yearModel = model;
		}
		else
		{
			yearModel = 0;
		}
	
	}

	//2.getMake
	void setMake(string making)
	{
		make = making;
	}

	//3. setSpeed
	void setSpeed(int carSpeed)
	{
		if (carSpeed >= 0)
		{
			speed = accelerator(carSpeed);
		}
		else
		{
			speed = 0;
		}

	}

	//setCar
	void setCar(int model,string mak,int sp)
	{
		setYearModel(model);
		setMake(mak);
		setSpeed(sp);
	}

	//getCar
	void getCar()
	{
		int yMod,sp;
		string maKe;

		cout << "Enter Year Model of Car: ";
		cin >> yMod;
		setYearModel(yMod);

		cout << "Enter Make of Car: ";
		cin.ignore();
		getline(cin, maKe);
		setMake(maKe);

		cout << "Enter speed of Car: ";
		cin >> sp;
		setSpeed(sp);
	}

	//putCar
	void putCar()
	{
		cout << yearModel << "\t" << make << "\t" << speed << endl;
	}

	//Accelerator
	int accelerator(int sp)
	{
		return speed = sp + 5;
	}

	//Break
	void brake(int sp)
	{
		speed = sp - 5;
	}

	//Destructor
	~Car()
	{
		cout << "Destructor executed...." << endl;
	}
};





int main()
{
	Car obj1(2021,"Suzuki Alto");
	Car obj2(2015,"Toyota Camry");
	Car obj3(2011, "Honda Accord");
	Car obj4(2012, "Toyota Prius");
	Car obj5(2018, "Daihatsu Boon");

	//Car obj(obj1);

	obj1.setSpeed(40);
	obj2.setSpeed(45);
	obj3.setSpeed(80);
	obj4.setSpeed(87);
	obj5.setSpeed(55);

	cout << "YearModel \t Make \t Speed" << endl;


	//obj.putCar();

	obj1.putCar();
	obj2.putCar();
	obj3.putCar();
	obj4.putCar();
	obj5.putCar();
	
	cout << " " << endl;


	return 0;
}