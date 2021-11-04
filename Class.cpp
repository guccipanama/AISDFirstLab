#include "Class.h"

String::String() : _data(NULL), _size(0) {}
String::String(const char* Str)
{
	_size = strlen(Str);
	_data = new char[_size + 1];
	strcpy_s(_data, _size + 1, Str);
}
String::String(const String& Str)
{
	_size = Str._size;
	_data = new char[Str._size];
	if (Str._data)
		_data = _strdup(Str._data);
	else
		_data = NULL;
}
String::~String()
{
	delete[]_data;
}
int String::GetSize()
{
	return _size;
}
char& String::operator[](int Index)
{
	if (Index >= _size)
		throw "invalid index";
	else
		return _data[Index];
}
String String::operator+(const String Str)
{
	if (!_size)
		return Str;
	if (!Str._size)
		return *this;
	String result;
	result._size = _size + Str._size;
	result._data = new char[_size + Str._size + 1];
	strcpy_s(result._data, result._size + 1, _data);
	strcat_s(result._data, result._size + 1, Str._data);
	return result;
}
String& String::operator=(const String& Str)
{
	if (this == (&Str))
		return *this;
	if (_data)
		delete[] _data;
	if (Str._data)
	{
		_size = Str._size;
		_data = _strdup(Str._data);
	}
	else
	{
		_size = 0;
		_data = NULL;
	}
	return *this;
}
String operator*(const String Str, int Power)
{
	String temp;
	if ((Power <= 0) || (Str._size == 0))
		return temp;
	temp._size = Power * Str._size;
	temp._data = new char[Power * Str._size + 1];
	char* p = temp._data;
	*p = 0;
	for (int i = 0; i < Power; i++)
		strcat_s(p, temp._size + 1,  Str._data);
	return temp;
}
String operator*(int Power, const String Str)
{
	String temp;
	if ((Power <= 0) || (Str._size == 0))
		return temp;
	temp._size = Power * Str._size;
	temp._data = new char[Power * Str._size + 1];
	char* p = temp._data;
	*p = 0;
	for (int i = 0; i < Power; i++)
		strcat_s(p, temp._size + 1, Str._data);
	return temp;
}
std::ostream& operator<<(std::ostream& Out, const String& Str)
{
	cout << Str._data << endl;
	return Out;
}
/*std::istream& operator>>(istream& In, String& String)
{
	char temp[80];
	In.get(temp, 80);
	if (In)
		String = temp;
	while (In && In.get() != '\n')
		continue;
	return In;
}*/
bool operator<(const String& Str1, const String& Str2)
{
	return (strcmp(Str1._data, Str2._data) < 0);
}
bool operator>(const String& Str1, const String& Str2)
{
	return (strcmp(Str1._data, Str2._data) > 0);
}
bool operator==(const String& Str1, const String& Str2)
{
	return (strcmp(Str1._data, Str2._data) == 0);
}
bool operator!=(const String& Str1, const String& Str2)
{
	return (strcmp(Str1._data, Str2._data) != 0);
}
String String::Substring(int Begin, int End) const
{
	if ((Begin < 0) || (Begin >= _size))
		throw - 1;
	if ((End < 0) || (End >= _size) || (End < Begin))
		throw - 1;
	String temp;
	temp._size = End - Begin + 1;
	temp._data = new char[End - Begin + 2];
	int j = 0;
	for (int i = Begin; i < End + 1; i++)
	{
		temp._data[j] = _data[i];
		j++;
	}
	temp._data[End - Begin + 1] = 0;
	return temp;
}