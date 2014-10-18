/*
ID: apoorvk1
PROG: transform
LANG: C++
*/
#include <fstream>
using namespace std;
int main(){
    ifstream fin ("transform.in");
    int N;
    fin >> N;
    char oSquare[N][N], tSquare[N][N], trans[7][N][N];
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            fin >> oSquare[a][b];
        }
    }
    for(int c = 0; c < N; c++){
        for(int d = 0; d < N; d++){
            fin >> tSquare[c][d];
        }
    }
    fin.close();
    for(int g = 0; g < N; g++){
        for(int h = 0; h < N; h++){
            trans[0][g][h] = oSquare[g][N-1-h];
            trans[1][g][h] = oSquare[N-1-h][g];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            trans[2][i][j] = trans[1][N-1-j][i];
            trans[4][i][j] = trans[0][N-1-j][i];
        }
    }
    for(int k = 0; k < N; k++){
        for(int l = 0; l < N; l++){
            trans[3][k][l] = trans[2][N-1-l][k];
            trans[5][k][l] = trans[4][N-1-l][k];
        }
    }
    for(int m = 0; m < N; m++){
        for(int mn = 0; mn < N; mn++){
            trans[6][m][mn] = trans[5][N-1-mn][m];
        }
    }
    ofstream fout ("transform.out");
    int check[8] = {0};
    for(int o = 0; o < N; o++){
        for(int p = 0; p < N; p++){
            if(trans[1][o][p] != tSquare[o][p]){
                check[0]++;
            }
            if(trans[2][o][p] != tSquare[o][p]){
                check[1]++;
            }
            if(trans[3][o][p] != tSquare[o][p]){
                check[2]++;
            }
            if(trans[0][o][p] != tSquare[o][p]){
                check[3]++;
            }
            if(trans[4][o][p] != tSquare[o][p]){
                check[4]++;
            }
            if(trans[5][o][p] != tSquare[o][p]){
                check[5]++;
            }
            if(trans[6][o][p] != tSquare[o][p]){
                check[6]++;
            }
            if(oSquare[o][p] != tSquare[o][p]){
                check[7]++;
            }
        }
    }
    if(1 == 2){}
    else if(check[0] == 0){
        fout << 1 << endl;
        return 0;
    }
    else if(check[1] == 0){
        fout << 2 << endl;
        return 0;
    }
    else if(check[2] == 0){
        fout << 3 << endl;
        return 0;
    }
    else if(check[3] == 0){
        fout << 4 << endl;
        return 0;
    }
    else if(check[4] == 0 || check[5] == 0 || check[6] == 0){
        fout << 5 << endl;
    }
    else if(check[7] == 0){
        fout << 6 << endl;
        return 0;
    }
    else {
        fout << 7 << endl;
        return 0;
    }
    fout.close();
}
