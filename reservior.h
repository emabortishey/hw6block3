#pragma once
#include <iostream>
using namespace std;

class reservior
{

	char* name, * type;
	int width, length, max_depth;

public:

	reservior() : reservior(nullptr, nullptr, 0, 0, 0) { }
	reservior(char* name_P) : reservior(name_P, nullptr, 0, 0, 0) { }
	reservior(char* name_P, char* type_P) : reservior(name_P, type_P, 0, 0, 0) { }
	reservior(char* name_P, char* type_P, int width_P) : reservior(name_P, type_P, width_P, 0, 0) { }
	reservior(char* name_P, char* type_P, int width_P, int length_P) : reservior(name_P, type_P, width_P, length_P, 0) { }
	reservior(char* name_P, char* type_P, int width_P, int length_P, int max_depth_P) : width{ width_P }, length{ length_P }, max_depth{ max_depth_P }
	{
		if (name_P == nullptr)
		{
			name = new char[100] {"none"};
		}
		else
		{
			name = new char[strlen(name_P) + 1];
			strcpy_s(name, strlen(name) + 1, name_P);
		}

		if (type_P == nullptr)
		{
			type = new char[100] {"none"};
		}
		else
		{
			type = new char[strlen(type_P)+1];
			strcpy_s(type, strlen(type) + 1, type_P);
		}
	}
	reservior(const reservior& obj) : width{ obj.width }, length{ obj.length }, max_depth{ obj.max_depth } { strcpy_s(name, strlen(name) + 1, obj.name); strcpy_s(type, strlen(type) + 1, obj.type); }

	void set_name(char* name_P);
	void set_type(char* type_P);
	void set_width(int width_P) { width = width_P; }
	void set_length(int length_P) { length = length_P; }
	void set_max_depth(int max_depth_P) { max_depth = max_depth_P; }

	int calculate_volume() const { return width * length * max_depth; }
	int calculate_area() const { return width * length; } 
	int if_type_same(const reservior& obj) const;
	int compare_areas(const reservior& obj) const;
	void coppy(const reservior& obj);

	void print() 
	{
		cout << name; 
		cout << '\t'; 
		cout << type; 
		cout << '\t'; 
		cout << width; 
		cout << '\t'; 
		cout << length; 
		cout << '\t'; 
		cout << max_depth; 
	}

	const char* get_name() const { return name; }
	const char* get_type() const { return type; }
	int get_width() const { return width; }
	int get_length() const { return length; }
	int get_max_depth() const { return max_depth; }

	~reservior()
	{
		delete[] name;
		delete[] type;
	}
};

