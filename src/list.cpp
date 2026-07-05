#include <iostream>
#include "list.h"


void addList(ListNode*& head, const addresses& data){
    ListNode* adr = new ListNode;

    adr -> data = data;
    adr -> next = head;

    head = adr;
}

void memory_clear(ListNode*& head){

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}