/*
ID: apoorvk1
PROG: barn1
LANG: C++
*/
#include <fstream>
using namespace std;

int main(){
    unsigned int M, S, C;
    ifstream fin("barn1.in");
    fin >> M >> S >> C;
    unsigned int OccS[C];
    for(int a = 0; a < C; a++){
        fin >> OccS[a];
    }
    fin.close();
    unsigned int buffer[M - 1], blocked, temp;
    for(int a = 0; a < M - 1; a++) {
        buffer[a] = 0;
    }
    for(int a = 0; a < C; a++){
        for(int b = 0; b < C - 1; b++){
            if(OccS[b] > OccS[b+1]) {
                temp = OccS[b];
                OccS[b] = OccS[b+1];
                OccS[b+1] = temp;
            }
        }
    }
    blocked = (OccS[C-1] - OccS[0]) + 1;
    for(int a = 0; a < C - 1; a++) {
        temp = OccS[a+1] - OccS[a] - 1;
        for(int b = 0; b < M - 1; b++){
            if(temp >= buffer[b]) {
                for(int c = M - 2; c > b; c--) {
                    buffer[c] = buffer[c-1];
                }
                buffer[b] = temp;
                break;
            }
        }
    }
    for(int a = 0; a < M - 1; a++){
        blocked -= buffer[a];
    }
    ofstream fout("barn1.out");
    fout << blocked << endl;
    fout.close();
    return 0;
}
