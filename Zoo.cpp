//
// Created by fred on 9/17/15.
//

#include "Zoo.h"
using namespace std;
Zoo::Zoo(){
    //Nothing to Initialize
}

void Zoo::ImportFromFile(string filename) {
    ifstream file(filename);
    if(!file.is_open()){
        cout << "Error Opening" << endl;
        return;
    }
    string data;
    while(getline(file, data)){
        if(IsValid(data)){
            ZooAnimals.push_back(StringToAnimal(data));
        }
    }
}

Animal Zoo::StringToAnimal(string data) {
    string species_temp;
    string color_temp;
    string legs_temp;
    int firstDelimiter = data.find('|');
    int secondDelimiter = data.rfind('|');

    species_temp = data.substr(0,firstDelimiter);
    color_temp = data.substr(firstDelimiter+1,secondDelimiter-firstDelimiter-1);
    legs_temp = data.substr(secondDelimiter+1);

    Animal Animal_temp(species_temp, color_temp, atoi(legs_temp.c_str()));
    return Animal_temp;
}

void Zoo::append(Animal new_animal) {
    ZooAnimals.push_back(new_animal);
}

void Zoo::PrintToFile(ofstream & out) {
    for(int i = 0; i < ZooAnimals.size(); i++){
        out << ZooAnimals[i];
    }
}

void Zoo::remove() {
    ZooAnimals.pop_back();
}

void Zoo::sort() {
    int min = 0;
    Animal temp;

    for(int i = 0; i < ZooAnimals.size()-1; i++) {
        bool swap = false;
        min = i;
        for(int j = i+1; j < ZooAnimals.size(); j++) {
            if(ZooAnimals[min] > ZooAnimals[j]) {
                min = j;
                swap = true;
            }
        }
        if(swap == true) {
            temp = ZooAnimals[i];
            ZooAnimals[i] = ZooAnimals[min];
            ZooAnimals[min] = temp;
        }
    }
}

void Zoo::SortAlpha(){
    int min = 0;
    Animal temp;

    for(int i = 0; i < ZooAnimals.size()-1; i++) {
        bool swap = false;
        min = i;
        for(int j = i+1; j < ZooAnimals.size(); j++) {
            if(ZooAnimals[min].GetSpecies().at(0) > ZooAnimals[j].GetSpecies().at(0)) {
                min = j;
                swap = true;
            }
        }
        if(swap == true) {
            temp = ZooAnimals[i];
            ZooAnimals[i] = ZooAnimals[min];
            ZooAnimals[min] = temp;
        }
    }
}

Animal Zoo::FindMedian() {
    sort();
    return ZooAnimals[ZooAnimals.size()/2];
}

void Zoo::LessThan4(ofstream& filename) {
    sort();
    for(int i = 0; i < ZooAnimals.size(); i++){
        if(ZooAnimals[i].GetLegs() >= 4) return;
        else filename << ZooAnimals[i];
    }
}

bool IsValid(string data){
    return (data.find('|') == string::npos)? false:true;
}
