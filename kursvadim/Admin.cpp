#include "Admin.h"



void Admin::change()
{
	bool _check = true;
	int _num;
	cout << "Какую запись вы хотите Отредактировать?\n";
	cin >> _num;
	cin.clear();
	getchar();
	if (_num > Tick.size() || _num < 1)
		throw exception("Такого билета не существует!\n");
	try
	{
		Tick[_num - 1] = Flight();
		cout << "Запись успешно отредакторовна!\n";

	}
	catch (const std::exception&exc)
	{
		cout << exc.what();
	}
	w_file(Tick.size(), -1);
}

void Admin::_delete()
{
	bool _check = true;
	int _num;
	cout << "Какую запись вы хотите удалить?\n";
	cin >> _num;
	cin.clear();
	getchar();
	if (_num > Tick.size() || _num < 1)
		throw exception("Такого билета не существует!\n");
	cout << "Вы действительно хотите удалить " << _num << " запись?\n1.Да\n2.Нет\n";
	while (_check)
	{
		switch (_getch())
		{
		case '1':
			Tick.erase(Tick.begin() + _num - 1);
			w_file(Tick.size(), -1);
			cout << "Запись успешно удалена!\n";
			_check = false;
			break;
		case '2':
			cout << "Вы отказались удалять запись!\n";
			_check = false;
			break;
		default:
			break;
		}
	}
}

void Admin::output()
{
	cout << " № рейса " << "|   Пункт назначения    " << "| Дата отправления " << "| Время отправления " << "| Время прибытия " << "| Стоимость билета " << "| Оставшиеся билеты " << "| Проданные билеты |\n";
	for (int i = 0; i < Tick.size(); i++)
	{
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << setw(9) << left << Tick[i].get_number() << "|" << setw(23) << left << Tick[i].get_destination() << "|" << setw(18) << left << Tick[i].get_data() << "|" << setw(19) << left << Tick[i].get_departureTime() << "|"
			<< setw(15) << left << Tick[i].get_arrivalTime() << " |" << setw(18) << left << Tick[i].get_ticketPrice() << "|" << setw(19) << left << Tick[i].get_remainingiTickets() << "|" << setw(17) << left << Tick[i].get_sellTickets() << " |" << endl;
	}
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void Admin::add()
{
	cout << "Сколько записей вы вы хотите создать?\n";
	int n;
	int _value = 0;
	cin >> n;
	cin.clear();
	getchar();
	for (int i = 0; i < n; i++)
	{
		try
		{
			Tick.push_back(Flight());

		}
		catch (const std::exception&ex)
		{
			cout << ex.what();
			continue;
		}
		_value++;
		cout << "Запись сохранена в файл!\n";
	}
	if (_value != 0)
		w_file(_value, 0);
}


void Admin::main_loop()
{
	r_file();
	bool _check = true;
	cout << "Добро пожаловать, администратор!\n";
	while (_check)
	{

		cout << "1.Посмотреть все доступные билеты\n2.Добавить билет\n3.Отредактировать запись о билете\n4.Удалить запись о билете\n5.Выход\n";
		try
		{
			switch (_getch())
			{
			case '1':
				output();
				break;
			case '2':
				add();
				break;
			case '3':
				change();
				break;
			case '4':
				_delete();
				break;
			case '5':
				Tick.clear();
				cout << "Завершение работы!\nВсе данные сохранены в файл\nПуть к файлу -> " << path << endl;
				_check = false;
				break;
			default:
				break;
			}
		}
		catch (const std::exception&excc)
		{
			cout << excc.what();
		}
		
	}
}