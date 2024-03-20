// Copyright 2024 Lee V.

#include <iostream>
#include <utility>

#include "Animal.h"

Animal::Animal(float mass, Sex sex, const char* color, int age)
    : m_mass(mass), m_sex(sex), m_age(age) {
    if (color == nullptr) {
        m_color = nullptr;
        return;
    }

    int size = strlen(color) + 1;
    m_color = new char[size];

    for (int index = 0; index < size; ++index)
        m_color[index] = color[index];
}

Animal::Animal(const Animal& source)
    : m_mass(source.m_mass), m_sex(source.m_sex), m_age(source.m_age) {
    if (source.m_color == nullptr) {
        m_color = nullptr;
        return;
    }

    int size = strlen(source.m_color) + 1;
    m_color = new char[size];

    for (int index = 0; index < size; ++index)
        m_color[index] = source.m_color[index];
}

Animal::Animal(Animal&& source)
    : m_mass(source.m_mass), m_sex(source.m_sex), m_age(source.m_age) {
    m_color = source.m_color;
    source.m_color = nullptr;
}

Animal::~Animal() {
    delete[] m_color;
}

float Animal::GetMass() const {
    return m_mass;
}

const char* Animal::GetSex() const {
    switch (m_sex) {
        case Sex::MALE:   return "Male";
        case Sex::FEMALE: return "Female";
        default:          return "Unknown";
    }
}

char* Animal::GetColor() const {
    return m_color;
}

int Animal::GetAge() const {
    return m_age;
}

void Animal::SetMass(float mass) {
    m_mass = mass;
}

void Animal::SetSex(Sex sex) {
    m_sex = sex;
}

void Animal::SetColor(const char* color) {
    delete[] m_color;

    int new_size = strlen(color) + 1;
    m_color = new char[new_size];

    for (int index = 0; index < new_size; ++index)
        m_color[index] = color[index];
}

void Animal::SetAge(int age) {
    m_age = age;
}

Dog::Dog(const char* name, Breed race, float mass, Sex sex,
    const char* color, int age) : Animal(mass, sex, color, age), m_race(race) {
    if (name == nullptr) {
        m_name = nullptr;
        return;
    }

    int size = strlen(name) + 1;
    m_name = new char[size];

    for (int index = 0; index < size; ++index)
        m_name[index] = name[index];
}

Dog::Dog(const Dog& source) : Animal(source), m_race(source.m_race) {
    if (source.m_name == nullptr) {
        m_name = nullptr;
        return;
    }

    int size = strlen(source.m_name) + 1;
    m_name = new char[size];

    for (int index = 0; index < size; ++index)
        m_name[index] = source.m_name[index];
}

Dog::Dog(Dog&& source) : Animal(std::move(source)), m_race(source.m_race) {
    m_name = source.m_name;
    source.m_name = nullptr;
}

Dog::~Dog() {
    delete[] m_name;
}

Dog& Dog::operator=(const Dog& source) {
    if (this == &source)
        return *this;

    delete[] m_color;
    delete[] m_name;

    m_mass = source.m_mass;
    m_sex = source.m_sex;
    m_age = source.m_age;
    m_race = source.m_race;

    if (source.m_name == nullptr) {
        m_name = nullptr;
    } else {
        int size = strlen(source.m_name) + 1;
        m_name = new char[size];

        for (int index = 0; index < size; ++index)
            m_name[index] = source.m_name[index];
    }

    if (source.m_color == nullptr) {
        m_color = nullptr;
    } else {
        int size = strlen(source.m_color) + 1;
        m_color = new char[size];

        for (int index = 0; index < size; ++index)
            m_color[index] = source.m_color[index];
    }

    return *this;
}

Dog& Dog::operator=(Dog&& source) {
    if (this == &source)
        return *this;

    *this = source;
    source.m_color = nullptr;
    source.m_name = nullptr;

    return *this;
}

char* Dog::GetName() const {
    return m_name;
}

const char* Dog::GetRace() const {
    switch (m_race) {
        case Breed::BULLTERRIER: return "Bullterrier";
        case Breed::CHIHUAHUA:   return "Chihuahua";
        case Breed::DACHSHUND:   return "Dachshund";
        case Breed::DALMATIAN:   return "Dalmatian";
        case Breed::DOBERMAN:    return "Doberman";
        case Breed::HUSKY:       return "Husky";
        case Breed::PEKINGESE:   return "Pekingese";
        case Breed::POODLE:      return "Poodle";
        case Breed::PUG:         return "Pug";
        case Breed::ROTTWEILER:  return "Rottweiler";
        case Breed::SHEPHERD:    return "Shepherd";
        default:                 return "Unknown";
    }
}

void Dog::SetName(const char* name) {
    delete[] m_name;

    int new_size = strlen(name) + 1;
    m_name = new char[new_size];

    for (int index = 0; index < new_size; ++index)
        m_name[index] = name[index];
}

void Dog::SetRace(Breed race) {
    m_race = race;
}

void Dog::WhatDoesSay() {
    std::cout << "Woof!";
}

std::ostream& operator<<(std::ostream& out, const Dog& dog) {
    out << "DOG NAME: [";

    if (dog.m_name == nullptr)
        out << "Nameless]\n";
    else
        out << dog.m_name << "]\n";

    out << "DOG RACE: [" << dog.GetRace() << "]\n";
    out << "DOG AGE: [" << dog.m_age << "]\n";
    out << "DOG GENDER: [" << dog.GetSex() << "]\n";
    out << "DOG COLOR: [";

    if (dog.m_color == nullptr)
        out << "Unknown]\n";
    else
        out << dog.m_color << "]\n";

    out << "DOG MASS: [" << dog.m_mass << "]";

    return out;
}

