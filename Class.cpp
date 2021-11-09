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
int String::GetSize() const
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
String String::operator*(const int Power)
{
	String temp;
	if (_size == 0)
		return temp;
	if (Power <= 0)
		throw "invalid ratio";
	temp._size = Power * _size;
	temp._data = new char[Power * _size + 1];
	char* p = temp._data;
	*p = 0;
	for (int i = 0; i < Power; i++)
		strcat_s(p, temp._size + 1,  _data);
	return temp;
}
/*String operator*(int Power, const String Str)
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
}*/
std::ostream& operator<<(std::ostream& Out, const String& Str)
{
	cout << Str._data << endl;
	return Out;
}
bool String::operator<(const String& Str) const
{
	return (strcmp(Str._data, _data) < 0);
}
bool String::operator>(const String& Str) const
{
	return (strcmp(Str._data, _data) > 0);
}
bool String::operator==(const String& Str) const
{
	return (strcmp(Str._data, _data) == 0);
}
bool String::operator!=(const String& Str) const
{
	return (strcmp(Str._data, _data) != 0);
}
String String::Substring(int Index, int Length) const
{
	if ((Index < 0) || (Index >= _size))
		throw "invalid index";
	if ((Length < 0) || (Length >= _size))
		throw "invalid length";
	String temp;
	temp._size = Length;
	temp._data = new char[Length + 1];
	for (int i = 0; i < Length + 1; i++)
		if (_data)
			temp._data[i] = _data[Index + i];
	temp._data[Length] = 0;
	return temp;
}
