#include "Admin.h"



void Admin::change()
{
	bool _check = true;
	int _num;
	cout << "����� ������ �� ������ ���������������?\n";
	cin >> _num;
	cin.clear();
	getchar();
	if (_num > Tick.size() || _num < 1)
		throw exception("������ ������ �� ����������!\n");
	try
	{
		Tick[_num - 1] = Flight();
		cout << "������ ������� ��������������!\n";

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
	cout << "����� ������ �� ������ �������?\n";
	cin >> _num;
	cin.clear();
	getchar();
	if (_num > Tick.size() || _num < 1)
		throw exception("������ ������ �� ����������!\n");
	cout << "�� ������������� ������ ������� " << _num << " ������?\n1.��\n2.���\n";
	while (_check)
	{
		switch (_getch())
		{
		case '1':
			Tick.erase(Tick.begin() + _num - 1);
			w_file(Tick.size(), -1);
			cout << "������ ������� �������!\n";
			_check = false;
			break;
		case '2':
			cout << "�� ���������� ������� ������!\n";
			_check = false;
			break;
		default:
			break;
		}
	}
}

void Admin::output()
{
	cout << " � ����� " << "|   ����� ����������    " << "| ���� ����������� " << "| ����� ����������� " << "| ����� �������� " << "| ��������� ������ " << "| ���������� ������ " << "| ��������� ������ |\n";
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
	cout << "������� ������� �� �� ������ �������?\n";
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
		cout << "������ ��������� � ����!\n";
	}
	if (_value != 0)
		w_file(_value, 0);
}


void Admin::main_loop()
{
	r_file();
	bool _check = true;
	cout << "����� ����������, �������������!\n";
	while (_check)
	{

		cout << "1.���������� ��� ��������� ������\n2.�������� �����\n3.��������������� ������ � ������\n4.������� ������ � ������\n5.�����\n";
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
				cout << "���������� ������!\n��� ������ ��������� � ����\n���� � ����� -> " << path << endl;
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