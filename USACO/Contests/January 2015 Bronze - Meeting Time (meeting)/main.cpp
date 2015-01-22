#include <fstream>
using namespace std;

unsigned short int N, M, small = 1601;
bool paths[17][17];
int bTime[17][17];
int eTime[17][17];
bool bWorks[1601], eWorks[1600];
void recurse(int col, int bT, int eT) {
    if(bT > small || eT > small) return;
    if(col == 1) {
        if(bT == eT && bT < small) small = bT;
        bWorks[bT] = true;
        eWorks[eT] = true;
        return;
    }
    for(int a = 1; a <= N; a++)
        if(a == col) continue;
        else if(paths[a][col])
            recurse(a, bT + bTime[a][col], eT + eTime[a][col]);
}
int main(int argc, char** argv) {
    ifstream fin("meeting.in");
    fin >> N >> M;
    unsigned short int temp[2];
    for(int a = 0; a < M; a++) {
        fin >> temp[0] >> temp[1];
        paths[temp[0]][temp[1]] = true;
        fin >> bTime[temp[0]][temp[1]] >> eTime[temp[0]][temp[1]];
    }
    fin.close();
    recurse(N, 0, 0);
    for(int a = 0; a < 1601 && small == 1601; a++)
        if(bWorks[a] && eWorks[a])
            small = a;
    ofstream fout("meeting.out");
    if(small == 1601) fout << "IMPOSSIBLE" << "\n";
    else fout << small << "\n";
    fout.close();
    return 0;
}