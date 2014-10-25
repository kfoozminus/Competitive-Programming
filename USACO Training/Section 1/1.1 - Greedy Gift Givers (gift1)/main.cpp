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
    unsigned short int np, value, numpeople;
    string giver, reciever;
    fin >> np;
    int wallet[np];
    string names[np];
    for(int a = 0; a < np; a++){
        fin >> names[a];
        wallet[a] = 0;
    }
    for(int b = 0; b < np; b++){
        fin >> giver >> value >> numpeople;
        if(numpeople != 0){
            value = value -(value%numpeople);
            for(int c = 0; c < np; c++){
                if(giver == names[c]){
                    wallet[c] -= value;
                    for(int d = 0; d < numpeople; d++){
                        fin >> reciever;
                        for(int e = 0; e < np; e++){
                            if(reciever == names[e]){
                                wallet[e] += value/numpeople;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int out = 0; out < np; out++){
        fout << names[out] << " " << wallet[out] << endl;
    }
    return 0;
}