Fox::Fox(const char* name, TypeFox type, float mass, Sex sex,
    const char* color, int age) : Animal(mass, sex, color, age), m_type(type),
    m_numberRabbitsEaten(0) {
    if (name == nullptr) {
        m_name = nullptr;
        return;
    }

    int size = strlen(name) + 1;
    m_name = new char[size];

    for (int index = 0; index < size; ++index)
        m_name[index] = name[index];
}

Fox::Fox(const Fox& source): Animal(source),
    m_type(source.m_type), m_numberRabbitsEaten(source.m_numberRabbitsEaten) {
    if (source.m_name == nullptr) {
        m_name = nullptr;
        return;
    }

    int size = strlen(source.m_name) + 1;
    m_name = new char[size];

    for (int index = 0; index < size; ++index)
        m_name[index] = source.m_name[index];
}

Fox::Fox(Fox&& source) : Animal(std::move(source)),
    m_type(source.m_type), m_numberRabbitsEaten(source.m_numberRabbitsEaten) {
    m_name = source.m_name;
    source.m_name = nullptr;
}

Fox::~Fox() {
    delete[] m_name;
}

Fox& Fox::operator=(const Fox& source) {
    if (this == &source)
        return *this;

    delete[] m_color;
    delete[] m_name;

    m_mass = source.m_mass;
    m_sex = source.m_sex;
    m_age = source.m_age;
    m_type = source.m_type;
    m_numberRabbitsEaten = source.m_numberRabbitsEaten;

    if (source.m_name == nullptr) {
        m_name = nullptr;
    } else {
        int size = strlen(source.m_name) + 1;
        m_name = new char[size];

        for (int index = 0; index < size; ++index)
            m_name[index] = source.m_name[index];
    }

    if (source.m_color == nullptr) {
        m_color = nullptr;
    } else {
        int size = strlen(source.m_color) + 1;
        m_color = new char[size];

        for (int index = 0; index < size; ++index)
            m_color[index] = source.m_color[index];
    }

    return *this;
}

Fox& Fox::operator=(Fox&& source) {
    if (this == &source)
        return *this;

    *this = source;
    source.m_color = nullptr;
    source.m_name = nullptr;

    return *this;
}

char* Fox::GetName() const {
    return m_name;
}

const char* Fox::GetType() const {
    switch (m_type) {
    case TypeFox::ARCTIC:       return "Arctic";
    case TypeFox::BENGAL:       return "Bengal";
    case TypeFox::CAPE:         return "Cape";
    case TypeFox::CORSAC:       return "Corsac";
    case TypeFox::CULPEO:       return "Culpeo";
    case TypeFox::GRAY:         return "Gray";
    case TypeFox::RED:          return "Red";
    case TypeFox::SECHURAN:     return "Sechuran";
    case TypeFox::TIBETAN_SAND: return "Tibetan sand";
    default:                    return "Unknown";
    }
}

int Fox::GetNumberRabbitsEaten() const {
    return m_numberRabbitsEaten;
}

void Fox::SetName(const char* name) {
    delete[] m_name;

    int new_size = strlen(name) + 1;
    m_name = new char[new_size];

    for (int index = 0; index < new_size; ++index)
        m_name[index] = name[index];
}

void Fox::SetType(TypeFox type) {
    m_type = type;
}

void Fox::Eat() {
    ++m_numberRabbitsEaten;
}

void Fox::WhatDoesSay() {
    switch (m_type) {
        case TypeFox::ARCTIC:
            std::cout << "Ring-ding-ding-ding-dingeringeding!"; break;
        case TypeFox::BENGAL:
            std::cout << "Gering-ding-ding-ding-dingeringeding!"; break;
        case TypeFox::CAPE:
            std::cout << "Wa-pa-pa-pa-pa-pa-pow!"; break;
        case TypeFox::CORSAC:
            std::cout << "Hatee-hatee-hatee-ho!"; break;
        case TypeFox::CULPEO:
            std::cout << "Joff-tchoff-tchoffo-tchoffo-tchoff!"; break;
        case TypeFox::GRAY:
            std::cout << "Jacha-chacha-chacha-chow!"; break;
        case TypeFox::RED:
            std::cout << "Chacha-chacha-chacha-chow!"; break;
        case TypeFox::SECHURAN:
            std::cout << "Fraka-kaka-kaka-kaka-kow!"; break;
        case TypeFox::TIBETAN_SAND:
            std::cout << "A-hee-ahee ha-hee!"; break;
        default:
            std::cout << "A-oo-oo-oo-ooo!"; break;
    }
}

std::ostream& operator<<(std::ostream& out, const Fox& fox) {
    out << "FOX NAME: [";

    if (fox.m_name == nullptr)
        out << "Nameless]\n";
    else
        out << fox.m_name << "]\n";

    out << "FOX TYPE: [" << fox.GetType() << "]\n";
    out << "FOX AGE: [" << fox.m_age << "]\n";
    out << "FOX GENDER: [" << fox.GetSex() << "]\n";
    out << "FOX COLOR: [";

    if (fox.m_color == nullptr)
        out << "Unknown]\n";
    else
        out << fox.m_color << "]\n";

    out << "FOX MASS: [" << fox.m_mass << "]\n";
    out << "NUMBER OF EATEN RABBITS BY THIS FOX: ["
        << fox.m_numberRabbitsEaten << "]";

    return out;
}
