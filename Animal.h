// Copyright 2024 Lee V.

#ifndef INCLUDE_ANIMAL_H
#define INCLUDE_ANIMAL_H

enum class Sex {
    UNITIALIZED,
    MALE,
    FEMALE
};

class Animal {
 protected:
    float m_mass;
    Sex m_sex;
    char* m_color;
    int m_age;

    explicit Animal(float mass = 0.0, Sex sex = Sex::UNITIALIZED,
        const char* color = nullptr, int age = 0);
    Animal(const Animal& source);
    Animal(Animal&& source);

    virtual ~Animal();

 public:
    float GetMass() const;
    const char* GetSex() const;
    char* GetColor() const;
    int GetAge() const;

    void SetMass(float mass);
    void SetSex(Sex sex);
    void SetColor(const char* color);
    void SetAge(int age);

    virtual void WhatDoesSay() = 0;
};

enum class Breed {
    UNITIALIZED,
    BULLTERRIER,
    CHIHUAHUA,
    DACHSHUND,
    DALMATIAN,
    DOBERMAN,
    HUSKY,
    PEKINGESE,
    POODLE,
    PUG,
    ROTTWEILER,
    SHEPHERD
};

class Dog final : public Animal {
 private:
    char* m_name;
    Breed m_race;

 public:
     explicit Dog(const char* name = nullptr, Breed race = Breed::UNITIALIZED,
         float mass = 0.0, Sex sex = Sex::UNITIALIZED,
         const char* color = nullptr, int age = 0);
     Dog(const Dog& source);
     Dog(Dog&& source);

     ~Dog() override;

     Dog& operator=(const Dog& source);
     Dog& operator=(Dog&& source);

     char* GetName() const;
     const char* GetRace() const;

     void SetName(const char* name);
     void SetRace(Breed race);

     void WhatDoesSay() override;

     friend std::ostream& operator<<(std::ostream& out, const Dog& dog);
};

enum class TypeFox {
    UNINITIALIZED,
    ARCTIC,
    BENGAL,
    CAPE,
    CORSAC,
    CULPEO,
    GRAY,
    RED,
    SECHURAN,
    TIBETAN_SAND
};

class Fox final : public Animal {
 private:
     char* m_name;
     TypeFox m_type;
     int m_numberRabbitsEaten;

 public:
     explicit Fox(const char* name = nullptr,
         TypeFox type = TypeFox::UNINITIALIZED, float mass = 0.0,
         Sex sex = Sex::UNITIALIZED, const char* color = nullptr, int age = 0);
     Fox(const Fox& source);
     Fox(Fox&& source);

     ~Fox() override;

     Fox& operator=(const Fox& source);
     Fox& operator=(Fox&& source);

     char* GetName() const;
     const char* GetType() const;
     int GetNumberRabbitsEaten() const;

     void SetName(const char* name);
     void SetType(TypeFox type);

     void Eat();
     void WhatDoesSay() override;

     friend std::ostream& operator<<(std::ostream& out, const Fox& fox);
};

#endif  // INCLUDE_ANIMAL_H
