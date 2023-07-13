//#Mishaal Aslam
//#BITF21M526
//#Hw 05
//#BSIT F21

#include"iostream"

using namespace std;

class IntegerSet 
{
private:
	int* ptrSet;
	const int size;

public:
	//Parameterized Constructor
	IntegerSet(const int& size):size(size)
	{
		ptrSet = new int[size];
		for (int i = 0; i < size; i++)
		{
			ptrSet[i] = 0;
		}
	}


	//Copy constructor
	IntegerSet(const IntegerSet& obj) :size(obj.size)
	{
		ptrSet = new int[size];
		for (int i = 0; i < size; i++)
		{
			ptrSet[i] = obj.ptrSet[i];
		}
	}

	
	//Destructor
	~IntegerSet()
	{
		delete[] ptrSet;
	}


	//Stream insertion operator '<<'
	friend ostream& operator<<(ostream& put,const IntegerSet& obj);


	//Assignment operator '='
	IntegerSet operator=(const IntegerSet& obj)
	{
		if (this != &obj)
		{
			if (size == obj.size)
			{
				for (int i = 0; i < size; i++)
				{
					ptrSet[i] = obj.ptrSet[i];
				}
			}
			else
			{
				//cout << "Error! Sizes Mismatch!!" << endl;
			}
		}
		return *this;
	}


	//Equal operator '==' to compare two sets
	bool operator==(const IntegerSet& obj) const
	{
		int flag = 0;
		if (size != obj.size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (ptrSet[i] != obj.ptrSet[i])
				{
					return false;
				}
				else
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				return true;
			}
		}
	}


	//Logical Not '!' operator
	IntegerSet operator!() const
	{
		IntegerSet obj(size);
		for (int i = 0; i < size; i++)
		{
			if (ptrSet[i] == 1)
			{
				obj.ptrSet[i] = 0;
			}
			else if (ptrSet[i] == 0)
			{
				obj.ptrSet[i] = 1;
			}
		}

		return obj;
	}


	//Member Functions
	//1. "insertElement" member function to insert an element into the set
	void insertElement(int k)
	{
		if (k >= 0 && k < size)
		{
			ptrSet[k] = 1;
		}
		else
		{
			cout << "Error!! Wrong value entered\nCouldn't insert " << k << endl;
		}
	}


	//2. "deleteElement" member function to delete an element from the set
	void deleteElement(int k)
	{
		if (k >= 0 && k < size)
		{
			ptrSet[k] = 0;
		}
		else
		{
			cout << "Error!! Wrong value entered\nCouldn't delete " << k << endl;
		}
	}


	//3. Member Function to find Union of sets
	IntegerSet unionOfSets(const IntegerSet& obj)const
	{
		int newSize = size;
		if (size != obj.size)
		{
			if (size > obj.size)
			{
				newSize = size;
			}
			else
			{
				newSize = obj.size;
			}
		}
		IntegerSet uniSet(newSize);
		for (int i = 0; i < newSize; i++)
		{
			if (ptrSet[i] == 0 && obj.ptrSet[i] == 0)
			{
				uniSet.ptrSet[i] = 0;
			}
			else if (ptrSet[i] == 1 || obj.ptrSet[i] == 1)
			{
				uniSet.ptrSet[i] = 1;
			}
			else if (ptrSet[i] == 0)
			{
				uniSet.ptrSet[i] = 0;
			}
			else if (obj.ptrSet[i] == 0)
			{
				uniSet.ptrSet[i] = 0;
			}
			else if (ptrSet[i] == 1)
			{
				uniSet.ptrSet[i] = 1;
			}
			else if (obj.ptrSet[i] == 1)
			{
				uniSet.ptrSet[i] = 1;
			}
		}
		return uniSet;
	}


	//4. Member Function to find intersection of two sets
	IntegerSet intersectionOfSets(const IntegerSet& obj)const
	{
		int newSize = size;
		if (size != obj.size)
		{
			if (size > obj.size)
			{
				newSize = size;
			}
			else
			{
				newSize = obj.size;
			}
		}
		IntegerSet intersectionSet(newSize);
		for (int i = 0; i < newSize; i++)
		{
			if (ptrSet[i] == 1 && obj.ptrSet[i] == 1)
			{
				intersectionSet.ptrSet[i] = 1;
			}
			else
			{
				intersectionSet.ptrSet[i] = 0;
			}
		}

		return intersectionSet;
	}


	//5. Member Function to find an element in the set
	bool findElement(int key)
	{
		if (ptrSet[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

//Stream insertion operator '<<' (for printing numbers whose corresponding index contain value 1)
ostream& operator<<(ostream& put, const IntegerSet& obj)
{
	int flag = 0;
	if (obj.size == 0)
	{
		put << "---";
	}
	for (int i = 0; i < obj.size; i++)
	{
		if (obj.ptrSet[i] == 1)
		{
			put << i << "\t";
		}
		else {
			flag++;
		}
	}
	if (flag == obj.size)
	{
		put << "---";
	}

	return put;
}

int main()
{
	IntegerSet obj1(3);
	cout << "obj1 = " << obj1 << endl;
	obj1.insertElement(2);
	cout << "obj1 = " << obj1 << endl << endl;

	IntegerSet obj2(obj1),obj3(5),obj4(!(obj2));
	obj2.insertElement(1);
	cout << "obj2 = " << obj2 << endl << endl;

	obj3.insertElement(4);
	obj3.insertElement(1);
	cout << "obj3 = " << obj3 << endl << endl;

	cout << "obj4 = " << obj4 << endl << endl;

	obj4.deleteElement(3);
	obj4.deleteElement(0);
	cout << "After obj4.deleteElement(0) statement-->";
	cout<< "obj4 = " << obj4 << endl << endl;

	if (obj1 == obj2)
	{
		cout << "Both sets are equal" << endl;
	}
	else
	{
		cout << "Not Equal" << endl;
	}
	cout << "\n";


	cout << "Before Assignment --> obj3 = " << obj3 << endl ;
	obj3 = obj1;
	cout << "After Assignment --> obj3 = " << obj3 << endl << endl;

	cout << "obj1.unionOFSets(obj3) = " << obj1.unionOfSets(obj3) << endl;
	cout << "obj1.intersectionOFSets(obj2) = " << obj1.intersectionOfSets(obj2) << endl;
	cout << "obj1.intersectionOFSets(obj3) = " << obj1.intersectionOfSets(obj3) << endl << endl;

	cout << "obj1.findElement(9) = " << obj1.findElement(9) << endl;
	cout << "obj2.findElement(5) = " << obj2.findElement(5) << endl;
	cout << "obj3.findElement(4) = " << obj3.findElement(4) << endl << endl;

	


	return 0;
}