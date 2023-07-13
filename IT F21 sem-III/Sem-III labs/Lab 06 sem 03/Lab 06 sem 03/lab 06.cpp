//Mishaal Aslam
//IT F21
//lab 06

#include"iostream"
#include"string"

using namespace std;

class Item
{
private:
	int id;
	string name;
	int quantity;
	float cost;
public:
	//Mutators
	//1.setID
	void setID(int id)
	{
		if (id > 0)
		{
			this->id = id;
		}
		else 
		{
			this->id = 0;
		}
	}

	//2.setName
	void setName(string name)
	{
		this->name = name;
	}

	//3.setQuantity
	void setQuantity(int quantity)
	{
		if (quantity > 0)
		{
			this->quantity = quantity;
		}
		else
		{
			this->quantity = 0;
		}
	}

	//4.setCost
	void setCost(float cost)
	{
		if (cost > 0.0)
		{
			this->cost = cost;
		}	
		else
		{
			this->cost = 0;
		}
	}


	//Accessors
	//1.getID
	int getID()
	{
		return this->id;
	}

	//2.getName
	string getName()
	{
		return this->name;
	}

	//3.getQuantity
	int getQuantity()
	{
		return this->quantity;
	}

	//4.getCost
	float getCost()
	{
		return this->cost;
	}


	//Parameterized Constructor '1'
	Item(int id, string name, int quantity, float cost)
	{
		setID(id);
		setName(name);
		setQuantity(quantity);
		setCost(cost);
	}
	
	//Parameterized Constructor '2'
	Item(int id, string name, int quantity)
	{
		setID(id);
		setName(name);
		setQuantity(quantity);
		setCost(0);
	}

	//Parameterized Constructor '3'
	Item(int id, string name, float cost)
	{
		setID(id);
		setName(name);
		setQuantity(0);
		setCost(cost);
	}

	
	//Copy Constructor 
	Item(const Item& obj)
	{
		this->id = obj.id;
		this->name = obj.name;
		this->quantity = obj.quantity;
		this->cost = obj.cost;

	}


	//Destructor
	~Item()
	{
		cout << "Destructor Executed..." << endl;
	}


	//setItem function sets object's items
	void setItem(int id, string name, int quantity, float cost)
	{
		setID(id);
		setName(name);
		setQuantity(quantity);
		setCost(cost);
	}

	//setItem function sets object's items
	void getItem()
	{
		int id,  quantity;
		string name;
		float cost;

		cout << "Enter item's item number: ";
		cin >> id;
		setID(id);

		cout << "Enter item's Name: ";
		getline(cin, name);
		setName(name);

		cout << "Enter Quantity of items: ";
		cin >> quantity;
		setQuantity(quantity);

		cout << "Enter Cost of Item: ";
		cin >> cost;
		setCost(cost);
	}


	//putItem function to display item's information
	void putItem() const
	{
		cout << "Id = " << id << "\tName = " << name << "\tQuantity = " << quantity << "\tCost = " << cost << endl;
	}


	//TotalCost function to find total Cost of an item if quantity is greater than zero
	float getTotalCost() const
	{
		//float totCost = 0.0f;
		if (this->quantity >= 1)
		{
			return this->quantity * this->cost;
		}
		return 0.0;
	}


	//isEqual to comapre two items
	bool isEqual(const Item &obj)const
	{
		if (id == obj.id && name == obj.name && quantity == obj.quantity && cost == obj.cost)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	//updateName member function
	void updateName(Item arr[], const int& size)const
	{
		for (int i = 0; i < size; i++)
		{
			if (id == arr[i].id)
			{
				arr[i].name = name;
			}
		}
	}


	//getMinimumCostItem member Function
	Item getMinimumCostItem(const Item arr[], const int& size)const
	{
		float min = arr[0].cost;
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].cost < min) 
			{
				min = arr[i].cost;
				index = i;
			}
		}
		return arr[index];
	}


	//getAveragePrice member Function
	void getAveragePrice(const Item arr[], const int& size)
	{
		for (int i = 0; i < size; i++)
		{
			this->cost += arr[i].cost;
		}
	}
};

int main()
{
	Item item1(1, "Tom", 5, 10),item2(2,"Jerry",5.1f),item3(3,"OGY",3);
	Item item4(item1);
	Item a[3] = { Item(1,"Toys",4,5.2f),Item(1,"Novels",4,6.5f), Item(1,"Toys",4,2.5f) };

	item1.putItem();
	item2.putItem();
	cout <<"item1.isEqual(item2) = " << item1.isEqual(item2) << endl;

	item3.putItem();
	cout << item3.getTotalCost();

	item4.setName("Dora");
	item4.setQuantity(3);
	cout << "Id = " << item4.getID() << "\tName = " << item4.getName() << "\tQuantity = " << item4.getQuantity() << "\tCost = " << item4.getCost() << endl;

	cout << "Original Array " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "a[" << i << "] = ";
		a[i].putItem();
		cout<< endl;
	}

	item1.updateName(a, 3);

	cout << "Array after call to updateName " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "a[" << i << "] = ";
		a[i].putItem();
		cout << endl;
	}

	item3.getAveragePrice(a,3);
	cout << "item3.getAveragePrice(); " << endl << "Average Cost = " << item3.getCost() << endl;

	Item minCostItem = item4.getMinimumCostItem(a, 3);
	cout << "Minimum Cost Item in array is: " << endl;
	minCostItem.putItem();


	return 0;
}