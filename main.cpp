  // Copyright 2024 Lee V.

#include <iostream>
#include <string>
#include <vector>

#include "Animal.h"

constexpr int kBuffer = 256;

void print_separator() {
    std::cout << '\n';

    for (int counter = 0; counter < 10; ++counter)
        std::cout << "=====";

    std::cout << '\n';
}

char* getNameFromUser() {
    char* name = new char[kBuffer];
    std::cout << "Input name: ";
    std::cin >> name;

    return name;
}

char* getColorFromUser() {
    char* color = new char[kBuffer];
    std::cout << "Input color: ";
    std::cin >> color;

    return color;
}

int main() {
    print_separator();

    // инициализируем объект класса Dog по умолчанию
    Dog defaultDog;
    std::cout << "defaultDog\n" << defaultDog;
    print_separator();

    // конструктор инициализации
    Dog dog1("Antony", Breed::CHIHUAHUA, 2.3, Sex::MALE, "Desert", 1);
    std::cout << "dog1\n" << dog1;
    print_separator();

    // конструктор копирования
    Dog dog1_copy(dog1);
    std::cout << "dog1_copy\n" << dog1_copy;
    print_separator();

    // конструктор перемещения
    Dog dog1_move(std::move(dog1));
    std::cout << "dog1_move\n" << dog1_move;
    print_separator();

    // теперь поля m_color и m_name у перемещенного объекта
    // dog1 указывают на nullptr
    std::cout << "dog1 (after moving)\n" << dog1;
    print_separator();

    Dog dog2("George", Breed::DOBERMAN, 4.6, Sex::MALE, "Black", 7);

    // присваивание копированием
    Dog dog3;
    dog3 = dog2;
    std::cout << "dog3\n" << dog3;
    print_separator();

    // присваивание перемещением
    Dog dog4;
    dog4 = std::move(dog2);
    std::cout << "dog4\n" << dog4;
    print_separator();

    // теперь поля m_color и m_name у перемещенного объекта
    // dog2 указывают на nullptr
    std::cout << "dog2 (after moving)\n" << dog2;
    print_separator();

    // геттеры
    std::cout << "MASS: " << dog1_copy.GetMass() << '\n';
    std::cout << "SEX: " << dog1_copy.GetSex() << '\n';
    std::cout << "COLOR: " << dog1_copy.GetColor() << '\n';
    std::cout << "AGE: " << dog1_copy.GetAge() << '\n';
    std::cout << "NAME: " << dog1_copy.GetName() << '\n';
    std::cout << "RACE: " << dog1_copy.GetRace();
    print_separator();

    // сеттеры
    dog1_copy.SetMass(7.5);
    dog1_copy.SetSex(Sex::FEMALE);
    dog1_copy.SetColor("Light gray");
    dog1_copy.SetAge(4);
    dog1_copy.SetName("Morgana");
    dog1_copy.SetRace(Breed::HUSKY);
    std::cout << "dog1_copy (after using setters)\n" << dog1_copy;
    print_separator();

    dog1_copy.WhatDoesSay();  // перегрузка виртуальной функции
    print_separator();

    // инициализируем объект класса Fox по умолчанию
    Fox defaultFox;
    std::cout << "defaultFox\n" << defaultFox;
    print_separator();

    // конструктор инициализации
    Fox fox1("Pushinka", TypeFox::ARCTIC, 3, Sex::FEMALE, "White", 4);
    std::cout << "fox1\n" << fox1;
    print_separator();

    // конструктор копирования
    Fox fox1_copy(fox1);
    std::cout << "fox1_copy\n" << fox1_copy;
    print_separator();

    // конструктор перемещения
    Fox fox1_move(std::move(fox1));
    std::cout << "fox1_move\n" << fox1_move;
    print_separator();

    // теперь поля m_color и m_name у перемещенного объекта
    // dog1 указывают на nullptr
    std::cout << "fox1 (after moving)\n" << fox1;
    print_separator();

    Fox fox2("Karl", TypeFox::TIBETAN_SAND, 4, Sex::MALE, "Desert", 2);

    // присваивание копированием
    Fox fox3;
    fox3 = fox2;
    std::cout << "fox3\n" << fox3;
    print_separator();

    // присваивание перемещением
    Fox fox4;
    fox4 = std::move(fox2);
    std::cout << "fox4\n" << fox4;
    print_separator();

    // теперь поля m_color и m_name у перемещенного объекта
    // dog2 указывают на nullptr
    std::cout << "fox2 (after moving)\n" << fox2;
    print_separator();

    // геттеры
    std::cout << "MASS: " << fox1_copy.GetMass() << '\n';
    std::cout << "SEX: " << fox1_copy.GetSex() << '\n';
    std::cout << "COLOR: " << fox1_copy.GetColor() << '\n';
    std::cout << "AGE: " << fox1_copy.GetAge() << '\n';
    std::cout << "NAME: " << fox1_copy.GetName() << '\n';
    std::cout << "FOX TYPE: " << fox1_copy.GetType() << '\n';
    std::cout << "NUMBER OF EATEN RABBITS: "
        << fox1_copy.GetNumberRabbitsEaten();
    print_separator();

    // сеттеры
    fox1_copy.SetMass(3.378);
    fox1_copy.SetSex(Sex::MALE);
    fox1_copy.SetColor("Dark orange");
    fox1_copy.SetAge(7);
    fox1_copy.SetName("Rabbit eater");
    fox1_copy.SetType(TypeFox::CULPEO);
    std::cout << "fox1_copy (after setters)\n" << fox1_copy;
    print_separator();

    std::vector<Fox> foxes;  // вектор лис всевозможных пород
    for (int counter = 0; counter < 10; ++counter)
        foxes.push_back(Fox());

    foxes[1].SetType(TypeFox::ARCTIC);
    foxes[2].SetType(TypeFox::BENGAL);
    foxes[3].SetType(TypeFox::CAPE);
    foxes[4].SetType(TypeFox::CORSAC);
    foxes[5].SetType(TypeFox::CULPEO);
    foxes[6].SetType(TypeFox::GRAY);
    foxes[7].SetType(TypeFox::RED);
    foxes[8].SetType(TypeFox::SECHURAN);
    foxes[9].SetType(TypeFox::TIBETAN_SAND);

    for (int index = 0; index < 10; ++index) {
        // перегрузка виртуальной функции
        foxes[index].WhatDoesSay();

        if (index != 9)
            std::cout << '\n';
    }
    print_separator();

    // метод Eat
    fox1_copy.Eat();
    fox1_copy.Eat();
    fox1_copy.Eat();

    // кол-во съеденных кроликов увеличилось на 3
    std::cout << "NUMBER OF EATEN RABBITS: "
        << fox1_copy.GetNumberRabbitsEaten();
    print_separator();

    // пользовательский ввод
    std::cout << "Input data for Fox object.\n";
    char* name = getNameFromUser();
    char* color = getColorFromUser();
    Fox userFox(name, TypeFox::SECHURAN, 3.66, Sex::MALE, color, 2);
    std::cout << "Your fox\n" << userFox;

    return 0;
}
