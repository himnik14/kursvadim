#include <iostream>
#include "Flight.h"
#include "Admin.h"
#include "User.h"
int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Admin a;
	User u;
	bool _check = true;
	while (_check)
	{
		cout << "Доброго времени суток, с каким режимом доступа вы хотите зайти?\n1.Администратор\n2.Пользователь\n3.Выход\n";
		switch (_getch())
		{
		case '1':
			system("cls");
			a.main_loop();
			break;
		case '2':
			system("cls");
			u.main_loop();
			break;
		default:
			cout << "До свидания!\n";
			_check = false;
			break;
		}
	}

	
}
