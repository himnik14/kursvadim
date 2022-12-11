#pragma once
#include "Admin.h"
class User :
    public Admin
{
public:
    void def_sort();
    vector<Flight> scan();
    void alphabetical_sorting();
    void buy_ticket();
    void main_loop();
};

