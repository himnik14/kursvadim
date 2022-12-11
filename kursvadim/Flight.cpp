#include "Flight.h"

string Flight::get_data()
{
	return _data;
}

string Flight::get_arrivalTime()
{
	return _arrivalTime;
}

string Flight::get_departureTime()
{
	return _departureTime;
}

string Flight::get_destination()
{
	return _destination;
}

int Flight::get_number()
{
	return _number;
}

int Flight::get_remainingiTickets()
{
	return _remainingiTickets;
}

int Flight::get_sellTickets()
{
	return _sellTickets;
}

string Flight::get_ticketPrice()
{
	return _ticketPrice;
}

Flight::Flight(string _number, string _destination, string _data, string _departureTime, string _arrivalTime, string _ticketPrice, string _remainingiTickets, string _sellTickets)
{
	this->_number = stoi(_number);
	this->_destination = _destination;
	this->_data = _data;
	this->_departureTime = _departureTime;
	this->_arrivalTime = _arrivalTime;
	this->_ticketPrice = _ticketPrice;
	this->_remainingiTickets = stoi(_remainingiTickets);
	this->_sellTickets = stoi(_sellTickets);
}

void Flight::set_data(string _data)
{
	regex r("[0-9\Q.\E]*");
	if (!regex_match(_data.c_str(), r) || _data.length() != 10)
		throw exception("Поле дата должно быть введено в формате dd.mm.yyyy!\n");
	else if (_data.empty())
		throw exception("Вы ввели пустую строку!\n");
	else if (stoi(_data.substr(0, 2)) > 31 || stoi(_data.substr(0, 2)) <= 0)
		throw exception("Дни месяца от 1 до 31!\n");
	else if (stoi(_data.substr(3, 5)) > 12 || stoi(_data.substr(3, 5)) <= 0)
		throw exception("Месяцев от 1 до 12!\n");
	else if (stoi(_data.substr(6, 9)) > 2023 || stoi(_data.substr(6, 9)) < 2022)
		throw exception("Годы от 2022 до 2023!\n");
	this->_data = _data;
}

void Flight::set_arrivalTime(string _arrivalTime)
{
	if (_arrivalTime.empty())
		throw exception("Вы ввели пустую строку!\n");
	else if (_arrivalTime.size() != 5)
		throw exception("Неверный формат записи времени прибытия!\n");
	else if (!regex_match(_arrivalTime, regex("[0-9\\:]*")))
		throw exception("В поле время допустимо вводить только цифры и символ разделния(:)!\n");
	else if (stoi(_arrivalTime.substr(0, 2)) < 0 || stoi(_arrivalTime.substr(0, 2)) > 24 || stoi(_arrivalTime.substr(3, 4)) < 0 || stoi(_arrivalTime.substr(3, 4)) > 59)
		throw exception("Время прибытия должно быть записано в формате hh:mm, где количество часов от 0 до 24!\n");
	this->_arrivalTime = _arrivalTime;
}

void Flight::set_departureTime(string _departureTime)
{
	if (_departureTime.empty())
		throw exception("Вы ввели пустую строку!\n");
	else if (_departureTime.size() != 5)
		throw exception("Невырный формат записи времени отбытия!\n");
	else if (!regex_match(_departureTime, regex("[0-9\\:]*")))
		throw exception("В поле время допустимо вводить только цифры и символ разделния(:)!\n");
	else if (stoi(_departureTime.substr(0, 2)) < 0 || stoi(_departureTime.substr(0, 2)) > 24 || stoi(_departureTime.substr(3, 4)) < 0 || stoi(_departureTime.substr(3, 4)) > 59)
		throw exception("Время отбытия должно быть записано в формате hh:mm, где количество часов от 0 до 24!\n");
	this->_departureTime = _departureTime;
}

void Flight::set_destination(string _destination)
{
	if (_destination.empty())
		throw exception("Поле \"пункт назначения\" не может быть пустым!\n");
	else if (!regex_match(_destination, regex("[А-я\\s]*")))
		throw exception("В поле \"пункт назначния\" допустим ввод только русских букв любого регистра и символ пробела!\n");
	this->_destination = _destination;
}

void Flight::set_number(int _number)
{
	if (_number <= 0)
		throw exception("Номер должен быть натуральным числом больше нуля!\n");
	this->_number = _number;
}

void Flight::set_remainingiTickets(int _remainingiTickets)
{
	if (_remainingiTickets < 0)
		throw exception("Количество оставшихся билетов должно быть натуральным числом больше нуля!\n");
	this->_remainingiTickets = _remainingiTickets;
}

void Flight::set_sellTickets(int _sellTickets)
{
	this->_sellTickets = _sellTickets;
}

void Flight::set_ticketPrice(string _ticektPrice)
{
	if (_ticektPrice.empty())
		throw exception("Вы ввели пустую строку!\n");
	else if (!regex_match(_ticektPrice, regex("[0-9\\.]*")))
		throw exception("В поле \"стоимость билета\" допустимы только цифры и точка!\n");
	else if (stoi(_ticektPrice) < 500 || stoi(_ticektPrice) > 999999)
		throw exception("Минимальная стоимость билета 500 рублей, максимальная 999999 рублей!\n");
	this->_ticketPrice = _ticektPrice;
}

Flight::Flight()
{
	string _str;
	int _value;
	this->_sellTickets = 0;
	try
	{
		cout << "Введите номер рейса\n";
		cin >> _value;
		set_number(_value);
		cin.clear();
		getchar();
		cout << "Введите пункт назначения\n";
		getline(cin, _str, '\n');
		set_destination(_str);
		cout << "Введите дату отправления\n";
		getline(cin, _str);
		set_data(_str);
		cout << "Введите время отправления\n";
		getline(cin, _str);
		set_departureTime(_str);
		cout << "Введите время прибытия\n";
		getline(cin, _str);
		set_arrivalTime(_str);
		cout << "Введите стоимость билета\n";
		getline(cin, _str);
		set_ticketPrice(_str);
		cout << "Введите количество доступных для покупки билетов\n";
		cin >> _value;
		set_remainingiTickets(_value);
		cin.clear();
		getchar();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("Запись не была сохранена!\n");
	}
}