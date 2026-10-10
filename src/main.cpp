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

    print_list(head);
    memory_clear(head);

    return 0;
}
