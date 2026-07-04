#include <iostream>
#include <cstdio>
#include "database.h"

int main() {
    
    FILE *file = fopen("data/testBase4.dat", "rb");
    if(file == NULL){
        std::cout << "Ошибка чтения файла\n";
        return 1;
    }

    std::cout << "Файл открыт и готов к чтению\n" << "\n";
    
    struct addresses people;

    if (fread(&people, sizeof(struct addresses), 1, file) == 1) {
        std::cout << "ФИО гражданина: "<<people.name << "\n";
        std::cout << "Название улицы: "<<people.street << "\n";
        std::cout << "Номер дома: "<<people.number_house << "\n";
        std::cout << "Номер квартиры: "<<people.apartment << "\n";
        std::cout << "Дата поселения: "<<people.date_of_settlement << "\n";
   
    } else {
        std::cout << "Ошибка чтения файла или файл пуст\n";
    }

    fclose(file);
    return 0;
}
