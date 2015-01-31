/*
ID: apoorvk1
PROG: frac1
LANG: C++
*/
#include <fstream>
using namespace std;

unsigned short int N;
int main(int argc, char** argv) {
    ifstream fin("frac1.in");
    fin >> N;
    fin.close();
    int size = (N + 1)*N/2 - N;
    unsigned int values[size][2];
    int counter = -1;
    for(int a = 2; a <= N; a++) {
        for(int b = 1; b < a; b++) {
            values[++counter][0] = b;
            values[counter][1] = a;
        }
    }
    counter = 0;
    for(int a = size - 1; a >= 0; a--) {
        bool works = true;
        for(int b = a - 1; b >= 0; b--) {
            if(1.0*values[a][0]/values[a][1] == 1.0*values[b][0]/values[b][1]) {
                works = false;
                break;
            }
        }
        if(!works) {
            values[a][0] = values[a][1] = 0;
            counter++;
        }
    }
    unsigned int rSize = size - counter, rVal[rSize][2];
    counter = -1;
    for(int a = 0; a < size; a++) {
        if(values[a][0] != 0 && values[a][1] != 0) {
            rVal[++counter][0] = values[a][0];
            rVal[counter][1] = values[a][1];
        }
    }
    if(N > 1) {
        unsigned int key[2], i;
        for(int j = 1; j <= rSize - 1; j++) {
            key[0] = rVal[j][0];
            key[1] = rVal[j][1];
            i = j - 1;
            while(i > 0 && 1.0*rVal[i][0]/rVal[i][1] > 1.0*key[0]/key[1]) {
                rVal[i+1][0] = rVal[i][0];
                rVal[i+1][1] = rVal[i][1];
                i--;
            }
            rVal[i+1][0] = key[0];
            rVal[i+1][1] = key[1];
        }
    }
    ofstream fout("frac1.out");
    fout << "0/1\n";
    if(N > 1) {
        for(int a = 1; a < rSize; a++) {
            fout << rVal[a][0] << "/" << rVal[a][1] << "\n";
            if(1.0*rVal[a][0]/rVal[a][1] < 0.5 && 1.0*rVal[a+1][0]/rVal[a+1][1] > 0.5)
                fout << "1/2\n";
        }
        if(N == 2) fout << "1/2\n";
    }
    fout << "1/1\n";
    fout.close();
    return 0;
}