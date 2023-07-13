//Mishaal Aslam
//BITF21M526
//BSIT F21(Morning)
//#Hw-07(Inheritance)

#include"iostream"
#include"string"

using namespace std;

//Base class
class Package
{
private:
	string s_name;						// s-> sender
	string r_name;						// r-> receiver
	string s_address;
	string r_address;
	string s_city;
	string r_city;
	float weight;
	float costPerOunce;
public:
	//Constructor
	Package(string s_name, string r_name , string s_address, string r_address, string s_city,string r_city,float weight,float costPerOunce)
	{
		this->s_name = s_name;
		this->r_name = r_name;
		this->s_address = s_address;
		this->r_address = r_address;
		this->s_city = s_city;
		this->r_city = r_city;
		if (weight > 0)
		{
			this->weight = weight;
		}
		else {
			this->weight = 0;
		}
		if (costPerOunce > 0)
		{
			this->costPerOunce = costPerOunce;
		}
		else {
			this->costPerOunce = 0;
		}
	}

	//calculateCost() member function
	float calculateCost()
	{
		return costPerOunce * weight;
	}
	void display()
	{
		cout << s_name << "\t" << r_name<< "\t" << s_address<< "\t" << r_address<< "\t" << s_city<< "\t" << r_city<< "\t" << weight<< "\t" << costPerOunce;
	}
};

//Derive class-1
class TwoDayPackage : public Package
{
private:
	float flatFee;

public:
	//Constructor
	TwoDayPackage(string s_name, string r_name, string s_address, string r_address, string s_city, string r_city, float weight, float costPerOunce, float flatFee) :Package(s_name,r_name,s_address, r_address,s_city, r_city,  weight,costPerOunce)
	{
		this->flatFee = flatFee;
	}

	//calculateCost() member function
	float calculateCost()
	{
		return Package::calculateCost() + flatFee;
	}

	void display()
	{
		Package::display();
		cout << "\t"<<flatFee;
	}
};

//Derive class-2
class OverNightPackage : public Package
{
private:
	float feePerOunce;

public:
	//Constructor
	OverNightPackage(string s_name, string r_name, string s_address, string r_address, string s_city, string r_city, float weight, float costPerOunce, float feePerOunce) :Package(s_name,r_name,s_address, r_address,s_city, r_city,  weight,costPerOunce)
	{
		this->feePerOunce = feePerOunce;
	}

	//calculateCost() member function
	float calculateCost()
	{
		return Package::calculateCost() + feePerOunce;
	}

	void display()
	{
		Package::display();
		cout << "\t" << feePerOunce;
	}
};

int main()
{
	OverNightPackage o1("Mishaal Aslam", "Muhammad Aslam", "Lahore", "SDK RYK","Pakistan","Pakistan",21,2,10);
	o1.display();
	cout << endl << o1.calculateCost() << endl;

	return 0;
}