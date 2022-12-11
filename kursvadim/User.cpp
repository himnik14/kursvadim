#include "User.h"

void out(vector<Flight> vec)
{
	cout << " № рейса " << "|   Пункт назначения    " << "| Дата отправления " << "| Время отправления " << "| Время прибытия " << "| Стоимость билета " << "| Оставшиеся билеты " << "| Проданные билеты |\n";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout  << setw(8) << left << vec[i].get_number() << "|" << setw(23) << left << vec[i].get_destination() << "|" << setw(18) << left << vec[i].get_data() << "|" << setw(19) << left << vec[i].get_departureTime() << "|"
			<< setw(15) << left << vec[i].get_arrivalTime() << " |" << setw(18) << left << vec[i].get_ticketPrice() << "|" << setw(19) << left << vec[i].get_remainingiTickets() << "|" << setw(17) << left << vec[i].get_sellTickets() << " |" << endl;
	}
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n";
}



vector<Flight> User::scan()
{
	
	bool _check = true;
	regex reg("[А-Яа-я\\s\\-]*");
	string _str;
	vector<Flight> vec;
	cout << "Введите пункт назначения: ";
	getline(cin, _str);
	if (_str.empty() || !regex_match(_str, reg))
		throw exception("Вы ввели пустую строку или использовали не только символы русского языка!\n");
	for (int i = 0; i < Tick.size(); i++)
	{
		if (Tick[i].get_destination().find(_str) != -1) //Если элемент не найден, возвращается минус единица
			vec.push_back(Tick[i]);
	}
	if (vec.size() == 0)
		throw exception("Таких билетов нет!\n");
	cout << "Вот что мы смогли найти для вас!\n\n";
	out(vec);
	return vec;
}

void User::alphabetical_sorting()
{
	for (int i = 0; i < Tick.size() - 1; i++)
	{
		for (int j = i + 1; j < Tick.size(); j++)
		{
			if (strcmp(Tick[i].get_destination().c_str(), Tick[j].get_destination().c_str()) > 0)
				swap(Tick[i], Tick[j]);
		}
	}
	output();
}

void User::def_sort()
{
	Tick.clear();
	r_file();
	output();
}

void User::buy_ticket()
{
	system("cls");
	output();
	int _num, _count;	
	cout << "\nВведите номер билета который хотите купить\n";
	cin >> _num;
	if (_num < 0 || _num > Tick.size())
		throw exception("Ошибка, такого билета здесь нет!\n");
	cout << "Для покупки доступно " << Tick[_num - 1].get_remainingiTickets() << " билетов \nСколько билетов вы желаете купить?\n";
	cin >> _count;
	cin.clear();
	getchar();
	if (_count > Tick[_num - 1].get_remainingiTickets())
		throw exception("Вы не можете купить билетов больше, чем есть в наличии!\n");
	else if (_count <= 0)
		throw exception("Вы не можете купить ноль билетов!\n");
	cout << "Это будет вам стоить " << _count * stoi(Tick[_num - 1].get_ticketPrice()) << " рублей!\nНажмите 1, если согласны покупать. Любую другую кнопку чтобы отказаться!\n";
	switch (_getch())
	{
	case '1':
		break;
	default:
		throw exception("Вы отказались покупать билеты!\n");
		break;
	}
	cout << "Вы успешно купили " << _count << " билетов, приятного пути в городе " << Tick[_num - 1].get_destination() << endl;
	Tick[_num - 1].set_remainingiTickets(Tick[_num-1].get_remainingiTickets() - _count);
	Tick[_num - 1].set_sellTickets(Tick[_num - 1].get_sellTickets() + _count);
	w_file(Tick.size(), -1);
}

void User::main_loop()
{
	r_file();
	bool _check = true;
	cout << "Добро пожаловать, пользователь!\n";
	while (_check)
	{
		cout << "1.Посмотреть все доступные билеты\n2.Поиск билета по пункту назначения\n3.Сортировка билетов по алфавиту\n4.Сортировка изначальная\n5.Покупка билета\n6.Выйти\n";
		try
		{
			switch (_getch())
			{
			case '1':
				output();
				break;
			case '2':
				scan();
				break;
			case '3':
				alphabetical_sorting();
				break;
			case '4':
				def_sort();
				break;
			case '6':
				Tick.clear();
				cout << "Завершение работы!\nВсе данные сохранены в файл\nПуть к файлу -> " << path;
				_check = false;
				break;
			case '5':
				buy_ticket();
				break;
			default:
				break;
			}
		}
		catch (const std::exception& excc)
		{
			cout << excc.what();
		}

	}
}