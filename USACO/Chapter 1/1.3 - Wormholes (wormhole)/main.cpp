/*
ID: apoorvk1
PROG: wormhole
LANG: C++
*/
#include <fstream>
using namespace std;

unsigned short int N;
unsigned int x[13], y[13], onRight[13], joined[13];
bool isCycle() {
    for(int a = 1; a <= N; a++) {
        int b = a;
        for(int c = 0; c < N; c++)
            b = onRight[joined[b]];
        if(b != 0) return true;
    }
    return false;
}
int recurse() {
    unsigned short int a, total = 0;
    for(a = 1; a <= N; a++)
        if(joined[a] == 0)
            break;
    if(a > N)
        if(isCycle()) return 1;
        else return 0;
    for(int b = a + 1; b <= N; b++) {
        if(joined[b] == 0) {
            joined[a] = b;
            joined[b] = a;
            total += recurse();
            joined[a] = 0;
            joined[b] = 0;
        }
    }
    return total;
}
void right() {
    for(int a = 1; a <= N; a++)
        for(int b = 1; b <= N; b++)
            if(y[a] == y[b] && x[b] > x[a])
                if (onRight[a] == 0 || x[b] - x[a] < x[onRight[a]] - x[a])
                    onRight[a] = b;
}
int main(int argc, char** argv) {
    ifstream fin("wormhole.in");
    fin >> N;
    for(int a = 1; a <= N; a++)
        fin >> x[a] >> y[a];
    fin.close();
    right();
    int dPairs = recurse();
    ofstream fout("wormhole.out");
    fout << dPairs << "\n";
    fout.close();
    return 0;
}