/*
ID: apoorvk1
PROG: skidesign
LANG: C++
*/
#include <fstream>
#include <climits>
using namespace std;

unsigned int square = 0;
int main(int argc, char** argv) {
    unsigned short int N;
    ifstream fin("skidesign.in");
    fin >> N;
    unsigned short int elevation[N];
    for(int a = 0; a < N; a++)
        fin >> elevation[a];
    fin.close();
    short unsigned int holder;
    for(int a = 0; a < N; a++) {
        for(int b = 1; b < N; b++) {
            if(elevation[b] < elevation[b-1]) {
                holder = elevation[b-1];
                elevation[b-1] = elevation[b];
                elevation[b] = holder;
            }
        }
    }
    unsigned int tempSum, square = 65535, change;
    for(int a = 0; a <= 83; a++) {
        tempSum = 0;
        for(int b = 0; b < N; b++) {
            change = 0;
            if(elevation[b] < a) change = a - elevation[b];
            else if(elevation[b] > a + 17) change = elevation[b] - a - 17;
            tempSum += change*change;
        }
        if(tempSum < square) square = tempSum;
    }
    ofstream fout("skidesign.out");
    fout << square << "\n";
    fout.close();
    return 0;
}