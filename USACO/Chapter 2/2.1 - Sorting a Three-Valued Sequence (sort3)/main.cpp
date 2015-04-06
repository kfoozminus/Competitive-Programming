/*
ID: apoorvk1
PROG: sort3
LANG: C++
*/
#include <fstream>
using namespace std;

unsigned short int N, counter = 0;
int main(int argc, char** argv) {
    ifstream fin("sort3.in");
    fin >> N;
    unsigned short int val[N], num[3];
    num[0] = num[1] = num[2] = 0;
    for(int a = 0; a < N; a++)
        fin >> val[a];
    fin.close();
    for(int a = 0; a < N; a++)
        num[val[a]-1]++;
    for(int a = 0; a < num[0]; a++) {
        if(val[a] == 1) continue;
        int b;
        if(val[a] == 2) {
            for(b = num[0]; b < N; b++)
                if(val[b] == 1) break;
        } else {
            for(b = N - 1; b >= num[0]; b--)
                if(val[b] == 1) break;
        }
        val[b] = val[a];
        val[a] = 1;
        counter++;
    }
    for(int a = num[0] + num[1]; a < N; a++)
        if(val[a] != 3) counter++;
    ofstream fout("sort3.out");
    fout << counter << "\n";
    fout.close();
    return 0;
}