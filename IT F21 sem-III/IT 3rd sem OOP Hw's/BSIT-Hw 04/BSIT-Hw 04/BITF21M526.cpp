//Mishaal Aslam
//BITF21M526
//BSIT F21 Morning
//#Homework 04

#include "iostream"

using namespace std;

class RationalNumbers
{
private:
	int numerator;
	int denominator;

public:
	//Mutators
	//1. To set private data member of class numerator
	void setNumerator(int numerator)
	{
		this->numerator = numerator;
	}

	//2. To set private data member of class denominator
	void setDenominator(int denominator)
	{
		if (denominator > 0)
		{
			this->denominator = denominator;
		}
		else
		{
			this->denominator = 1;
		}
	}

	//Accessors
	//1. To access private data member of class numerator
	int getNumerator()
	{
		return numerator;
	}

	//2. To access private data member of class denominator
	int getDenominator()
	{
		return denominator;
	}


	//Constructors
	//1. Parameterized Constructor '1'
	RationalNumbers(int numerator, int denominator)
	{
		setNumerator(numerator);
		setDenominator(denominator);
	}

	//2. Parameterized Constructor '2'
	RationalNumbers(int numerator)
	{
		setNumerator(numerator);
		setDenominator(1);
	}


	//Operator Overloading
	//1. Stream insertion Operator
	friend ostream& operator<< (ostream& print, const RationalNumbers& r1);

	//2. Stream extraction Operator
	friend istream& operator>> (istream& input, RationalNumbers& r1);
	
	//3. Plus(+) Binary operator to add two rational numbers
	RationalNumbers operator+(const RationalNumbers& r)const
	{
		return RationalNumbers(((this->numerator * r.denominator) + (r.numerator * this->denominator)), (this->denominator * r.denominator));
	}

	//4. Minus(-) Binary operator to subtract rational numbers
	RationalNumbers operator-(const RationalNumbers& r)const
	{
		return RationalNumbers(((this->numerator * r.denominator) - (r.numerator * this->denominator)), (this->denominator * r.denominator));
	}

	//5. Multiply(*) Binary operator for miultiplication of two rational numbers
	RationalNumbers operator*(const RationalNumbers& r)const
	{
		return RationalNumbers((this->numerator * r.numerator), (this->denominator * r.denominator));
	}

	//6. Divide(*) Binary operator for division of two rational numbers
	RationalNumbers operator/(const RationalNumbers& r)const
	{
		return RationalNumbers((this->numerator * r.denominator), (this->denominator * r.numerator));
	}

	//7. Less than(<) Binary operator for comparison of two rational numbers
	bool operator<(const RationalNumbers& r)const
	{
		return ((this->numerator * r.denominator)< (this->denominator * r.numerator));
	}

	//8. Equal(==) Binary operator for comparison of two rational numbers
	bool operator==(const RationalNumbers& r)const
	{
		return ((this->numerator * r.denominator) == (this->denominator * r.numerator));
	}

	//9. Minus(-) Unary operator for negative of a rational number
	RationalNumbers operator-()const
	{
		if (this->numerator > 0)
		{
			return  RationalNumbers((-this->numerator), this->denominator);
		}
		else
		{
			return *this;
		}
	}

	//9. Logical not(!) Unary operator for checking a negative rational number
	bool operator!()const
	{
		//return (*this < 0);
		if (this->numerator < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


};

//Stream insertion Operator definition
ostream& operator<< (ostream& print, const RationalNumbers& r1)
{
	//print << "Numerator/Denomiator = " << r1.numerator << "/" << r1.denominator << endl;
	print  << r1.numerator << "/" << r1.denominator;
	return print;
}

//Stream extraction Operator definition
istream& operator>> (istream& input, RationalNumbers& r1)
{
	cout << "Enter numerator : ";
	cin >> r1.numerator;

	cout << endl << "Enter denominator : ";
	cin >> r1.denominator;
	cout<< endl;
	if (r1.denominator == 0)
	{
		r1.denominator = 1;
	}

	return input;
}

int main()
{
	cout << "\t<--Operator Overloading-->" << endl;

	RationalNumbers r1(2,3),r2(4,5) , r3(-5, 5), r4(-5, -6);

	cout << "r1 = " << r1 << endl;
	cout << "r2 = " << r2 << endl;
	cout << "r3 = " << r3 << endl;
	cout << "r4 = " << r4 << endl;

	cout << "r1 + r2 = " << r1 + r2 << endl;	// 22 / 15

	cout << "r1 * r2 = " << r1 * r2 << endl;		// 8 / 15

	cout << "r1 - r2 = " << r1 - r2 << endl;		// -2 / 15

	cout << "r1 / r2 = " << r1 / r2 << endl;

	if (r1 < r2)
	{
		cout << "True.i.e. " << r1 << " is less than " << r2 << endl;
	}
	else
	{
		cout<<"False as " << r1 << " is not less than " << r2 <<endl;
	}

	if (r1 == r2)
	{
		cout  << r1 << " is equal to " << r2 << endl;
	}
	else
	{
		cout<< r1 << " is not equal to " << r2 <<endl;
	}
	
	r3 = -r4;
	cout <<"r4 = "<< r4 << endl;		
	cout <<"r3 = "<< r3 << endl;	
	cout <<"-r3 = "<< -r3 << endl;

	cout <<"!r1 = "<< !r2 << endl;
	cout <<"!r3 = "<< !r3 << endl;
	cout <<"!r4 = "<< !r4 << endl;


	return 0;
}