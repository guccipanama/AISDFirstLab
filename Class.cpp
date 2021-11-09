#include "Class.h"

String::String() : Data(NULL), Size(0) {}
String::String(const char* Str)
{
	Size = strlen(Str);
	Data = new char[Size + 1];
	strcpy_s(Data, Size + 1, Str);
}
String::String(const String& Str)
{
	Size = Str.Size;
	Data = new char[Str.Size];
	if (Str.Data)
		Data = _strdup(Str.Data);
	else
		Data = NULL;
}
String::~String()
{
	delete[]Data;
}
int String::GetSize() const
{
	return Size;
}
char& String::operator[](int Index)
{
	if (Index >= Size)
		throw "Invalid index";
	else
		return Data[Index];
}
String String::operator+(const String Str)
{
	if (!Size)
		return Str;
	if (!Str.Size)
		return *this;
	String Result;
	Result.Size = Size + Str.Size;
	Result.Data = new char[Size + Str.Size + 1];
	strcpy_s(Result.Data, Result.Size + 1, Data);
	strcat_s(Result.Data, Result.Size + 1, Str.Data);
	return Result;
}
String& String::operator=(const String& Str)
{
	if (this == (&Str))
		return *this;
	if (Data)
		delete[] Data;
	if (Str.Data)
	{
		Size = Str.Size;
		Data = _strdup(Str.Data);
	}
	else
	{
		Size = 0;
		Data = NULL;
	}
	return *this;
}
String String::operator*(const int Power)
{
	String Temp;
	if (Size == 0)
		return Temp;
	if (Power <= 0)
		throw "Invalid ratio";
	Temp.Size = Power * Size;
	Temp.Data = new char[Power * Size + 1];
	char* P = Temp.Data;
	*P = 0;
	for (int i = 0; i < Power; i++)
		strcat_s(P, Temp.Size + 1,  Data);
	return Temp;
}
String operator*(int Power, const String Str)
{
	String Temp;
	if (Str.Size == 0)
		return Temp;
	if (Power <= 0)
		throw "Invalid ratio";
	Temp.Size = Power * Str.Size;
	Temp.Data = new char[Power * Str.Size + 1];
	char* P = Temp.Data;
	*P = 0;
	for (int i = 0; i < Power; i++)
		strcat_s(P, Temp.Size + 1, Str.Data);
	return Temp;
}
ostream& operator<<(std::ostream& Out, const String& Str)
{
	cout << Str.Data << endl;
	return Out;
}
bool String::operator<(const String& Str) const
{
	return (strcmp(Str.Data, Data) < 0);
}
bool String::operator>(const String& Str) const
{
	return (strcmp(Str.Data, Data) > 0);
}
bool String::operator==(const String& Str) const
{
	return (strcmp(Str.Data, Data) == 0);
}
bool String::operator!=(const String& Str) const
{
	return (strcmp(Str.Data, Data) != 0);
}
String String::Substring(int Index, int Length) const
{
	if ((Index < 0) || (Index >= Size))
		throw "Invalid index";
	if ((Length < 0) || (Length >= Size) || (Length < Index))
		throw "Invalid length";
	String Temp;
	Temp.Size = Length;
	Temp.Data = new char[Length + 1];
	for (int i = 0; i < Length + 1; i++)
		if (Data)
			Temp.Data[i] = Data[Index + i];
	Temp.Data[Length] = 0;
	return Temp;
}