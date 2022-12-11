#pragma once
#include "Database.h"
class Admin :
    public Database
{
    void _delete();
    void add();
    void change();
public:
    void main_loop();
    void output();
};

