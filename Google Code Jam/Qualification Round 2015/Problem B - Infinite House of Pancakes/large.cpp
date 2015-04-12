/*
Google Code Jam: Qualification Round
Author: Apoorv Khandelwal(apoorvk)
Year: 2015
Problem: B.Infinite House of Pancakes
*/
#include <fstream>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) >= (y)) ? (x) : (y))
using namespace std;

int pancakes[1200];
ifstream fin("B-large.in");
ofstream fout("pancakes.out");
unsigned int T, cases, D, minutes, total;
int main() {
    fin >> T;
    for(cases = 1; cases <= T; cases++) {
        fin >> D;
        for(int a = 0; a < D; a++)
            fin >> pancakes[a];
        unsigned int tall = pancakes[0];
        for(int a = 1; a < D; a++)
            if(tall < pancakes[a]) tall = pancakes[a];
        for(int a = 1; a <= tall; a++) {
            total = a;
            for(int b = 0; b < D; b++)
                if(pancakes[b] > a)
                    if(pancakes[b] % a == 0) total += (pancakes[b]/a-1) ;
                    else total += (pancakes[b]/a) ;
            tall = MIN(tall, total);
        }
        fout << "Case #" << cases << ": " << tall << "\n";
    }
    fin.close();
    fout.close();
    return 0 ;
}
