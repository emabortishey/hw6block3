#include "reservior.h"

void reservior::set_name(char* name_P)
{
	delete[] name;
	name = new char[strlen(name_P) + 1];
	strcpy_s(name, strlen(name) + 1, name_P);
}

void reservior::set_type(char* type_P)
{
	delete[] type;
	type = new char[strlen(type_P) + 1];
	strcpy_s(type, strlen(type) + 1, type_P);
}

int reservior::if_type_same(const reservior& obj) const
{
	if (strcmp(obj.type, type) == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int reservior::compare_areas(const reservior& obj) const
{ 
	if (if_type_same(obj) == 0) 
	{ 
		if (calculate_area() > obj.calculate_area()) 
		{ 
			return 1; 
		} 
		else if (calculate_area() < obj.calculate_area()) 
		{ 
			return -1;
		} 
		else
		{
			return 0;
		} 
	} 
}

