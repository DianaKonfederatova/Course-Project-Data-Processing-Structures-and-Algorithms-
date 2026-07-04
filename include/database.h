#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>

struct addresses{
    char name[32];
    char street[18];
    short int number_house;
    short int apartment;
    char date_of_settlement[10];
};

#endif 