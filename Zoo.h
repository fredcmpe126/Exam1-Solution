//
// Created by fred on 9/17/15.
//

#ifndef LABEXAM1_ZOO_H
#define LABEXAM1_ZOO_H

#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include"Animal.h"

using namespace std;

bool IsValid(string data);
class Zoo {
public:
    Zoo();
    void ImportFromFile(string filename);
    void append(Animal);
    void remove();
    void sort();
    void PrintToFile(ofstream&);

    Animal FindMedian();
    void LessThan4(ofstream&);
    void SortAlpha();


private:
    Animal StringToAnimal(string);
    vector<Animal> ZooAnimals;
};


#endif //LABEXAM1_ZOO_H
