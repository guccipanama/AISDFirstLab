/*#include <iostream>;
#include <string.h>;
#include <cstdlib>;
using namespace std;

class String
{
private:
	char* _data;
	int _size;
public:
	String(): _data(NULL), _size(0) {}
	String(const char* string)
	{
		_size = strlen(string);
		_data = new char[_size + 1];
		strcpy_s(_data, _size + 1, string);
	}
	String(const String& string)
	{
		_size = string._size;
		_data = new char[string._size];
		if (string._data)
			_data = _strdup(string._data);
		else
			_data = NULL;
	}
	~String()
	{
		delete[]_data;
	}

	char& operator[](int index)
	{
		if (index >= _size)
			throw - 1;
		else
			return _data[index];
	}
	String operator+(const String string)
	{
		if (!_size) 
			return string;
		if (!string._size)
			return *this;
		String result;
		result._size = _size + string._size;
		result._data = new char[_size + string._size + 1];
		strcpy(result._data, _data);
		strcat(result._data, string._data);
		return result;
	}
	String& operator=(const String& string)
	{
		if (this == (&string))
			return *this;
		if (_data)
			delete[] _data;
		if (string._data)
		{
			_size = string._size;
			_data = _strdup(string._data);
		}
		else
		{
			_size = 0;
			_data = NULL;
		}
		return *this;
	}
	friend String operator*(const String string, int power)
	{
		String temp;
		if ((power <= 0) || (string._size == 0))
			return temp;
		temp._size = power * string._size;
		temp._data = new char[power * string._size + 1];
		char* p = temp._data;
		*p = 0;
		for (int i = 0; i < power; i++)
			strcat(p, string._data);
		return temp;
	}
	friend String operator*(int power, const String string)
	{
		String temp;
		if ((power <= 0) || (string._size == 0))
			return temp;
		temp._size = power * string._size;
		temp._data = new char[power * string._size + 1];
		char* p = temp._data;
		*p = 0;
		for (int i = 0; i < power; i++)
			strcat(p, string._data);
		return temp;
	}
	String Substring(int begin, int end)
	{
		if ((begin < 0) || (begin >= _size))
			throw - 1;
		if ((end < 0) || (end >= _size) || (end < begin))
			throw - 1;
		String temp;
		temp._size = end - begin + 1;
		temp._data = new char[end - begin + 2];
		int j = 0;
		for (int i = begin; i < end + 1; i++)
		{
			temp._data[j] = _data[i];
			j++;
		}
		temp._data[end - begin + 1] = 0;
		return temp;
	}
};*/
#include "Class.h";
#include <windows.h>;
#include <conio.h>

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int MainMenu()
{
	while (true)
	{
		system("cls");
		std::cout << "������� �6: ����� \"������\"\n";
		std::cout << "\n";
		std::cout << "�������� ��������\n";
		std::cout << "\n";
		std::cout << "1. �������� ������ � ����\n";
		std::cout << "2. ������� ������ �� ���� �� �������\n";
		std::cout << "3. �������� ��� ���������\n";
		std::cout << "4. ������� ���������� �� �����\n";
		std::cout << "\n";
		std::cout << "��� ������ ������� ������ �������\n";
		std::cout << "������� esc ��� ������\n";
		int key = GetKey();
		if (key == 27 || key >= '1' && key <= '4' || key == 75 || key == 77)
			return key;
	}
}

int main()
{
	system("color 0A");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	String** Array;
	/*String Name1 = "����";
	String Name2 = "�������";
	Name1 = Name2;
	try
	{
		Name1[0] = '�';
	}
	catch(int ex)
	{
		std::cout << "invalid index" << endl;
	}
	String Name3 = Name1 + Name2;
	String Name4 = Name3 * 2;
	Name1 = Name4.Substring(7, 8);
	Name1 = Name1 * 2;
	cout << Name1;*/
	return 0;
}