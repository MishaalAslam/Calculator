#include "iostream"
//#include "string"
#include <cstdio>

using namespace std;

int *pairWiseSum(const int arr[],int size,int &newSize)
{
	newSize = size % 2;

	if (newSize == 0)
	{
		newSize = size / 2;
	}
	else if (size % 2 == 1)
	{
		newSize = (size / 2) + 1;
	}
	
	int* farr = new int[newSize];
	int j = 0;
	
	if (size / 2 == 0)
	{
		for (int i = 0; i < size; i += 2)
		{
			*(farr + j) = arr[i] + arr[i + 1];
			j++;
		}
	}
	else if (size / 2 != 0)
	{
		for (int i = 0; i < size; i++)
		{
			*(farr + j) = arr[i] + arr[i + 1];
			
			if (i == size - 1)
			{
				*(farr + j) = arr[i];
			}
			j++;
			i++;
		}
	}
	

	return farr;
}

void letterPerWord(const char *st)
{
	char a[10];
	int length = 0;
	for (int i = 0; *(st + i) != '\0'; i++)
	{
		length++;
	}
	int count = 0;
	int j = 0;
	for (int i = 0; i<length; i++)
	{
		if (st[i] != ' ')
		{
			cout << st[i];
			count++;
		}
		/*else if(i == length-1)
		{
			cout << "hh";
			cout << "\t" << count << endl;
		}*/
		else 
		{
			
			cout << "\t" << count << endl;
			count = 0;
		}
	}
}


char *reverseCase(const char *st)
{
	char* carr = new char[100];
	for (int i = 0; st[i] != '\0'; i++)
	{
		cout <<"st["<<i<<"] = "<< st[i] << endl;
		if ((st[i] >= 'a') || (st[i] <= 'z'))
		{
			carr[i] = st[i] - 32;
		}
		if ((st[i] >= 'A') || (st[i] <= 'Z'))
		{
			carr[i] = st[i] + 32;
		}
		if((st[i] == ' '))
		{
			carr[i] = st[i];
		}
		cout << "st[" << i << "] = " << st[i] << endl;
	}
	return carr;
}

int main()
{
	//Tak 03
	//char stri[100];
	//cout << "Enter a string: ";
	//cin.get(stri,100);
	//char *ptr = reverseCase(stri);
	////cout << "Output string is: " << endl << stri;
	//for (int i = 0; *(ptr + i) != '\0'; i++)
	//{
	//	cout << *(ptr + i);
	//}



	

	//Task 02

	//string str;
	char str[100];
	cout << "Enter a string: ";
	cin.get(str,100);

	letterPerWord(str);


	
	//Task 01
	/*int newSize = 0;

	int arr[10];
	int arr2[9];


	cout << "Even Size Array" << endl;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}
	int *a3 = pairWiseSum(arr, 10, newSize);
	for (int i = 0; i < newSize; i++)
	{
		cout << *(a3 + i) << "\t";
	}



	cout << endl << "Odd Size Array" << endl;
	for (int i = 0; i < 9; i++)
	{
		arr2[i] = i + 1;
	}
	int* a4 = pairWiseSum(arr2, 9, newSize);
	for (int i = 0; i < newSize; i++)
	{
		cout << *(a4 + i) << "\t";
	}


	delete[] a3;
	delete[] a4;
	
*/

	
	return 0;
}