#pragma once
#include <iostream>
using namespace std;

class reservior
{

	char* name, * type;
	int width, length, max_depth;

public:

	reservior() : reservior(0, 0, 0, 0, 0) { }
	reservior(char* name_P) : reservior(name_P, 0, 0, 0, 0) { }
	reservior(char* name_P, char* type_P) : reservior(name_P, type_P, 0, 0, 0) { }
	reservior(char* name_P, char* type_P, int width_P) : reservior(name_P, type_P, width_P, 0, 0) { }
	reservior(char* name_P, char* type_P, int width_P, int length_P) : reservior(name_P, type_P, width_P, length_P, 0) { }
	reservior(char* name_P, char* type_P, int width_P, int length_P, int max_depth_P) : width{ width_P }, length{ length_P }, max_depth{ max_depth_P }
	{
		if (name_P == 0)
		{
			name = new char[100];
			strcpy_s(name, 100, name_P);
		}
		else
		{
			strcpy_s(name, strlen(name) + 1, name_P);
		}

		if (type_P == 0)
		{
			type = new char[100];
			strcpy_s(type, 100, type_P);
		}
		else
		{
			strcpy_s(type, strlen(type) + 1, type_P);
		}
	}
	reservior(const reservior& obj) : width{ obj.width }, length{ obj.length }, max_depth{ obj.max_depth } { strcpy_s(name, strlen(name) + 1, obj.name); strcpy_s(type, strlen(type) + 1, obj.type); }

	void set_name(char* name_P) { strcpy_s(name, strlen(name) + 1, name_P); }
	void set_type(char* type_P) { strcpy_s(type, strlen(type) + 1, type_P); }
	void set_width(int width_P) { width = width_P; }
	void set_length(int length_P) { length = length_P; }
	void set_max_depth(int max_depth_P) { max_depth = max_depth_P; }

	const char* get_name() { return name; }
	const char* get_type() { return type; }
	int get_width() { return width; }
	int get_length() { return length; }
	int get_max_depth() { return max_depth; }
};

