#pragma once
#include <string>
#include <regex>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;
class Flight
{
	int _number, _remainingiTickets, _sellTickets;
	string _destination, _departureTime, _arrivalTime, _ticketPrice, _data;
public:
	Flight(string _number, string _destination, string _data, string _departureTime, string _arrivalTime, string _ticketPrice, string _remainingiTickets, string _sellTickets);
	void set_number(int _number);
	void set_remainingiTickets(int _remainingiTickets);
	void set_destination(string _destination);
	void set_departureTime(string _departureTime);
	void set_arrivalTime(string _arrivalTime);
	void set_ticketPrice(string _ticketPrice);
	void set_sellTickets(int _sellTickets);
	void set_data(string _data);
	int get_number();
	int get_remainingiTickets();
	int get_sellTickets();
	string get_destination();
	string get_departureTime();
	string get_arrivalTime();
	string get_ticketPrice();
	string get_data();
	Flight();
};

