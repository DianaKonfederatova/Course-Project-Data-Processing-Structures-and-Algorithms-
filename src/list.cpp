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

void print_list(ListNode* head){
    int record_counter = 0;
    ListNode* temp = head;
    bool exit = false;

    while(temp != nullptr){
        std::cout << temp -> data.name << "\n";
        std::cout << temp -> data.street << "\n";
        std::cout << temp -> data.number_house << "\n";
        std::cout << temp -> data.apartment << "\n";
        std::cout << temp -> data.date_of_settlement << "\n";
        record_counter++;
        temp = temp -> next;

        if(record_counter == 20 && temp != nullptr){

            int answer;
            std::cout << "Смотреть записи дальше? 1 - продолжаем просмотр, 2 - отказ от просмотра\n";
            std::cin >> answer;

            while(answer != 1 && answer != 2){
                std::cout << "Выберите 1 или 2\n";
                std::cin >> answer;
            }

            if(answer == 1){
                record_counter = 0;
            }

            if(answer == 2){
                exit = true;
            }

        }

        if(exit == true){
            break;
        }
    }

}
