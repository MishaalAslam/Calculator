// Mishaal Aslam
// BITF21M526
// BSIT F21(Morning)
// #Lab 09
// #ADT: Generic Array

#include"iostream"

using namespace std;

//define template
template<class t>

class Array
{
private:
	t* data;
	int size;

public:
	// Constructors
	// 1. Default constructor that allocates an array of size 5 and initializes it with zero
	Array()
	{
		this->size = 5;
		this->data = new t[size];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = 0;
		}
	}


	//2. Parameterized Constructor that accepts the size of an array and initializes it with zeroes 
	Array(const int& size)
	{
		if (size > 0)
		{
			this->size = size;
		}
		else
		{
			this->size = 5;
		}
		this->data = new t[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = 0;
		}
	}
	

	//3. Copy Constructor initializes an array object with an already existing object. 
	Array(const Array& obj)
	{
		this->size = obj.size;
		this->data = new t[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = obj.data[i];
		}
	}


	//	Destructor
	~Array()
	{
		delete[] data;
	}


	// getSize returns the size of array
	int getSize()
	{
		return size;
	}


	// setElement inserts a new element k at index i into an array if possible
	void setElement(t k, int i)
	{
		if (i >= 0 && i < size)
		{
			data[i] = k;
		}
		else
		{
			cout << "Error!! Wrong index entered\nCouldn't insert " << k << endl;
		}
	}

	
	// countElement accepts a key as argument and counts and returns the total occurrences of it in an array
	int coutElement(const t& key)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (data[i] == key)
			{
				count++;
			}
		}
		return count;
	}


	//Assignment Operator Overloading
	Array operator=(const Array& arr)
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


	// getSubArray  returns a new Collection that contains all the values in the left-hand-side object from start_index to end_index, both inclusive
	Array getSubArray(int start_index, int end_index)
	{
		int size = 0;
		//if (start_index >= 0 && end_index < this->size)
		if ((start_index >= 0 && start_index < this->size) && (end_index > 0 && end_index < this->size) && (end_index > start_index))
		{
			size = end_index - start_index + 1;
			Array temp(size);
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
			cout << "Error!!Incorrect indexes..." << endl;
			Array temp(size);
			return temp;
		}

	}


	// Arithmetic binary (+) that inserts contents of right-hand-side object at the end of left-hand-side object
	Array operator+(const Array& obj)const
	{
		int newSize = this->size + obj.size;
		Array temp(newSize);
		
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			temp.data[j] = this->data[i];
			j++;
		}
		for (int i = 0; i < obj.size; i++)
		{
			temp.data[j] = obj.data[i];
			j++;
		}
		return temp;
	}

	template<class t>
	friend istream& operator>>(istream& input, Array<t>& obj);

	template<class t>
	friend ostream& operator<<(ostream& output, const Array<t>& obj);


	
	// '==' Comparison Operator
	bool operator==(const Array& obj)
	{
		if (this->size != obj.size)
		{
			return false;
		}
		else if (this->size == obj.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] != obj.data[i])
				{
					return false;
				}
			}
		}
		return true;
	}


	//subscript operator for non-constant object
	t& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}

		cout << "Array index is out of bound" << endl;
		static t x = -1;
		return x;
	}

	//subscript operator for constant object
	t operator[](int index) const
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		cout << "Error!!Array index is out of bound" << endl;
		return -1;
	}

};

//'>>' stream extraction operator
template<class t>
istream& operator>>(istream& input, Array<t>& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		cout << "data[" << i << "] = ";
		input >> obj.data[i];
	}
	return input;
}


//'<<' stream insertion operator
template<class t1>
ostream& operator<<(ostream& put, const Array<t1>& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		put << obj.data[i] << "\t";
	}
	return put;
}


int main()
{
	Array<int> arr1(4);
	cout << "Enter Array elements: ";
	cin >> arr1;
	Array<int> arr2(arr1);
	cout << endl << "Array 1 = " << arr1 << endl;
	cout << "Array 2 = " << arr2 << endl << endl;

	arr1[3] = 12;
	cout << "After using subscript operator" << endl << "Array 1 = " << arr1 << endl << endl;

	cout << "arr1[5] = " << arr1[5] << endl << endl;

	arr2.setElement(23, 1);
	arr2.setElement(123, 8);
	cout << "After using setElement member function" << endl << "Array 2 = " << arr2 << endl << endl;

	if (arr1 == arr2)
	{
		cout << "Both arrays are equal" << endl;
	}
	else
	{
		cout << "Arrays are not equal" << endl;
	}
	cout << "\n";

	cout << "arr1 + arr2 = " << arr1 + arr2 << endl << endl;

	Array<int> arr3;
	arr3 = arr1;
	cout << "Array 3 = " << arr3 << endl << endl;

	cout << "arr3.coutElement(3) = " << arr3.coutElement(3) << endl << endl;


	arr2.setElement(78, 3);
	cout << "After setElement():\nArray 2 = " << arr2 << endl << endl;

	cout << "arr3.getSubArray(2, 3) = " << arr3.getSubArray(2, 3) << endl << endl;
	//cout << "Array 3 = " << arr3 << endl << endl;

	//Array<float> arr1;
	//Array<string> arr1;
	Array<char> arrc1;
	cout << "Enter caracters: ";
	cin >> arrc1;
	cout << arrc1;

	cout<<arrc1[78];
	



	return 0;
}