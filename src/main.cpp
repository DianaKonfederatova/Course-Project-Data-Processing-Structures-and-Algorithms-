#include <iostream>
#include <cstdio>
#include "database.h"
#include "list.h"
#include "tree.h"

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
    std::cout << "Данные упорядочены.\n\n";

    std::cout << "=== ПРОСМОТР БАЗЫ ДАННЫХ ===\n";
    print_list(head);
    std::cout << "\n";

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

    int found_count_people = collect_to_queue(index_array, 4000, key_search_cp866, result_queue);

    std::cout << "\n--- Результаты поиска ---\n";
    std::cout << "Найдено записей: " << found_count_people << "\n\n";

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

    vertex* tree_root = nullptr;
    bool Rost = false;
    int tree_size = 0;
    current = result_queue.head;

    while(current != nullptr){
        Rost = false;
        add_AVL(current -> data, tree_root, Rost);
        tree_size++;
        current = current -> next;
    }

    std::cout << "\n========ВЫВОД АВЛ-ДЕРЕВА:========\n";
    print_tree(tree_root);
    std::cout << "\nРазмер дерева: " << tree_size << " узлов\n";

    short search_apartment;
    std::cout << "Введите номер квартиры для поиска в дереве: ";
    std::cin >> search_apartment;
    tree_search(tree_root, search_apartment);

    clear_tree(tree_root);
    memory_clear(head);
    delete[] index_array;

    return 0;
}
