//
// Created by fred on 9/17/15.
//

#ifndef LABEXAM1_ANIMAL_H
#define LABEXAM1_ANIMAL_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Animal {
public:
    //Constructors
    Animal();
    Animal(string,string,int);

    //Getter Functions
    string GetSpecies();
    string GetColor();
    int GetLegs();

    //Setter Functions
    void SetSpecies(string);
    void SetColor(string);
    void SetLegs(int);

    //Overloaded functions
    friend ostream& operator << (ostream&, Animal);
    friend Animal operator + (Animal, Animal);
    friend bool operator < (Animal, Animal);
    friend bool operator <= (Animal, Animal);
    friend bool operator > (Animal, Animal);
    friend bool operator >= (Animal, Animal);

private:
    string species;
    string color;
    int numberOfLegs;
};


#endif //LABEXAM1_ANIMAL_H
