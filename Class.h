#pragma once
#include <iostream>;
#include <stdio.h>;
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
	int GetSize();

	char& operator[](int index);
	String operator+(const String string);
	String& operator=(const String& string);
	friend String operator*(const String string, int power);
	friend String operator*(int power, const String string);
	friend ostream& operator<<(std::ostream& out, const String& string);
	friend istream& operator>>(istream& is, String& string);
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend bool operator!=(const String& st1, const String& st2);
	String Substring(int begin, int end);
};