//Mishaal Aslam
//BITF21M526
//IT F21(Morning)
//#Homework 02

#include"iostream"
#include"cmath"

using namespace std;

//Cuboids Class
class Cuboids
{
private:
	float height;
	float width;
	float depth;
public:
	
	//Setters
	//1. setHeight
	void setHeight(float heightCuboid)
	{
		
		if (heightCuboid > 0 && heightCuboid < 35.00)
		{
			height = heightCuboid;
		}
		else
		{
			height = 1;
		}
	}

	//2.setWidth
	void setWidth(float widthCuboid)
	{
		if (widthCuboid > 0 && widthCuboid < 35.00)
		{
			width = widthCuboid;
		}
		else
		{
			width = 1;
		}
	}
	
	//3.setDepth
	void setDepth(float depthCuboid)
	{
		if (depthCuboid > 0 && depthCuboid < 35.00)
		{
			depth = depthCuboid;
		}
		else
		{
			depth = 1;
		}
	}



	//Getters
	//1. getHeight
	float getHeight()
	{
		return height;
	}

	//2.setWidth
	float getWidth()
	{
		return width;
	}
	
	//3.setDepth
	float setDepth()
	{
		return depth;
	}


	//Default Constructor 
	Cuboids()
	{
		setHeight(1);
		setWidth(1);
		setDepth(1);

		//cout << "Default Constructor executed..." << endl;
	}


	//Parameterized Constructor '1'
	Cuboids(float heightCuboid, float widthCuboid, float depthCuboid)
	{
		setHeight(heightCuboid);
		setWidth(widthCuboid);
		setDepth(depthCuboid);

		//cout << "Parameterized Constructor '1' executed..." << endl;
	}
	

	//Parameterized Constructor '2'
	Cuboids(float heightCuboid, float widthCuboid)
	{
		setHeight(heightCuboid);
		setWidth(widthCuboid);
		setDepth(1);

		//cout << "Parameterized Constructor '2' executed..." << endl;
	}
	

	//Copy Constructor 
	Cuboids(const Cuboids &obj)
	{
		setHeight(obj.height);
		setWidth(obj.width);
		setDepth(obj.depth);

		//cout << "Copy Constructor executed..." << endl;
	}
	

	//Member Function setCuboid
	void setCuboids(float cubHeight, float cubWidth, float cubDepth)
	{
		setHeight(cubHeight);
		setWidth(cubWidth);
		setDepth(cubDepth);
	}


	//Member Function getcuboid to take input from user
	void getCuboids()
	{
		float cubHeight, cubWidth, cubDepth;

		cout << "Enter height of Cuboid: ";
		cin >> cubHeight;
		setHeight(cubHeight);

		cout << "Enter width of Cuboid: ";
		cin >> cubWidth;
		setWidth(cubWidth);

		cout << "Enter depth of Cuboid: ";
		cin >> cubDepth;
		setDepth(cubDepth);
	}


	//Member Function putCuboids to display dimensions of Cuboids
	void putCuboids()
	{
		cout << height <<"\t" << width <<"\t" << depth<<"\t";
	} 


	//function for calculating surface Area
	float getSurfaceArea()
	{
		return (2 * ((height* width) + (height * depth) + (width * depth)));
	}


	//function for calculating volume of cuboid
	float getVolume()
	{
		return (height* width * depth);
	}

	
	//function for calculating diagonals
	float getSpaceDiagonal()
	{
		return (sqrt((height * height) + (width * width) + (depth * depth)));
	}
	
	
	//function for displaying each and every information of a cuboid
	void putCuboidsInfo()
	{
		cout << height <<"\t " << width <<"\t  " << depth <<"\t\t"<< getSurfaceArea() <<"\t\t" << getVolume()<<"\t\t" << getSpaceDiagonal() << endl;
	}


	//Destructor
	~Cuboids()
	{
		cout << "Destructor executed..." << endl;
	}


};


int main()
{
	Cuboids cub1(4, 5, 6), cub2(3.0, 3.0), cub3;
	cub3.getCuboids();
	Cuboids cub4(cub3);

	cub1.getSurfaceArea();
	cub1.getVolume();
	cub1.getSpaceDiagonal();

	
	cub2.setDepth(7);
	cub2.getSurfaceArea();
	cub2.getVolume();
	cub2.getSpaceDiagonal();

	cub3.getSurfaceArea();
	cub3.getVolume();
	cub3.getSpaceDiagonal();

	cub4.setHeight(6);
	cub4.getSurfaceArea();
	cub4.getVolume();
	cub4.getSpaceDiagonal();


	cout << "Height \t Width \t Depth \t Surface Area \t Volume \tSpace Diagonals" << endl;

	cub1.putCuboidsInfo();
	cub2.putCuboids();
	cout <<"\t"<< cub2.getSurfaceArea() << "\t\t" << cub2.getVolume() << "\t\t" << cub2.getSpaceDiagonal() << endl;
	cub3.putCuboidsInfo();
	cub4.putCuboidsInfo();



	return 0;
}