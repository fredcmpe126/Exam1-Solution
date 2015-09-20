//
// Created by fred on 9/17/15.
//

#include "Animal.h"
using namespace std;
Animal::Animal(){
    species = "None";
    color = "None";
    numberOfLegs = 0;
}

Animal::Animal(string sp,string co,int nl){
    species = sp;
    color = co;
    numberOfLegs = nl;
}

string Animal::GetSpecies() {
    return species;
}

string Animal::GetColor() {
    return color;
}

int Animal::GetLegs() {
    return numberOfLegs;
}

void Animal::SetSpecies(string s) {
    species = s;
}

void Animal::SetColor(string c) {
    color = c;
}

void Animal::SetLegs(int nl) {
    numberOfLegs = nl;
}

ostream& operator <<(ostream& out, Animal a){
    out << "Species:" << a.species;
    out << " Color:" << a.color;
    out << " Legs:" << a.numberOfLegs << endl;
    return out;
}

bool operator < (Animal a1, Animal a2){
    return a1.numberOfLegs < a2.numberOfLegs ? true : false;
}

bool operator <= (Animal a1, Animal a2){
    return a1.numberOfLegs <= a2.numberOfLegs ? true : false;
}

bool operator > (Animal a1, Animal a2){
    return a1.numberOfLegs > a2.numberOfLegs ? true : false;
}

bool operator >= (Animal a1, Animal a2){
    return a1.numberOfLegs >= a2.numberOfLegs ? true : false;
}