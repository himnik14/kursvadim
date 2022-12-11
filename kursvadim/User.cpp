#include "User.h"

void out(vector<Flight> vec)
{
	cout << " � ����� " << "|   ����� ����������    " << "| ���� ����������� " << "| ����� ����������� " << "| ����� �������� " << "| ��������� ������ " << "| ���������� ������ " << "| ��������� ������ |\n";
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
	regex reg("[�-��-�\\s\\-]*");
	string _str;
	vector<Flight> vec;
	cout << "������� ����� ����������: ";
	getline(cin, _str);
	if (_str.empty() || !regex_match(_str, reg))
		throw exception("�� ����� ������ ������ ��� ������������ �� ������ ������� �������� �����!\n");
	for (int i = 0; i < Tick.size(); i++)
	{
		if (Tick[i].get_destination().find(_str) != -1) //���� ������� �� ������, ������������ ����� �������
			vec.push_back(Tick[i]);
	}
	if (vec.size() == 0)
		throw exception("����� ������� ���!\n");
	cout << "��� ��� �� ������ ����� ��� ���!\n\n";
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
	cout << "\n������� ����� ������ ������� ������ ������\n";
	cin >> _num;
	if (_num < 0 || _num > Tick.size())
		throw exception("������, ������ ������ ����� ���!\n");
	cout << "��� ������� �������� " << Tick[_num - 1].get_remainingiTickets() << " ������� \n������� ������� �� ������� ������?\n";
	cin >> _count;
	cin.clear();
	getchar();
	if (_count > Tick[_num - 1].get_remainingiTickets())
		throw exception("�� �� ������ ������ ������� ������, ��� ���� � �������!\n");
	else if (_count <= 0)
		throw exception("�� �� ������ ������ ���� �������!\n");
	cout << "��� ����� ��� ������ " << _count * stoi(Tick[_num - 1].get_ticketPrice()) << " ������!\n������� 1, ���� �������� ��������. ����� ������ ������ ����� ����������!\n";
	switch (_getch())
	{
	case '1':
		break;
	default:
		throw exception("�� ���������� �������� ������!\n");
		break;
	}
	cout << "�� ������� ������ " << _count << " �������, ��������� ���� � ������ " << Tick[_num - 1].get_destination() << endl;
	Tick[_num - 1].set_remainingiTickets(Tick[_num-1].get_remainingiTickets() - _count);
	Tick[_num - 1].set_sellTickets(Tick[_num - 1].get_sellTickets() + _count);
	w_file(Tick.size(), -1);
}

void User::main_loop()
{
	r_file();
	bool _check = true;
	cout << "����� ����������, ������������!\n";
	while (_check)
	{
		cout << "1.���������� ��� ��������� ������\n2.����� ������ �� ������ ����������\n3.���������� ������� �� ��������\n4.���������� �����������\n5.������� ������\n6.�����\n";
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
				cout << "���������� ������!\n��� ������ ��������� � ����\n���� � ����� -> " << path;
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