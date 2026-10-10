#ifndef LIST_H
#define LIST_H

#include "database.h"

struct ListNode{
    addresses data;
    ListNode* next;
};

struct Queue {
    ListNode* head;
    ListNode* tail;
};

void addList(ListNode*& head, const addresses& newData);
void memory_clear(ListNode*& head);
void transcodingCP866_for_UTF8(const char* str, int len);
void print_list (ListNode* head);
int compareStrings(const char* str1, const char* str2);
int street_comparison_house_number(const addresses& r1, const addresses& r2);
void queue_init(Queue& q);
void add_node_queue(Queue& q, ListNode* node);
ListNode* nodefrom_thebeginning_list(ListNode*& list);
void merging_of_series(ListNode*& a, int q, ListNode*& b, int r, Queue& c);
void add_to_end(ListNode*& list, ListNode* node);
void split_list(ListNode* S, ListNode*& a, ListNode*& b);
void mergeSort(ListNode*& S, int n);
int compareFirst_Chars(const char* str1, const char* str2, int n);

#endif