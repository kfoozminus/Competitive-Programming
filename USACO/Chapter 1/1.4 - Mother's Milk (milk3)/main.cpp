/*
ID: apoorvk1
PROG: milk3
LANG: C++
*/
#include <fstream>
using namespace std;

struct Buckets { int fill[3]; };
unsigned short int limit[3];
bool amount[21];
bool searched[21][21][21];
Buckets pourTo(Buckets pouring, int from, int to) {
    unsigned short int ability = pouring.fill[from];
    unsigned short int capacity = limit[to] - pouring.fill[to];
    if(ability <= capacity) {
        pouring.fill[to] += ability;
        pouring.fill[from] = 0;
    } else {
        pouring.fill[to] = limit[to];
        pouring.fill[from] -= capacity;
    }
    return pouring;
}
void perBucket(struct Buckets current) {
    if(searched[current.fill[0]][current.fill[1]][current.fill[2]]) return;
    else searched[current.fill[0]][current.fill[1]][current.fill[2]] = true;
    if(current.fill[0] == 0)
        amount[current.fill[2]] = true;
    for(int d = 0; d < 3; d++) {
        if(current.fill[d] == 0)
            continue;
        else for(int e = 0; e < 3; e++) {
            if(d == e) continue;
            else if(current.fill[e] == limit[e])
                continue;
            perBucket(pourTo(current, d, e));
        }
    }
}
int main(int argc, char** argv) {
    ifstream fin("milk3.in");
    fin >> limit[0] >> limit[1] >> limit[2];
    fin.close();
    struct Buckets initial;
    initial.fill[0] = initial.fill[1] = 0;
    initial.fill[2] = limit[2];
    perBucket(initial);
    ofstream fout("milk3.out");
    string spacing = "";
    for(int a = 0; a <= limit[2]; a++) {
        if(amount[a]) {
            fout << spacing << a;
            spacing = " ";
        }
    }
    fout << "\n";
    fout.close();
    return 0;
}
