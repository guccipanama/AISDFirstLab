#pragma once
#include <iostream>;
#include <string.h>;
#include <cstdlib>;
using namespace std;

class String
{
private:
	char* _data;
	int _size;
public:
	String();
	String(const char* string);
	String(const String& string);
	~String();

	char& operator[](int index);
	String operator+(const String string);
	String& operator=(const String& string);
	friend String operator*(const String string, int power);
	friend String operator*(int power, const String string);
	String Substring(int begin, int end);
};