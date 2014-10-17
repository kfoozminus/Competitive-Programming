/*
ID: apoorvk1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    unsigned int cometbuf = 1, groupbuf = 1;
    for(unsigned int i = 0; i < comet.length(); i++){
        switch (comet[i]){
            case 'A': comet[i] = 1; break;
            case 'B': comet[i] = 2; break;
            case 'C': comet[i] = 3; break;
            case 'D': comet[i] = 4; break;
            case 'E': comet[i] = 5; break;
            case 'F': comet[i] = 6; break;
            case 'G': comet[i] = 7; break;
            case 'H': comet[i] = 8; break;
            case 'I': comet[i] = 9; break;
            case 'J': comet[i] = 10; break;
            case 'K': comet[i] = 11; break;
            case 'L': comet[i] = 12; break;
            case 'M': comet[i] = 13; break;
            case 'N': comet[i] = 14; break;
            case 'O': comet[i] = 15; break;
            case 'P': comet[i] = 16; break;
            case 'Q': comet[i] = 17; break;
            case 'R': comet[i] = 18; break;
            case 'S': comet[i] = 19; break;
            case 'T': comet[i] = 20; break;
            case 'U': comet[i] = 21; break;
            case 'V': comet[i] = 22; break;
            case 'W': comet[i] = 23; break;
            case 'X': comet[i] = 24; break;
            case 'Y': comet[i] = 25; break;
            case 'Z': comet[i] = 26; break;
        }
        cometbuf *= comet[i];
    }
    for(unsigned int i = 0; i < group.length(); i++){
        switch (group[i]){
            case 'A': group[i] = 1; break;
            case 'B': group[i] = 2; break;
            case 'C': group[i] = 3; break;
            case 'D': group[i] = 4; break;
            case 'E': group[i] = 5; break;
            case 'F': group[i] = 6; break;
            case 'G': group[i] = 7; break;
            case 'H': group[i] = 8; break;
            case 'I': group[i] = 9; break;
            case 'J': group[i] = 10; break;
            case 'K': group[i] = 11; break;
            case 'L': group[i] = 12; break;
            case 'M': group[i] = 13; break;
            case 'N': group[i] = 14; break;
            case 'O': group[i] = 15; break;
            case 'P': group[i] = 16; break;
            case 'Q': group[i] = 17; break;
            case 'R': group[i] = 18; break;
            case 'S': group[i] = 19; break;
            case 'T': group[i] = 20; break;
            case 'U': group[i] = 21; break;
            case 'V': group[i] = 22; break;
            case 'W': group[i] = 23; break;
            case 'X': group[i] = 24; break;
            case 'Y': group[i] = 25; break;
            case 'Z': group[i] = 26; break;
        }
        groupbuf *= group[i];
    }
    cometbuf %= 47;
    groupbuf %= 47;
    if(cometbuf == groupbuf){
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}