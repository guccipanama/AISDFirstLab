#include "Class.h"
#include <windows.h>
#include <conio.h>

int main()
{
	system("color 0A");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	/*String Name1 = "Вася";
	String Name2 = "Василий";
	Name1 = Name2;
	try
	{
		Name1[0] = 'С';
		cout << Name1[6] << endl;
	}
	catch(const char* ex)
	{
		std::cout << ex << endl;
	}
	String Name3 = Name1 + Name2;
	const String Name4 = Name3 * 3;
	Name1 = Name4.Substring(7, 8);
	try
	{
		cout << Name1[2] << endl;
	}
	catch (const char* ex)
	{
		std::cout << ex << endl;
	}
	const String Name5 = Name1 * 3;
	cout << Name5;
	return 0;*/

	try
	{
		char Str1[32];
		cout << "Enter the string" << endl;
		cin >> Str1;
		cout << endl;
		int Change = 0;
		String A(Str1);
		while (Change == 0)
		{
			system("cls");
			cout << "Your string: "<< A << endl;
			int Option = 0;
			cout << "Select an option: "<< endl;
			cout << "1 - operator for reading / writing a character by its index" << endl;
			cout << "2 - addition operator for string concatenation" << endl;
			cout << "3 - multiplication operator by a number to duplicate a string the specified number of times" << endl;
			cout << "4 - the possibility of obtaining a substring by the specified index of the beginning of the substring and its length" << endl;
			cout << "5 - Exit" << endl;
			cin >> Option;
			cout << endl;
			switch (Option)
			{
			case 1:
			{
				system("cls");
				int Index = 0;
				int Choice = 0;
				cout << "Do you want to write by index? Or read it? 1 - write / 2 - read" << endl;
				cin >> Choice;
				cout << endl;
				cout << "Enter the index" << endl;
				cin >> Index;
				cout << endl;
				switch (Choice)
				{
				case 1:
				{
					system("cls");
					cout << A;
					cout << "Element " << Index << " is " << A[Index] << endl;
					cout << "Replace with:  ";
					char s;
					cin >> s;
					A[Index] = s;
					cout << endl;
					cout << A;
				}
				case 2:
				{
					system("cls");
					cout << "Element " << Index << " is " << A[Index] << endl;
				}
				}
				break;
			}
			case 2:
			{
				system("cls");
				char Str2[32];
				cout << "Enter the string" << endl;
				cin >> Str2;
				cout << endl;
				String B(Str2);
				String Sum = A + B;
				cout << Sum;
				cout << endl;
				break;
			}
			case 3:
			{
				system("cls");
				int Multiplier = 1;
				cout << "Enter the multiplier" << endl;
				cin >> Multiplier;
				cout << endl;
				String Mul = A * Multiplier;
				cout << Mul;
				cout << endl;
				break;
			}
			case 4:
			{
				system("cls");
				int Index = 0;
				int Length = 0;
				cout << "Enter the index" << endl;
				cin >> Index;
				cout << "Enter the length" << endl;
				cin >> Length;
				String Sub = A.Substring(Index, Length);
				cout << Sub;
				cout << endl;
				break;
			}
			case 5:
			{
				return 0;
			}
			}
		}
	}
	catch (const char* Err)
	{
		cerr << "Error: " << Err << endl;
	}
	return 0;
}