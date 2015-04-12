/*
Google Code Jam: Qualification Round
Author: Apoorv Khandelwal(apoorvk)
Year: 2015
Problem: D.Ominous Omino
*/
#include <fstream>
using namespace std;

ifstream fin("D-large.in");
ofstream fout("omino.out");
unsigned short int T;
bool check(int a, int b, int c) {
    if (b > c) { int temp = c; c = b; b = temp; }
    if(b * c % a != 0) return false;
    if(a < 3) return true;
    bool rVal = false;
    rVal |= (a == 3) && (b == 2) && (c == 3);
    rVal |= (a == 3) && (b == 3) && (c == 3);
    rVal |= (a == 3) && (b == 3) && (c == 4);
    rVal |= (a == 4) && (b == 3) && (c == 4);
    rVal |= (a == 4) && (b == 4) && (c == 4);
    return rVal;
}
int main(int argc, char** argv) {
    fin >> T;
    for(int cases = 1; cases <= T; cases++) {
        unsigned short int X, R, C;
        fin >> X >> R >> C;
        fout << "Case #" << cases << ": ";
        if(check(X, R, C)) fout << "GABRIEL\n";
        else fout << "RICHARD\n";
    }
    fin.close();
    fout.close();
    return 0;
}