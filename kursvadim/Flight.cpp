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
		throw exception("���� ���� ������ ���� ������� � ������� dd.mm.yyyy!\n");
	else if (_data.empty())
		throw exception("�� ����� ������ ������!\n");
	else if (stoi(_data.substr(0, 2)) > 31 || stoi(_data.substr(0, 2)) <= 0)
		throw exception("��� ������ �� 1 �� 31!\n");
	else if (stoi(_data.substr(3, 5)) > 12 || stoi(_data.substr(3, 5)) <= 0)
		throw exception("������� �� 1 �� 12!\n");
	else if (stoi(_data.substr(6, 9)) > 2023 || stoi(_data.substr(6, 9)) < 2022)
		throw exception("���� �� 2022 �� 2023!\n");
	this->_data = _data;
}

void Flight::set_arrivalTime(string _arrivalTime)
{
	if (_arrivalTime.empty())
		throw exception("�� ����� ������ ������!\n");
	else if (_arrivalTime.size() != 5)
		throw exception("�������� ������ ������ ������� ��������!\n");
	else if (!regex_match(_arrivalTime, regex("[0-9\\:]*")))
		throw exception("� ���� ����� ��������� ������� ������ ����� � ������ ���������(:)!\n");
	else if (stoi(_arrivalTime.substr(0, 2)) < 0 || stoi(_arrivalTime.substr(0, 2)) > 24 || stoi(_arrivalTime.substr(3, 4)) < 0 || stoi(_arrivalTime.substr(3, 4)) > 59)
		throw exception("����� �������� ������ ���� �������� � ������� hh:mm, ��� ���������� ����� �� 0 �� 24!\n");
	this->_arrivalTime = _arrivalTime;
}

void Flight::set_departureTime(string _departureTime)
{
	if (_departureTime.empty())
		throw exception("�� ����� ������ ������!\n");
	else if (_departureTime.size() != 5)
		throw exception("�������� ������ ������ ������� �������!\n");
	else if (!regex_match(_departureTime, regex("[0-9\\:]*")))
		throw exception("� ���� ����� ��������� ������� ������ ����� � ������ ���������(:)!\n");
	else if (stoi(_departureTime.substr(0, 2)) < 0 || stoi(_departureTime.substr(0, 2)) > 24 || stoi(_departureTime.substr(3, 4)) < 0 || stoi(_departureTime.substr(3, 4)) > 59)
		throw exception("����� ������� ������ ���� �������� � ������� hh:mm, ��� ���������� ����� �� 0 �� 24!\n");
	this->_departureTime = _departureTime;
}

void Flight::set_destination(string _destination)
{
	if (_destination.empty())
		throw exception("���� \"����� ����������\" �� ����� ���� ������!\n");
	else if (!regex_match(_destination, regex("[�-�\\s]*")))
		throw exception("� ���� \"����� ���������\" �������� ���� ������ ������� ���� ������ �������� � ������ �������!\n");
	this->_destination = _destination;
}

void Flight::set_number(int _number)
{
	if (_number <= 0)
		throw exception("����� ������ ���� ����������� ������ ������ ����!\n");
	this->_number = _number;
}

void Flight::set_remainingiTickets(int _remainingiTickets)
{
	if (_remainingiTickets < 0)
		throw exception("���������� ���������� ������� ������ ���� ����������� ������ ������ ����!\n");
	this->_remainingiTickets = _remainingiTickets;
}

void Flight::set_sellTickets(int _sellTickets)
{
	this->_sellTickets = _sellTickets;
}

void Flight::set_ticketPrice(string _ticektPrice)
{
	if (_ticektPrice.empty())
		throw exception("�� ����� ������ ������!\n");
	else if (!regex_match(_ticektPrice, regex("[0-9\\.]*")))
		throw exception("� ���� \"��������� ������\" ��������� ������ ����� � �����!\n");
	else if (stoi(_ticektPrice) < 500 || stoi(_ticektPrice) > 999999)
		throw exception("����������� ��������� ������ 500 ������, ������������ 999999 ������!\n");
	this->_ticketPrice = _ticektPrice;
}

Flight::Flight()
{
	string _str;
	int _value;
	this->_sellTickets = 0;
	try
	{
		cout << "������� ����� �����\n";
		cin >> _value;
		set_number(_value);
		cin.clear();
		getchar();
		cout << "������� ����� ����������\n";
		getline(cin, _str, '\n');
		set_destination(_str);
		cout << "������� ���� �����������\n";
		getline(cin, _str);
		set_data(_str);
		cout << "������� ����� �����������\n";
		getline(cin, _str);
		set_departureTime(_str);
		cout << "������� ����� ��������\n";
		getline(cin, _str);
		set_arrivalTime(_str);
		cout << "������� ��������� ������\n";
		getline(cin, _str);
		set_ticketPrice(_str);
		cout << "������� ���������� ��������� ��� ������� �������\n";
		cin >> _value;
		set_remainingiTickets(_value);
		cin.clear();
		getchar();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("������ �� ���� ���������!\n");
	}
}