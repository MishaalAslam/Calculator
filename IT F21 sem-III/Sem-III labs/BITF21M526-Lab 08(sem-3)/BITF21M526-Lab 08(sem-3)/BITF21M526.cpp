// Mishaal Aslam
// BITF21M526
// BSIT 
// #Lab 08

#include"iostream"

using namespace std;

class Collection
{
private:
	int* data;
	int size;

public:
	//Constructors
	//1. Overloaded constructor '1'
	Collection(const int size)
	{
		if (size > 0)
		{
			this->size = size;
		}
		else 
		{
			this->size = 0;			//default size
		}
		data = new int[this->size];
		for (int i = 0; i < (this->size); i++)
		{
			data[i] = 0;
		}
	}

	//2.Overloaded constructor '2'
	Collection(const int arr[], const int size)
	{
		if (size > 0)
		{
			this->size = size;
		}
		else 
		{
			this->size = 0;			//default size
		}
		data = new int[this->size];
		for (int i = 0; i < (this->size); i++)
		{
			data[i] = arr[i];
		}
	}

	//3. Copy constructor
	Collection(const Collection& arr)
	{
		this->size = arr.size;
		data = new int[this->size];
		for (int i = 0; i < (this->size); i++)
		{
			data[i] = arr.data[i];
		}
	}

	//Destructor
	~Collection()
	{
		delete[] data;
	}

	//getSize
	int getSize()
	{
		return this->size;
	}

	//setElement
	void setElement(int i, int k)
	{
		if (i >= 0 && i < size)
		{
			data[i] = k;
		}
		else
		{
			cout << "Error!!Incorrect index..." << endl;
		}
	}

	//countElement function for occurence of an element
	int countElement(int key)
	{
		int count = 0;
		for (int i = 0; i < (this->size); i++)
		{
			if (data[i]==key)
			{
				count++;
			}
		}
		return count;
	}

	//Assignment Operator Overloading
	Collection operator=(const Collection& arr)
	{
		if (this != &arr)
		{
			if (this->size != arr.size)
			{
				delete[] data;
				this->size = arr.size;
				this->data = new int[this->size];
			}
			for (int i = 0; i < (this->size); i++)
			{
				data[i] = arr.data[i];
			}
		}
		return *this;
	}

	//getSubCollection
	Collection getSubCollection(int start_index, int end_index)
	{
		int size = 0;
		//if (start_index >= 0 && end_index < this->size)
		if ((start_index >= 0 && start_index < this->size) && (end_index > 0 && end_index < this->size) && (end_index > start_index))
		{
			size = end_index - start_index + 1;
			Collection temp(size);
			int j = 0;
			for (int i = start_index; i <= size; i++)
			{
				temp.data[j] = this->data[i];
				j++;
			}
			return temp;
		}
		else
		{
			cout<<"Error!!Incorrect indexes..."<<endl;
			Collection temp(size);
			return temp;
		}
		
	}

	//'<<' stream extraction operator
	friend ostream& operator<<(ostream& put, const Collection& arr);

	//'>>' stream insertion operator
	friend istream& operator>>(istream& get, Collection& arr);

	//Addition operator (+)
	Collection operator+(const Collection &arr1)
	{
		int size = 0;
		if (this->size == arr1.size)
		{
			Collection add(this->size);
			for (int i = 0; i < this->size; i++)
			{
				add.data[i] = arr1.data[i] + this->data[i];
				//cout << add.data[i]<<"\t";
			}
			return add;
		}
		else
		{
			cout << "Error!!Sizes Mismatch..." << endl;
			return Collection(0);
		}
	}

	//subscript operator for non-constant object
	int& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		
		cout << "Array index is out of bound" << endl;
		static int x = 99;
		return x;
	}

	//subscript operator for constant object
	int operator[](int index) const
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		cout << "Error!!Array index is out of bound" << endl;
		return 99;
	}

	//unary (-) operator
	bool operator-()const
	{
		int flag = 0;
		for (int i = 0; i < size; i++)
		{
			if (data[i] <= 0)
			{
				flag = 1;
			}
			else
			{
				return false;
			}
		}
		if (flag == 1)
		{
			return true;
		}
	}

};

//'<<' stream extraction operator
ostream& operator<<(ostream& put, const Collection& arr)
{
	for (int i = 0; i < arr.size; i++)
	{
		put << arr.data[i] << "\t";
	}
	return put;
}

//'>>' stream insertion operator
istream& operator>>(istream& get,Collection& arr)
{
	//cout << arr.size << endl;
	for (int i = 0; i < arr.size; i++)
	{
		get >> arr.data[i];
	}
	return get;
}

int main()
{
	int size = 5;
	Collection obj1(size);
	cout << "Enter values:";
	cin >> obj1;
	Collection obj2(obj1);
	obj2[3] = -21;


	cout <<"obj1 = "<<obj1 << endl;
	cout <<"obj2 = "<<obj2 << endl;
	
	cout <<"obj1.getSubCollection(1, 4) = "<< obj1.getSubCollection(1, 4) << endl;
	
	cout << "obj1[4] = " << obj1[4] << endl;

	cout << "obj1[-3] = " << obj1[-3] << endl;

	cout << "obj1.countElement(4) = " << obj1.countElement(4) << endl;
	cout << "Before setElement call obj1 = " << obj1<<endl;
	obj1.setElement(2, -200);
	cout << "obj1.setElement = " << obj1 << endl;

	cout << "obj1 + obj2 = " << obj1 + obj2 << endl;
	if (-obj1)
	{
		cout << "All values are non-positive" << endl;
	}
	else {
		cout<<"Some values are positive" << endl;
	}
	


	return 0;
}