/*
Google Code Jam: Qualification Round
Author: Apoorv Khandelwal(apoorvk)
Year: 2015
Problem: A.Standing Ovation
*/
#include <fstream>
using namespace std;

unsigned short int T;
int main(int argc, char** argv) {
    ifstream fin("ovation.in");
    fin >> T;
    ofstream fout("ovation.out");
    for(int cases = 1; cases <= T; cases++) {
        unsigned int max, total = 0, need = 0;
        string input;
        fin >> max;
        unsigned short int shyness[++max];
        fin >> input;
        for(int a = 0; a < max; a++)
            shyness[a] = input.at(a) - '0';
        for(int a = 0; a < max; a++) {
            if(total < a) {
                int add = a - total;
                need += add;
                total += add;
            }
            total += shyness[a];
        }
        fout << "Case #" << cases << ": " << need << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}