//#include <stdio.h>
#include "reservior.h"
#include <fstream>

enum meow { fill_all = 1, fill_index, show_all, show_index, calc_volume, calc_area, if_type_ssame, compare_area, write_infile, write_binary, delete_index, add_new };

int main()
{
	setlocale(LC_ALL, "russian");

	// выбор 1 - основной выбор для работы меню, choice2 - второй выбор для 7 и 8 пункта
	int choice{ -1 }, choice2{ -1 }, size{ 4 };
	// переменные для пункта 1 (заполнение всего массива)
	char* buff_name{ new char[100] }, * buff_type{ new char[100] };
	int buff_width, buff_length, buff_max_depth;
	// обьявление файла для обычной записи
	FILE* info;

	// буферная переменная, использовавшаяся для проверки записи и вывода из бинарного файла (имя и тип)
	char* y = new char[100];
	// также буферная переменная для проверки бинарного файла (длина, ширина, макс. глубина)
	int x = 0;

	reservior* water = new reservior[size];

	do {

		cout << "\n\nВведите выбор:\n1. Заполнить всё\n2. Заполнить какой-либо индекс\n3. Вывести всё\n4. Вывести по индексу\n5. Вычислить объём по индексу\n6. Вычислить площадь по индексу\n7. Сравнить типы\n8. Сравнить площадь одинаковых типов\n9. Записать в файл весь массив\n10. Записать в бинарный файл весь массив\n11. Удалить по индексу\n12. Добавить в конец 1 водоём\n0. Выход\n";
		cin >> choice;

		switch (choice)
		{

		case  fill_all:
		{
			for (int i = 0; i < size; i++)
			{
				cin.ignore(); // после ввода выбора необходим

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

			cin.ignore(); // после ввода выбора необходим

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

			// на всякий случай при каждом действии с переменной в конце ей присваивается -1, чтобы в случае её равенства 0 программа не завершилась
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
			// вызов метода для расчёта объёма
			cout << "\nОбъём водоёма равен: " << water[choice].calculate_volume();
			choice = -1;
			break;
		}
		case calc_area:
		{
			cout << "\nВведите индекс водоёма: ";
			cin >> choice;
			// вызов метода для расчёта площади
			cout << "\nПлощадь водоёма равна: " << water[choice].calculate_area();
			choice = -1;
			break;
		}
		case if_type_ssame:
		{
			cout << "\nВведите два индекса массива для сравнения: ";
			cin >> choice >> choice2;
			// в случае одинаковости как и стр компарейшен возвращает 0 и идёт проверка на равенство нулю
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
			// на счёт чтения из файла в задании сказано не был поэтому я решила не заморачиваться
			// и плюсом записала всё на разные строки с помощью последнего фпринтф в цикле для красоты, раз уж вывод не важен

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
			// обьявление файла для бинарной записи
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

			// я не поняла насколько важно закрытие бинарного файла для результата, так как вроде у меня и без этого
			// работало прекрасно, но подстраховка не помешает

			file.close(); 

			//////////////// КОД ПРОВЕРКИ ПРАВИЛЬНОСТИ ЗАПИСАННОЙ ИНФОРМАЦИИ В БИНАРНЫЙ ФАЙЛ (ВЫВОД СОДЕРЖИМОГО) НАЧАЛО ////////////////

			/*ifstream file2("info1.txt", ios::binary | ios::in);

			for (int i = 0; i < size; i++)
			{
				// так как размер массива чисел переменной игрик (она названаа так, потому что не задействуется в общем коде и создана чисто для проверки)
				//всегда равен 100, сайзоф не используется (не знаю, он посчитал бы выделенную память или записанную, не помню точно, но это подстраховка)

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

			file2.close();*/

			//////////////// КОД ПРОВЕРКИ ПРАВИЛЬНОСТИ ЗАПИСАННОЙ ИНФОРМАЦИИ В БИНАРНЫЙ ФАЙЛ (ВЫВОД СОДЕРЖИМОГО) КОНЕЦ ////////////////


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

			size--; // уменьшается размер

			// вызывается деструктор на последний элемент после копирования значений

			water[size].~reservior();

			choice = -1;

			break;
		}
		case add_new:
		{
			// вот тут все ошибки шредингера этой программы, они и отсутствуют и присутствуют где-то одновременно
			// при работе с откладчиком я проверила пошаговое выполнение этого пункта и всё идёт хорошои без ошибок, а копирование
			// происходит абсолютно успешно, НО когда после этого пункта я выбираю вывод всего массива откуда-то в массив
			// записываются мусорные значения, а добавленный, последний индекс массива, оно вообще не выводит, после чего программа заканчивается
			// ошибкой и сколько бы я не проверяла, я не могла понять, где между действием добавления индекса и вывода в массив попадает мусор, поэтому
			// решила просто оставить всё как есть

			// буферный массив с размером +1 от старого
			reservior* buff_mass = new reservior[size + 1];

			// копирование всех элементов из старого в буферный массив
			for (int i = 0; i < size; i++)
			{
				buff_mass[i] = water[i];
			}

			// пошаговое удаление старого
			for (int i = 0; i < size; i++)
			{
				water[i].~reservior();
			}

			size++;

			// пересоздание массива с именем старого и последующее копирование (которое проходит успешно)
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