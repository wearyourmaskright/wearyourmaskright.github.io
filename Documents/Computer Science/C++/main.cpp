//
//  main.cpp
//  Assignment 1_Rewrite
//
//  Created by Edward Man Fai Ho (mfh976) on 24/8/2018.
//  Copyright © 2018 Edward. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "header.h" //header file
#include "implementation.cpp" //implmentation file
using namespace std;
void detection(int i, int num, int curcode);
void summary(int z);
int main(int argc, const char * argv[]) {
    // number of car as indicated by user
    if (argc != 7) {
        cout << "You have not included enough files" << endl;
    }
    int index = stoi(argv[1]);
    string Vehiclefile = argv[2];
    string Mechanics = argv[3];
    string Problems = argv[4];
    string Fixes = argv[5];
    string Outputfile = argv[6];
    // call out function to import items into array
    for (int i = 1; i < 6; i++) { // read in each file as parsed by user and check file
        readFile(Vehiclefile, index);
        readFile(Mechanics, index);
        readFile(Problems, index);
        readFile(Fixes, index);
    }
    for (int vcode = 0; vcode < index; vcode++) {
        int mechnum = rand() % (mechanicNum[0]-1) + 1; // Randomize mechanics to current vehicle
        srand (static_cast<unsigned int>(time(NULL)));
        string tmp = Vehicle[vcode].prob;
        int code = atoi(tmp.c_str()); // current problem code
        detection(vcode, mechnum, code); // Detection & Repairment
    }
    summary(index, Outputfile); // Build summary table in text file

}
