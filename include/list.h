#ifndef LIST_H
#define LIST_H

#include "database.h"

struct ListNode{
    addresses data;
    ListNode* next;
};

void addList(ListNode*& head, const addresses& newData);
void memory_clear(ListNode*& head);
void transcodingCP866_for_UTF8(const char* str, int len);
void print_list (ListNode* head);

#endif