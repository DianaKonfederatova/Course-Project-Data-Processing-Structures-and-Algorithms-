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

void add_AVL(const addresses& D, vertex*& p, bool& Rost);
void print_tree(vertex* p);
void tree_search(vetrex* p, const char* search_name);

#endif 