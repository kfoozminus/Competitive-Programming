/*
ID: apoorvk1
PROG: numtri
LANG: C++
*/
#include <fstream>
#define ABS(x)((x) < 0 ? -(x):(x))
#define SUM(x)((int)((1+x)/2.0*(1+ABS(1-x))))
#define GREATER(x,y)((x) >= (y) ? (x):(y))
using namespace std;

ofstream fout("numtri.out");
short unsigned int R;
unsigned int tri[500500];
void rowOp(int rowId) {
    if(rowId == 1) return;
    unsigned int init = SUM((rowId-1));
    for(int a = init; a < init + rowId - 1; a++)
        tri[a + 1 - rowId] += GREATER(tri[a], tri[a + 1]);
    rowOp(rowId-1);
}
int main(int argc, char** argv) {
    ifstream fin("numtri.in");
    fin >> R;
    for(int a = 0; a < SUM(R); a++)
        fin >> tri[a];
    fin.close();
    rowOp(R);
    fout << tri[0] << "\n";
    fout.close();
    return 0;
}