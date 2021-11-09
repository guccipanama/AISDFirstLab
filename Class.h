#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
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
	int GetSize() const;

	char& operator[](int Index);
	String operator+(const String Str);
	String& operator=(const String& Str);
	String operator*(const int Power);
	friend String operator*(int Power, const String Str);
	friend ostream& operator<<(ostream& Out, const String& Str);
	bool operator<(const String& Str) const;
	bool operator>(const String& Str) const;
	bool operator==(const String& Str) const;
	bool operator!=(const String& Str) const;
	String Substring(int Index, int Length) const;
};