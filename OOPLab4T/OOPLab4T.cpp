#include <iostream>
#include "Lab4Exmaple.h"

int main(){

    int ch;
    system("chcp 1251");

    std::cout << " Lab #4 \n";

    do {
        system("cls");
        std::cout << " Виберіть завдання: ";

        ch = std::cin.get();

        std::cin.get();


        switch (ch) {
        case '1': mainExample1(); break;
        case '2': mainExample2(); break;
        case '3': mainExample3(); break;
        case '4': return 0;
        }
        std::cout << " Press any key and enter\n";
        ch = std::cin.get();
    } while (ch != '4');
}