#ifndef LIST_H
#define LIST_H

#include "database.h"

struct ListNode{
    addresses data;
    ListNode* next;
};

void addList(ListNode*& head, const addresses& newData);
void memory_clear(ListNode*& head);

#endif