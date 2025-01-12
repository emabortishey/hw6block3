#pragma once
#include <iostream>
using namespace std;

class reservior
{

	char* name, * type;
	int width, length, max_depth;

public:

	reservior() : reservior(nullptr, nullptr, 0, 0, 0) { }
	// ����������� � 1 ���������� ���������
	explicit reservior(const char* name_P) : reservior(name_P, nullptr, 0, 0, 0) { }
	reservior(const char* name_P, const  char* type_P) : reservior(name_P, type_P, 0, 0, 0) { }
	reservior(const char* name_P, const char* type_P, int width_P) : reservior(name_P, type_P, width_P, 0, 0) { }
	reservior(const char* name_P, const char* type_P, int width_P, int length_P) : reservior(name_P, type_P, width_P, length_P, 0) { }
	reservior(const char* name_P, const char* type_P, int width_P, int length_P, int max_depth_P) : width{ width_P }, length{ length_P }, max_depth{ max_depth_P }
	{
		// ������ ������ � ��������� ���������� ���� ��� �������� �� ��� ����, ����� �� ������ ��� ������� ���

		if (name_P == nullptr)
		{
			name = new char[100] {"none"};
		}
		else
		{
			name = new char[strlen(name_P) + 1];
			strcpy_s(name, strlen(name_P) + 1, name_P);
		}

		if (type_P == nullptr)
		{
			type = new char[100] {"none"};
		}
		else
		{
			type = new char[strlen(type_P)+1];
			strcpy_s(type, strlen(type_P) + 1, type_P);
		}
	}
	// ����������� �����������
	reservior(const reservior& obj) : width{ obj.width }, length{ obj.length }, max_depth{ obj.max_depth } { name = new char[strlen(obj.name) + 1]; strcpy_s(name, strlen(obj.name) + 1, obj.name); type = new char[strlen(obj.type) + 1]; strcpy_s(type, strlen(obj.type) + 1, obj.type); }

	void set_name(char* name_P);
	void set_type(char* type_P);
	void set_width(int width_P) { width = width_P; }
	void set_length(int length_P) { length = length_P; }
	void set_max_depth(int max_depth_P) { max_depth = max_depth_P; }

	// �������� ���������� ������
	int calculate_volume() const { return width * length * max_depth; }
	// �������� ���������� �������
	int calculate_area() const { return width * length; } 
	// �������� ��������� ����
	int if_type_same(const reservior& obj) const;
	// �������� ��������� ��������
	int compare_areas(const reservior& obj) const;
	// �������� ���������� ��������� ������������
	reservior& operator=(const reservior& obj);

	// ����� ������ (����� ������ ���������� ���������� ����� � ������ ������ �������� ��� ���� ����� � ���� ������� �� ������ � �� ��������������)
	void print() const
	{
		cout << name << '\t' << type << '\t' << width << '\t'  << length  << '\t'  << max_depth; 
	}

	const char* get_name() const { return name; }
	const char* get_type() const { return type; }
	// ������ ������������� ��������� ���������� ����������� ������ �� ������� ��� �������� � � ������ ������ � �������� ����
	const int& get_width() const { return width; }
	const int& get_length() const { return length; }
	const int& get_max_depth() const { return max_depth; }

	// ����������
	~reservior()
	{
		delete[] name;
		delete[] type;
	}
};

