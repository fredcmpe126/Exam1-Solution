#include <iostream>
#include "Zoo.h"
using namespace std;

int main() {
    string inputFile = "/home/fred/CmpE126_TA/LabExam1/inputfile.txt";
    string outputFile = "/home/fred/CmpE126_TA/LabExam1/outputfile.txt";
    ofstream outputfile(outputFile);

    //Read from file + Print
    Zoo MyZoo;
    MyZoo.ImportFromFile(inputFile);
    MyZoo.PrintToFile(outputfile);
    outputfile << endl;

    //Append Animal + Print
    MyZoo.append(Animal("Tiger", "Orange", 4));
    MyZoo.PrintToFile(outputfile);
    outputfile << endl;

    //Remove Animal + Print
    MyZoo.remove();
    MyZoo.PrintToFile(outputfile);
    outputfile << endl;

    //Sort + Print
    MyZoo.sort();
    MyZoo.PrintToFile(outputfile);
    outputfile << endl;

    //Median
    outputfile << "Median:" << endl;
    outputfile << MyZoo.FindMedian();
    outputfile << endl;

    //Less than 4
    outputfile << "Less than 4 legs:" << endl;
    MyZoo.LessThan4(outputfile);
    outputfile << endl;

    //Sort Alpha
    MyZoo.SortAlpha();
    MyZoo.PrintToFile(outputfile);

    outputfile.close();
    return 0;
}
