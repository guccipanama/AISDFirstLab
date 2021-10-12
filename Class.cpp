#include "Class.h"

String::String() : _data(NULL), _size(0) {}
String::String(const char* string)
{
	_size = strlen(string);
	_data = new char[_size + 1];
	strcpy_s(_data, _size + 1, string);
}
String::String(const String& string)
{
	_size = string._size;
	_data = new char[string._size];
	if (string._data)
		_data = _strdup(string._data);
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
char& String::operator[](int index)
{
	if (index >= _size)
		throw - 1;
	else
		return _data[index];
}
String String::operator+(const String string)
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
String& String::operator=(const String& string)
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
String operator*(const String string, int power)
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
String operator*(int power, const String string)
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
std::ostream& operator<<(std::ostream& out, const String& string)
{
	cout << string._data << endl;
	return out;
}
std::istream& operator>>(istream& in, String& string)
{
	char temp[80];
	in.get(temp, 80);
	if (in)
		string = temp;
	while (in && in.get() != '\n')
		continue;
	return in;
}
bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1._data, st2._data) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return (strcmp(st1._data, st2._data) > 0);
}

bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1._data, st2._data) == 0);
}
bool operator!=(const String& st1, const String& st2)
{
	return (strcmp(st1._data, st2._data) != 0);
}
String String::Substring(int begin, int end)
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