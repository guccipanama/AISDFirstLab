#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;

class String
{
private:
	char* _data;
	int _size;
public:
	String();
	String(const char* Str);
	String(const String& Str);
	~String();
	int GetSize();

	char& operator[](int Index);
	String operator+(const String Str);
	String& operator=(const String& Str);
	friend String operator*(const String Str, int Power);
	friend String operator*(int Power, const String Str);
	friend ostream& operator<<(ostream& Out, const String& Str);
	friend bool operator<(const String& Str1, const String& Str2);
	friend bool operator>(const String& Str1, const String& Str2);
	friend bool operator==(const String& Str1, const String& Str2);
	friend bool operator!=(const String& Str1, const String& Str2);
	String Substring(int Index, int Length) const;
};