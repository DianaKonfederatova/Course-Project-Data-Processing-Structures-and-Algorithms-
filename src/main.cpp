#include <iostream>
#include <cstdio>
#include "database.h"
#include "list.h"

int main() {
    
    FILE *file = fopen("../data/testBase4.dat", "rb");
    if(file == NULL){
        std::cout << "Ошибка чтения файла\n";
        return 1;
    }

    std::cout << "Файл открыт и готов к чтению\n" << "\n";
    
    ListNode* head = nullptr;
    addresses people;

    int count = 0;

    while (fread(&people, sizeof(addresses), 1, file) == 1) {
        addList(head, people);
        count++;

    }
    
    std::cout << "Файл успешно прочитан. В список добавлено " << count << " записей\n";
    std::cout << "\n";
    

    fclose(file);
    mergeSort(head, 4000);

    ListNode** index_array = new ListNode*[4000];
    ListNode* temp = head;
    for(int i = 0; i < 4000; i++){
        index_array[i] = temp;
        temp = temp -> next;
    }

    char key_search_utf8[100];
    std::cout << "Введите первые 3 буквы улицы для поиска: ";
    std::cin >> key_search_utf8;

    char key_search_cp866[4]; 
    utf8_to_cp866_prefix(key_search_utf8, key_search_cp866);

    Queue result_queue;
    queue_init(result_queue);

    collect_to_queue(index_array, 4000, key_search_cp866, result_queue);

    std::cout << "\n--- Результаты поиска ---\n";
    ListNode* current = result_queue.head;
    int found_count = 0;

    while(current != nullptr){
        found_count++;
        std::cout << found_count << ". ";
        transcodingCP866_for_UTF8(current->data.name, 32);
        std::cout << "\t";
        transcodingCP866_for_UTF8(current->data.street, 18);
        std::cout << "\t";
        std::cout << current->data.number_house << "\t";
        std::cout << current->data.apartment << "\t";
        transcodingCP866_for_UTF8(current->data.date_of_settlement, 10);
        std::cout << "\n";
        current = current->next;
    }
    
    if(found_count == 0) {
        std::cout << "Ничего не найдено.\n";
    }

    print_list(head);
    memory_clear(head);

    delete[] index_array;

    return 0;
}
