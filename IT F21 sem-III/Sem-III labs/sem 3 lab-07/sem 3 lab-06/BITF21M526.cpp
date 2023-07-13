//Mishaal Aslam
//BITF21M526
//Lab-07

#include"iostream"
#include"string"

using namespace std;

//User-defined datatype/Class Date
class Date
{
private:
	int day;
	int month;
	int year;

public:
	//Mutators
	
	//1. To set Year
	void setYear(int year)
	{
		if (year >= 1900)
		{
			this->year = year;
		}
		else
		{
			this->year = 1900;
		}
	}


	//2. To set Month
	void setMonth(int month)
	{
		if (month >= 1 && month <= 12)
		{
			this->month = month;
		}
		else
		{
			this->month = 1;
		}
	}

	//3. To set date
	void setDay(int day)
	{
		if (!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (month == 2 && (day >= 1 && day <= 28)))   //if year is a leap year
		{
			this->day = day;
		}
		else if((month==2)&& (day >= 1 && day <= 29))
		{
			this->day = day;
		}
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day >= 1 && day <= 31))
		{
			this->day = day;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11 ) && (day >= 1 && day <= 30))
		{
			this->day = day;
		}
		else
		{
			this->day = 1;
		}
	}

	//Mutators
	//1. To get date
	int getDay()
	{
		return day;
	}

	//2. To get Month
	int getMonth()
	{
		return month;
	}

	//3. To get Year
	int getYear()
	{
		return year;
	}

	//Constructors
	//1. Parameterized Constructor '1'
	Date(int day,int month,int year)
	{
		setDay(day);
		setMonth(month);
		setYear(year);
	}

	//2. Parameterized Constructor '2'
	Date(int month,int year)
	{
		setDay(1);
		setMonth(month);
		setYear(year);
	}

	//3. Default Constructor
	Date()
	{
		setDay(1);
		setMonth(1);
		setYear(1900);
	}

	//overloaded operators
	//1. stream insertion '<<' operator
	friend ostream& operator<<(ostream& put, const Date& obj);

	//2. stream extraction '>>' operator
	friend istream& operator>>(istream& put, Date& obj);

	//3. Pre-increment"++" to increment in day
	Date operator++()
	{
		if (day == 31 && month == 12)
		{
			day = 1;
			month = 1;
			year++;
		}
		else if (day == 31)
		{
			day = 1;
			month++;
		}
		else
		{
			++day;
		}

		return *this;
	}
	
	//4. Post-increment"++" to increment in day
	Date operator++(int)
	{
		Date temp(*this);
		if (day == 31 && month == 12)
		{
			day = 1;
			month = 1;
			year++;
		}
		else if (day == 31)
		{
			day = 1;
			month++;
		}
		else
		{
			day++;
		}

		return temp;
	}
	

	//5. Pre-decrement"--" for decrementation in day
	Date operator--()
	{
		if (day == 1 && month == 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else if (day == 1)
		{
			day = 31;
			month--;
		}
		else
		{
			--day;
		}

		return *this;
	}
	
	//6. Post-decrement "--" to decrement the date
	Date operator--(int)
	{
		Date temp(*this);

		if (day == 1 && month == 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else if (day == 1)
		{
			day = 31;
			month--;
		}
		else
		{
			--day;
		}
		return temp;
	}

	//7. Subtraction Binary(-)
	int operator-(const Date& obj)
	{
		int y = 0, m = 0, d = 0;
		int remDays = 0, moth=0;
		y = this->year - obj.year;
		m = this->month - obj.month;
		d = this->day - obj.day;

		//cout << "y = " << y << endl;

		//for greater month
		if (this->month >= obj.month)
		{
			moth = this->month;
		}
		else if (this->month < obj.month)
		{
			moth = obj.month;
		}

		//for calculating days
		if ((moth == 1 || moth == 3 || moth == 5 || moth == 7 || moth == 8 || moth == 10 || moth == 12))
		{
			if (y >= 0 && m >= 0 && d >= 0)
			{
				remDays = y * 12 * 31 + m * 31 + d;
			}
			else if (y >= 0 && m >= 0 && d < 0)
			{
				d = -1 * d;
				remDays = y * 12 * 31 + m * 31 + d;
			}
			else if (y >= 0 && m <= 0 && d >= 0)
			{
				d = -1 * m;
				remDays = y * 12 * 31 + m * 31 + d;
			}
			else if (y >= 0 && m < 0 && d < 0)
			{
				d = -1 * d;
				m = -1 * m;
				remDays = y * 12 * 31 + m * 31 + d;
			}
			else
			{
				remDays = -1;
			}
		}
		else if (moth == 4 || moth == 6 || moth == 9 || moth == 11)
		{
			if (y >= 0 && m >= 0 && d >= 0)
			{
				remDays = y * 12 * 30 + m * 30 + d;
			}
			else if (y >= 0 && m >= 0 && d < 0)
			{
				d = -1 * d;
				remDays = y * 12 * 30 + m * 30 + d;
			}
			else if (y >= 0 && m <= 0 && d >= 0)
			{
				d = -1 * m;
				remDays = y * 12 * 30 + m * 30 + d;
			}
			else if (y >= 0 && m < 0 && d < 0)
			{
				d = -1 * d;
				m = -1 * m;
				remDays = y * 12 * 30 + m * 30 + d;
			}
			else
			{
				remDays = -1;
			}
		}

		else if ((moth == 2)&& (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
		{
			if (y >= 0 && m >= 0 && d >= 0)
			{
				remDays = y * 12 * 29 + m * 29 + d;
			}
			else if (y >= 0 && m >= 0 && d < 0)
			{
				d = -1 * d;
				remDays = y * 12 * 29 + m * 29 + d;
			}
			else if (y >= 0 && m <= 0 && d >= 0)
			{
				d = -1 * m;
				remDays = y * 12 * 29 + m * 29 + d;
			}
			else if (y >= 0 && m < 0 && d < 0)
			{
				d = -1 * d;
				m = -1 * m;
				remDays = y * 12 * 29 + m * 29 + d;
			}
			else
			{
				remDays = -1;
			}
		}
		
		else if (moth == 2)
		{
			if (y >= 0 && m >= 0 && d >= 0)
			{
				remDays = y * 12 * 28 + m * 28 + d;
			}
			else if (y >= 0 && m >= 0 && d < 0)
			{
				d = -1 * d;
				remDays = y * 12 * 28 + m * 28 + d;
			}
			else if (y >= 0 && m <= 0 && d >= 0)
			{
				d = -1 * m;
				remDays = y * 12 * 28 + m * 28 + d;
			}
			else if (y >= 0 && m < 0 && d < 0)
			{
				d = -1 * d;
				m = -1 * m;
				remDays = y * 12 * 28 + m * 28 + d;
			}
			else
			{
				remDays = -1;
			}
		}
		
		return remDays;
	}


	//8.Addition Unary(+)
	bool operator+()
	{
		if ((day == 5 && month == 2) || (day == 23 && month == 3) || (day == 1 && month == 5) || (day == 14 && month == 8) || (day == 25 && month == 12))
		{
			return true;
		}
		else
		{
			return false;
		}
	}




};

//"<<" operator body/definition that print the date on screen as monthName day, year
ostream& operator<<(ostream& put, const Date& obj)
{
	string monthName;
	switch (obj.month)
	{
		case 1:
		{
			monthName = "January";
			break;
		}
		case 2:
		{
			monthName = "February";
			break;
		}
		case 3:
		{
			monthName = "March";
			break;
		}
		case 4:
		{
			monthName = "April";
			break;
		}
		case 5:
		{
			monthName = "May";
			break;
		}
		case 6:
		{
			monthName = "June";
			break;
		}
		case 7:
		{
			monthName = "July";
			break;
		}
		case 8:
		{
			monthName = "August";
			break;
		}
		case 9:
		{
			monthName = "September";
			break;
		}
		case 10:
		{
			monthName = "October";
			break;
		}
		case 11:
		{
			monthName = "November";
		}
		case 12:
		{
			monthName = "December";
		}
	}

	put << monthName << " " << obj.day << ", " << obj.year;

	return put;
}

//">>" operator body/definition that takes date as input from user in the format dd mm yyyy or dd/mm/yyyy
istream& operator>>(istream& get,Date& obj)
{
	cout << "Enter day, month and year of date in the format dd mm yyyy: ";
	get >> obj.day >> obj.month >> obj.year;

	obj.setDay(obj.day);
	obj.setMonth(obj.month);
	obj.setYear(obj.year);

	return get;
}

int main()
{
	Date d1 , d2;
	cin >> d1;
	cin >> d2;

	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;

	cout <<"++d1 = " << ++d1 << endl;
	cout << "d1++ = " << d1++ << endl;
	cout << "d1 = " << d1 << endl;
	cout <<"--d1 = " << --d1 << endl;
	cout << "d1-- = " << d1-- << endl;
	cout << "d1 = " << d1 << endl;

	
	

	cout << "d1-d2 = " << d1-d2 << endl;
	cout << +d1 << endl;
	cout << +d2 << endl;

	return 0;
}