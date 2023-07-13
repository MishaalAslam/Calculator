//Mishaal Aslam
//BITF21M526
//BSIT F21 (Morning)
//#Homework 03

#include"iostream"

using namespace std;

class Circle 
{
private:
	int x;
	int y;
	float radius;
	static const double PI;

public:
	//Setters
	//1. SetX
	void setX(int x)
	{
		if (x >= -50 && x <= 50)
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
		
	}

	//2. setY
	void setY(int y)
	{
		if (y >= -50 && y <= 50)
		{
			this->y = y;
		}
		else
		{
			this->y = 0;
		}
	}

	//3. setRadius
	void setRadius(float radius) 
	{
		if (radius >= 1 && radius <= 10)
		{
			this->radius = radius;
		}
		else
		{
			this->radius = 5;
		}
	}


	//Getters
	//1. getX
	int getX() const
	{
		return this->x;
	}

	//2. getY
	int getY() const
	{
		return this->y;
	}

	//3. To get Radius of Circle
	float getRadius() const
	{
		return this->radius;
	}

	//4. To access value of PI 
	static const double getPI()
	{
		return PI;
	}


	//Constructors
	//1. Default Constructor
	Circle()
	{
		setX(0);
		setY(0);
		setRadius(5);
	}

	//2. Parameterized Constructor '1'
	Circle(int x,int y,float radius)
	{
		setX(x);
		setY(y);
		setRadius(radius);
	}

	//3. Parameterized Constructor '2'
	Circle(int x,int y)
	{
		setX(x);
		setY(y);
		setRadius(5);
	}

	//4. Parameterized Constructor '3'
	Circle(int x, float radius)
	{
		setX(x);
		setY(0);
		setRadius(radius);
	}

	//5. Copy Constructor
	Circle(const Circle &circle)
	{
		setX(circle.x);
		setY(circle.y);
		setRadius(circle.radius);
	}


	//Destructor
	~Circle()
	{
		cout << "Destructor executed..." << endl;
	}


	//member function to set Circle elements
	void setCircle(int x, int y, float radius) 
	{
		setX(x);
		setY(y);
		setRadius(radius);
	}


	//member function to take input from user
	void getCircle()
	{
		int x, y;
		float radius;

		cout << "Enter x-Coordinate of the Circle: ";
		cin >> x;
		setX(x);
		
		cout << "Enter y-Coordinate of the Circle: ";
		cin >> y;
		setY(y);
		
		cout << "Enter radius of Circle: ";
		cin >> radius;
		setRadius(radius);
	}


	//member function to display x,y coordinates and radius of a circle
	void putCircle() const
	{
		cout << "x = "<<this->x << "\ty = " << this->y << "\tradius = " << this->radius << endl;
	}


	//Calculating area of Circle
	double getArea() const
	{
		return PI * (radius * radius);
	}


	//Calculating diameter of Circle
	double getDiameter() const
	{
		return (radius * 2);
	}


	//Calculating Circumference of Circle
	double getCircumference() const
	{
		return (2 * PI * radius);
	}


	//addCircle to add two Circle objects 
	Circle addCircle(const Circle & c) const
	{
		return Circle(this->x + c.x, this->y + c.y, this->radius + c.radius);
	}


	//isEqual to check states of both circles
	bool isEqual(const Circle &c) const
	{
		if (this->x == c.x && this->y == c.y && this->radius == c.radius)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	//member function to get index of array element having same state as that of LHS object
	//int findCircle( const Circle arr[], const int &size) const
	int findCircle( const Circle arr[]) const
	{
		int size = 3;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].x == this->x && arr[i].y == this->y && arr[i].radius == this->radius)
			{
				return i;
			}
		}
		return -1;
	}
	

	//member function to update radius of array element
	void updateObjects(Circle arr[], const int &size) const
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].x == this->x && arr[i].y == this->y)
			{
				arr[i].radius = this->radius;
			}
		}
	}


};

const double Circle::PI = 3.141593;

int main()
{
	//Testing Functionality of class Circle

	Circle c1,c2(3, 4, 5.5),c3(c1),c4(2,3.3f);
	Circle cArr[3] = {Circle(3,4,2),Circle(cArr[0]),Circle()};

	c1.getCircle();
	cout << "Circle 1: " << endl;
	c1.putCircle();
	cout <<"Area = "<< c1.getArea() << "\tDiameter = " << c1.getDiameter() << "\tCircumference = " << c1.getCircumference() << endl;


	cout << "Circle 2: " << endl;
	c2.putCircle();
	cout <<"Area= "<< c2.getArea() << "\tDiameter = " << c2.getDiameter() << "\tCircuference = " << c2.getCircumference() << endl;


	cout << "Circle 3: " << endl;
	c3.setCircle(3, 5, 1.1f);
	c3.putCircle();
	cout <<"Area = "<< c3.getArea() << "\tDiameter = " << c3.getDiameter() << "\tCircumference = " << c3.getCircumference() << endl;


	cout << "Circle 4: " << endl;
	c4.setY(8);
	c4.putCircle();
	cout <<"Area = "<< c4.getArea() << "\tDiameter = " << c4.getDiameter() << "\tCircumference = " << c4.getCircumference()<<"\n" << endl;
	
	cout <<"Circle::getPI()"<< Circle::getPI() << endl << endl;
	cout << "c3.isEqual(c4) = " << c3.isEqual(c4) << endl;
	cout << "addCircle(c1,c2) : ";
	c1.addCircle(c2).putCircle();
	cout << "\n";


	cArr[2].getCircle();
	cArr[1].setRadius(9.9);
	cout <<endl<< "c1.findCircle(cArr, 3) : Index = " << c1.findCircle(cArr, 3) << endl<<endl;


	cout << "c2.updateObjects(cArr, 3) : "<< endl;
	c2.updateObjects(cArr, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << "cArr[" << i << "].putCircle() = ";
		cArr[i].putCircle();
		cout << endl;
	}
	cout << endl;
	

	
	return 0;
}
