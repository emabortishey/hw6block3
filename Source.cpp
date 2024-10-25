//#include <stdio.h>
#include "reservior.h"
#include <fstream>

enum meow { fill_all = 1, fill_index, show_all, show_index, calc_volume, calc_area, if_type_ssame, compare_area, write_infile, write_binary, delete_index, add_new };

int main()
{
	setlocale(LC_ALL, "russian");

	int choice{ -1 }, choice2{ -1 }, size{ 4 };
	char* buff_name{ new char[100] }, * buff_type{ new char[100] };
	int buff_width, buff_length, buff_max_depth;
	FILE* info;

	char buff11[100]{ "meow1" };
	char buff12[100]{ "meow2" };
	char buff21[100]{ "bark1" };
	char buff22[100]{ "bark2" };

	reservior* water = new reservior[size];

	do {

		cout << "\n\nВведите выбор:\n1. Заполнить всё\n2. Заполнить какой-либо индекс\n3. Вывести всё\n4. Вывести по индексу\n5. Вычислить объём по индексу\n6. Вычислить площадь по индексу\n7. Сравнить типы\n8. Сравнить площадь одинаковых типов\n9. Записать в файл весь массив\n10. Удалить по индексу\n11. Добавить в конец 1 водоём\n0. Выход\n";
		cin >> choice;

		switch (choice)
		{

		case  fill_all:
		{
			for (int i = 0; i < size; i++)
			{
				cin.ignore();

				gets_s(buff_name, 100);
				gets_s(buff_type, 100);
				cin >> buff_width;
				cin >> buff_length;
				cin >> buff_max_depth;

				water[i].set_name(buff_name);
				water[i].set_type(buff_type);
				water[i].set_width(buff_width);
				water[i].set_length(buff_length);
				water[i].set_max_depth(buff_max_depth);
			}
			break;
		}
		case fill_index:
		{
			cout << "\nВведите индекс: ";
			cin >> choice;

			cin.ignore();

			gets_s(buff_name, 100);
			gets_s(buff_type, 100);
			cin >> buff_width;
			cin >> buff_length;
			cin >> buff_max_depth;

			water[choice].set_name(buff_name);
			water[choice].set_type(buff_type);
			water[choice].set_width(buff_width);
			water[choice].set_length(buff_length);
			water[choice].set_max_depth(buff_max_depth);

			choice = -1;

			break;
		}
		case show_all:
		{
			for (int i = 0; i < size; i++)
			{
				cout << "\nВодоём номер " << i+1 << ": ";
				water[i].print();
			}
			break;
		}
		case show_index:
		{
			cout << "\nВведите индекс: ";
			cin >> choice;
			cout << "\nВодоём под индексом " << choice << ": ";
			water[choice].print();
			choice = -1;
			break;
		}
		case calc_volume:
		{
			cout << "\nВведите индекс водоёма: ";
			cin >> choice;
			cout << "\nОбъём водоёма равен: " << water[choice].calculate_volume();
			choice = -1;
			break;
		}
		case calc_area:
		{
			cout << "\nВведите индекс водоёма: ";
			cin >> choice;
			cout << "\nПлощадь водоёма равна: " << water[choice].calculate_area();
			choice = -1;
			break;
		}
		case if_type_ssame:
		{
			cout << "\nВведите два индекса массива для сравнения: ";
			cin >> choice >> choice2;
			if (water[choice].if_type_same(water[choice2]) == 0)
			{
				cout << "\nТипы водоёмов одинаковы";
			}
			else
			{
				cout << "\nТипы водоёмов разные";
			}

			choice = -1, choice2 = -1;
			break;
		}
		case compare_area:
		{
			cout << "\nВведите два индекса массива для сравнения: ";
			cin >> choice >> choice2;
			if (water[choice].compare_areas(water[choice2]) == 0)
			{
				cout << "\nПлощади водоёмов одинаковы";
			}
			else if (water[choice].compare_areas(water[choice2]) == 1)
			{
				cout << "\nПервый водоём больше второго";
			}
			else if (water[choice].compare_areas(water[choice2]) == -1)
			{
				cout << "\nПервый водоём меньше второго";
			}
			else
			{
				cout << "\nТипы водоёмов разные, сравнение невозможно";
			}

			choice = -1, choice2 = -1;
			break;
		}
		case write_infile:
		{
			if (fopen_s(&info, "info.txt", "w") == 0)
			{
				cout << "\n\n(файл успешно открыт для перезаписи)";
			}

			for (int i = 0; i < size; i++)
			{
				fprintf_s(info, "%s ", water[i].get_name());
				fprintf_s(info, "%s ", water[i].get_type());
				fprintf_s(info, "%d ", water[i].get_width());
				fprintf_s(info, "%d ", water[i].get_length());
				fprintf_s(info, "%d\n", water[i].get_max_depth());
			}

			if (fclose(info) == 0)
			{
				cout << "\n\n(файл успешно закрыт после перезаписи)";
			}
			break;
		}
		case write_binary:
		{

			char* y = new char[100];
			int x = 0;

			ofstream file("info1.txt", ios::binary | ios::out);

			for (int i = 0; i < size; i++)
			{
				file.write((char*)water[i].get_name(), strlen(water[i].get_name()));
				file.write((char*)&" ",sizeof " ");
				file.write((char*)water[i].get_type(), strlen(water[i].get_type()));
				file.write((char*)&" ", sizeof " ");
				file.write((char*)&water[i].get_width(), sizeof water[i].get_width());
				file.write((char*)&water[i].get_length(), sizeof water[i].get_length());
				file.write((char*)&water[i].get_max_depth(), sizeof water[i].get_max_depth());
			}

			file.close();

			ifstream file2("info1.txt", ios::binary | ios::in);

			for (int i = 0; i < size; i++)
			{

				file2.read((char*)y, 100);
				cout << y << '\t';
				file2.read((char*)y, 100);
				cout << y << '\t';
				file2.read((char*)x, sizeof x);
				cout << x << '\t';
				file2.read((char*)x, sizeof x);
				cout << x << '\t';
				file2.read((char*)x, sizeof x);
				cout << x << '\n';
			}

			file2.close();

			break;
		}
		case delete_index:
		{
			cout << "\nВведите индекс элемента для удаления: ";
			cin >> choice;

			for (int i = choice; i < size-1; i++)
			{
				water[i]= water[i + 1];
			}

			size--;

			water[size].~reservior();

			choice = -1;

			break;
		}
		case add_new:
		{
			
			reservior* buff_mass = new reservior[size + 1];

			for (int i = 0; i < size; i++)
			{
				buff_mass[i] = water[i];
			}

			for (int i = 0; i < size; i++)
			{
				water[i].~reservior();
			}

			size+=1;

			reservior* water = new reservior[size];

			for (int i = 0; i < size; i++)
			{
				water[i]= buff_mass[i];
			}

			choice = -1;

			break;
		}
		}
	} while (choice != 0);

	

	return 0;
}