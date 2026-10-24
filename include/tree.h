#ifndef TREE_H
#define TREE_H

#include <database.h>
#include <iostream>
#include <fstream>

struct vertex{

    int Bal = 0;
    addresses adr;
    vertex* left;
    vertex* right;

};

int apartment_comparison(short int apart1, short int apart2);
void add_AVL(const addresses& D, vertex*& p, bool& Rost);
void print_tree(vertex* p);
void tree_search(vertex* p, short search_apartment);
void clear_tree(vertex* p);

#endif 