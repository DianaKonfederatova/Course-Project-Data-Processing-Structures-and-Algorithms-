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

void transcodingCP866_for_UTF8(const char* str, int len) {
    for (int i = 0; i < len; i++) {
        unsigned char c = (unsigned char)str[i];
        
        switch (c) {
            default:
                if (c < 0x80) {
                    std::cout << (char)c;
                } else {
                    std::cout << ' '; 
                }
                break;

            case 0x80: std::cout << "\xD0\x90"; break; // А
            case 0x81: std::cout << "\xD0\x91"; break; // Б
            case 0x82: std::cout << "\xD0\x92"; break; // В
            case 0x83: std::cout << "\xD0\x93"; break; // Г
            case 0x84: std::cout << "\xD0\x94"; break; // Д
            case 0x85: std::cout << "\xD0\x95"; break; // Е
            case 0x86: std::cout << "\xD0\x96"; break; // Ж
            case 0x87: std::cout << "\xD0\x97"; break; // З
            case 0x88: std::cout << "\xD0\x98"; break; // И
            case 0x89: std::cout << "\xD0\x99"; break; // Й
            case 0x8A: std::cout << "\xD0\x9A"; break; // К
            case 0x8B: std::cout << "\xD0\x9B"; break; // Л
            case 0x8C: std::cout << "\xD0\x9C"; break; // М
            case 0x8D: std::cout << "\xD0\x9D"; break; // Н
            case 0x8E: std::cout << "\xD0\x9E"; break; // О
            case 0x8F: std::cout << "\xD0\x9F"; break; // П
            case 0x90: std::cout << "\xD0\xA0"; break; // Р
            case 0x91: std::cout << "\xD0\xA1"; break; // С
            case 0x92: std::cout << "\xD0\xA2"; break; // Т
            case 0x93: std::cout << "\xD0\xA3"; break; // У
            case 0x94: std::cout << "\xD0\xA4"; break; // Ф
            case 0x95: std::cout << "\xD0\xA5"; break; // Х
            case 0x96: std::cout << "\xD0\xA6"; break; // Ц
            case 0x97: std::cout << "\xD0\xA7"; break; // Ч
            case 0x98: std::cout << "\xD0\xA8"; break; // Ш
            case 0x99: std::cout << "\xD0\xA9"; break; // Щ
            case 0x9A: std::cout << "\xD0\xAA"; break; // Ъ
            case 0x9B: std::cout << "\xD0\xAB"; break; // Ы
            case 0x9C: std::cout << "\xD0\xAC"; break; // Ь
            case 0x9D: std::cout << "\xD0\xAD"; break; // Э
            case 0x9E: std::cout << "\xD0\xAE"; break; // Ю
            case 0x9F: std::cout << "\xD0\xAF"; break; // Я
            case 0xA0: std::cout << "\xD0\xB0"; break; // а
            case 0xA1: std::cout << "\xD0\xB1"; break; // б
            case 0xA2: std::cout << "\xD0\xB2"; break; // в
            case 0xA3: std::cout << "\xD0\xB3"; break; // г
            case 0xA4: std::cout << "\xD0\xB4"; break; // д
            case 0xA5: std::cout << "\xD0\xB5"; break; // е
            case 0xA6: std::cout << "\xD0\xB6"; break; // ж
            case 0xA7: std::cout << "\xD0\xB7"; break; // з
            case 0xA8: std::cout << "\xD0\xB8"; break; // и
            case 0xA9: std::cout << "\xD0\xB9"; break; // й
            case 0xAA: std::cout << "\xD0\xBA"; break; // к
            case 0xAB: std::cout << "\xD0\xBB"; break; // л
            case 0xAC: std::cout << "\xD0\xBC"; break; // м
            case 0xAD: std::cout << "\xD0\xBD"; break; // н
            case 0xAE: std::cout << "\xD0\xBE"; break; // о
            case 0xAF: std::cout << "\xD0\xBF"; break; // п
            case 0xE0: std::cout << "\xD1\x80"; break; // р
            case 0xE1: std::cout << "\xD1\x81"; break; // с
            case 0xE2: std::cout << "\xD1\x82"; break; // т
            case 0xE3: std::cout << "\xD1\x83"; break; // у
            case 0xE4: std::cout << "\xD1\x84"; break; // ф
            case 0xE5: std::cout << "\xD1\x85"; break; // х
            case 0xE6: std::cout << "\xD1\x86"; break; // ц
            case 0xE7: std::cout << "\xD1\x87"; break; // ч
            case 0xE8: std::cout << "\xD1\x88"; break; // ш
            case 0xE9: std::cout << "\xD1\x89"; break; // щ
            case 0xEA: std::cout << "\xD1\x8A"; break; // ъ
            case 0xEB: std::cout << "\xD1\x8B"; break; // ы
            case 0xEC: std::cout << "\xD1\x8C"; break; // ь
            case 0xED: std::cout << "\xD1\x8D"; break; // э
            case 0xEE: std::cout << "\xD1\x8E"; break; // ю
            case 0xEF: std::cout << "\xD1\x8F"; break; // я
            case 0xF0: std::cout << "\xD0\x81"; break; // Ё
            case 0xF1: std::cout << "\xD1\x91"; break; // ё
        }
    }
}

void print_list(ListNode* head){
    int record_counter = 0;
    ListNode* temp = head;
    bool exit = false;

    while(temp != nullptr){
        transcodingCP866_for_UTF8(temp->data.name, 32);
        std::cout << "\n";
        transcodingCP866_for_UTF8(temp->data.street, 18);
        std::cout << "\n";
        std::cout << temp->data.number_house << "\n";
        std::cout << temp->data.apartment << "\n";
        transcodingCP866_for_UTF8(temp->data.date_of_settlement, 10);
        std::cout << "\n\n";

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

