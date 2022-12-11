#include "Database.h"

void Database::w_file(int _value, int _mode)
{
	if (_mode == -1)
	{
		fout.open(path, ios::trunc);
		fout.close();
	}
	fout.open(path, ios::app);
	for (int i = Tick.size() - _value; i < Tick.size(); i++)
	{
		fout << Tick[i].get_number() << ";" << Tick[i].get_destination() << ";" << Tick[i].get_data() << ";" << Tick[i].get_departureTime() << ";"
			<< Tick[i].get_arrivalTime() << ";" << Tick[i].get_ticketPrice() << ";" << Tick[i].get_remainingiTickets() << ";" << Tick[i].get_sellTickets() <<";" << "\n";
	}
	fout.close();
}

vector<string> split(string _str)
{
	vector<string> split_string;
	while (!_str.empty())
	{
		split_string.push_back(_str.substr(0, _str.find(";")));
		_str.erase(0, _str.find(";") + 1);
	}
	return split_string;
}

void Database::r_file()
{

	f.open(path);
	string _line;
	vector<string> split_str;
	while (!f.eof())
	{
		getline(f, _line);
		if (_line.size() != 0)
		{
			split_str = split(_line);
			Tick.push_back(Flight(split_str[0], split_str[1], split_str[2], split_str[3], split_str[4], split_str[5], split_str[6], split_str[7]));
		}
	}
	f.close();
}