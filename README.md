Всё работает крута за исплючением последнего пункта меню (добавление индекса). В этом пункте я выполняю
создание буферного массива с размером+1к размеру нынешнего,
копирую из нынешнего в буферный с помощью перегрузки
оператора присваивания (перегрузка работает исправно, проверено), после удаляю нынешний и создаю
новый массив с именем как у удалённого но с размером на 1 больше прошлого и затем копирую в него 
все значения из буфера. На этом моменте в откладчике значения присваиваются правильно и всё идёт нормально,
но после окончания работы по добавлению и выборе пользователем вывода массива, на экран выводятся мусорные
значения, которое как я понимаю появляются в промежутке между исполнением пункта добавления и 
пунктом по выводу массива и сколько бы я не пыталась разглядеть ошибку, на это ушло уже 5 дней и я
решила оставить всё как есть и надеяться что это ошибка не в коде и логике исполнения, а
просто какая-нибудь маленькая ошибка и это не сильно повлияет на оценку.

Далее о пункте в задании с "записью в бинарный файл". Я не знала, с помощью каких именно инструментов
необходимо выполнить этот пункт, поэтому загуглив, нашла статью (https://metanit.com/cpp/tutorial/8.2.php)
о том как использовать библиотеку
fstream и вопрос на киберфоруме (https://www.cyberforum.ru/cpp-beginners/thread2644109.html),
связанный с бинарными файлами, с помощью кода в ктором я поняла некоторые
вещи об использовании библиотеки. Так как при изучении нового материала нужно объяснять, то я постараюсь
расписать как я поняла статью и код в треде на киберфоруме

в библиотеке фстрим существует два файловых потока, ифстрим (для записи в файл) и офстрим
(для чтения из файла). При объявлении файла для записи или чтения нам необходимо указать тип 
(тот же офстрим или ифстрим) и любое имя файла, а в качестве параметров передать строку с именем файла и 
расширением как и в обычном опенф, а также режим (ios::out - для записи в файл и ios::in для чтения
из файла). Я изучила только два метода,это write и read, чисто чтобы выполнить задание,
поэтому расскажу только о них. Думаю в write мы принимаем (char*)& для какого-то рода конвертирования 
для последующей записи, а размер что-то вроде того, что мы указываем в функциях с _s для 
их использования без утечки данных, чтобы точно знать, сколько места занимает переменная
(в массивах символов ампрсант промущен потому что это и так является указателем и он не нужен)
Ну и в read практически такой же синтаксис, поэтому думаю его обьяснять не стоит.
Я конечно не слишком поняла все тонкости этой библиотеки, но для задания постаралась более-менее
разобраться с использованием этих примитивных функций