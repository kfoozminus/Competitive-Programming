/*
ID: apoorvk1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    short unsigned int np, numr, wallet[np], value;
    string names[np], giver, receiver;
    fin >> np;
    for(int i = 0; i < np; i++){
        fin >> names[i];
        wallet[i] = 0;
    }
    for(int i = 0; i < np; i++){
        fin >> giver >> value >> numr;
        for(int basew = 0; basew < numr; basew++){
            if(giver == names[basew]){
                wallet[basew] -= (value - (value % numr));
            }
        }
        for(int ep = 0; ep < numr; ep++){
            fin >> receiver;
            for(int walletr = 0; walletr < np; walletr++){
                if(receiver == names[walletr]){
                    wallet[walletr] += ((value - (value % numr))/numr);
                }
            }
        }
    }
    for(int i = 0; i < np; i++){
        fout << names[i] << " " << wallet[i] << endl;
    }
    return 0;
}
