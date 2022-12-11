#pragma once
#include "Flight.h"
class Database
{
	ifstream f;
	ofstream fout;
public:
	vector<Flight> Tick;
	void r_file();
	void w_file(int _value, int _mode);
protected:
	string path = "C:\\Games\\DataBase.txt";

};

