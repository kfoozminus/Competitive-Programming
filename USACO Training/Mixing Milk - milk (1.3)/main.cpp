/*
ID: apoorvk1
PROG: milk
LANG: C++
*/
#include <fstream>

using namespace std;
int main(){
    unsigned long int N, switchHold, money = 0;
    unsigned int M;
    ifstream fin("milk.in");
    fin >> N >> M;
    unsigned long int A[M];
    unsigned int P[M];
    for(int a = 0; a < M; a++){
        fin >> P[a] >> A[a];
    }
    fin.close();
    for(int b = 0; b < M; b++){
        for(int c = 0; c < M - 1; c++){
            if(P[c] > P[c+1]){
                switchHold = P[c+1];
                P[c+1] = P[c];
                P[c] = switchHold;
                switchHold = A[c+1];
                A[c+1] = A[c];
                A[c] = switchHold;
            }
        }
    }

    for(int d = 0; d < M; d++){
        if(A[d] == N){
            money += A[d]*P[d];
            N = 0;
        } else if(A[d] < N){
            money += A[d]*P[d];
            N -= A[d];
        } else {
            money += N*P[d];
            N = 0;
        }
        if(N == 0){
            break;
        }
    }
    ofstream fout("milk.out");
    fout << money << endl;
    fout.close();
    return 0;
}
