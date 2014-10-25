/*
ID: apoorvk1
PROG: milk2
LANG: C++
*/
#include <fstream>
using namespace std;

int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N, maxIng = 0, maxNon = 0, switchHold = 0, st = 0, en = 0;
    fin >> N;
    int time[2][N];
    for(int a = 0; a < N; a++){
        for(int b = 0; b < 2; b++){
            fin >> time[b][a];
        }
    }
    fin.close();
    for(int c = 0; c < N - 1; c++){
        for(int d = 0; d < N - 1; d++){
            if(time[0][d] > time[0][d + 1]){
                switchHold = time[0][d];
                time[0][d] = time[0][d + 1];
                time[0][d + 1] = switchHold;
                switchHold = time[1][d];
                time[1][d] = time[1][d + 1];
                time[1][d + 1] = switchHold;
            }
        }
    }
    st = time[0][0];
    en = time[1][0];
    maxIng = en - st;
    for(int e = 1; e < N; e++){
        if(time[0][e] <= en && time[1][e] >= en){
            en = time[1][e];
            if (en - st > maxIng){
                maxIng = en - st;
            }
        }
        if(time[0][e] > en){
            if (en - st > maxIng){
                maxIng = en - st;
            }
            st = time[0][e];
            en = time[1][e];
        }
    }
    for(int g = 1; g < N; g++){
        if(time[0][g] <= time[1][0]){
            if(time[1][g] > time[1][0]){
                time[1][0] = time[1][g];
            }
        } else {
            if(time[0][g] - time[1][0] > maxNon){
                maxNon = time[0][g] - time[1][0];
            }
            time[0][0] = time[0][g];
            time[1][0] = time[1][g];
        }
    }
    fout << maxIng << " " << maxNon << endl;
    fout.close();
    return 0;
}
