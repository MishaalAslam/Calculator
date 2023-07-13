//Mishaal Aslam
//Lab 10
//Carpet Calculator

#include"iostream"

using namespace std;

class FeetInches
{
private:
	int feet;			// To hold a number of feet
	int inches;			// To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches& right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator + (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator - (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator * (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator ++ ()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator ++ (int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator -- ()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator -- (int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator > (const FeetInches& right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator < (const FeetInches& right)
	{
		return !(*this > right);
	}

	bool operator >= (const FeetInches& right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator <= (const FeetInches& right)
	{
		return !(*this >= right);
	}

	bool operator == (const FeetInches& right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator != (const FeetInches& right)
	{
		return !(*this == right);
	}

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);
};

ostream& operator << (ostream& out, const FeetInches& obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator >> (istream& in, FeetInches& obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

class RoomDimension
{
private:
	FeetInches length;
	FeetInches width;

public:
	//Mutators
	void setLength(FeetInches length)
	{
		//this->length.setInches(length.getInches());
		//this->length.setFeet(length.getFeet());
		this->length = length;
	}
	void setWidth(FeetInches width)
	{
		//this->width.setInches(width.getInches());
		//this->width.setFeet(width.getFeet());
		this->width = width;
	}

	//Accessors
	FeetInches getLength()
	{
		//return FeetInches(length.getInches(),length.getFeet());
		return length;
	}
	FeetInches getWidth()
	{
		//return FeetInches(width.getInches(), width.getFeet());
		return width;
	}

	//Constructor
	RoomDimension(FeetInches length, FeetInches width): length(length)
	{
		setLength(length);
		setWidth(width);
	}

	FeetInches getArea()
	{
		//return FeetInches(length.getInches()*width.getInches(),length.getFeet() * width.getFeet());
		return (length * width);
	}

	void display()
	{
		cout << "length : " << length << "width : " << width << endl;
	}
};

class RoomCarpet
{
private:
	RoomDimension roomSize;
	float costPerSquareFoot;

public:
	//Getters
	RoomDimension getRoomSize()
	{
		return roomSize;
	}

	float getCostPerSquareFoot()
	{
		return costPerSquareFoot;
	}

	//Setters
	void setRoomSize(RoomDimension roomsize)
	{
		this->roomSize = roomsize;
	}

	void setCostPerSquareFoot(float costPerSquareFoot)
	{
		this->costPerSquareFoot = costPerSquareFoot;
	}

	RoomCarpet(RoomDimension roomsize, float costPerSquareFoot):roomSize(roomsize)
	{
		setCostPerSquareFoot(costPerSquareFoot);
	}
	
	//Member function to caculate Total cost 
	float getTotCost()
	{
		//return costPerSquareFoot * roomSize.getArea();
		return costPerSquareFoot * roomSize.getArea().getFeet();
	}


	void print()
	{
		cout <<endl<< "roomSize : " ;
		roomSize.display();
		cout << "costPerSquareFeet = " << costPerSquareFoot << endl;
	}

};

int main()
{
	FeetInches o1,o2;
	float cost;
	cout << "Enter elements of o1: " << endl;
	cin >> o1;
	cout << "Enter elements of o2: " << endl;
	cin >> o2;

	RoomDimension r1(o1,o2);
	r1.display();
	cout << r1.getArea() << endl;

	cout << "Enter Cost per square feet: ";
	cin >> cost;

	RoomCarpet rcarpet1(r1, cost);
	rcarpet1.print();

	cout <<"Cost = "<< rcarpet1.getTotCost() << endl;

	return 0;
}