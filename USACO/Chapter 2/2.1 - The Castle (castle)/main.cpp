/*
ID: apoorvk1
PROG: castle
LANG: C++
*/
#include <fstream>
using namespace std;

short unsigned int squares[50][50], rooms[50][50], rCount[2501];
bool visited[50][50];
void search(int a, int b, int r){
    if(!visited[a][b]) {
        visited[a][b] = true;
        rooms[a][b] = r;
        rCount[r]++;
        if(squares[a][b] % 2 == 0)
            search(a, b-1, r);
        if((squares[a][b] / 2) % 2 == 0)
            search(a-1, b, r);
        if((squares[a][b] / 4) % 2 == 0)
            search(a, b+1, r);
        if(squares[a][b] < 8)
            search(a+1, b, r);
    }
}
int main(int argc, char** argv) {
    short unsigned int M, N;
    ifstream fin("castle.in");
    fin >> M >> N;
    for(int a = 0; a < N; a++)
        for(int b = 0; b < M; b++)
            fin >> squares[a][b];
    fin.close();
    unsigned short int r = 0;
    for(int a = 0; a < N; a++)
        for(int b = 0; b < M; b++)
            if(!visited[a][b]) search(a, b, ++r);
    short unsigned int maxR = 0;
    for(int a = 1; a <= r; a++)
        if(rCount[a] > maxR)
            maxR = rCount[a];
    short unsigned int maxBr = 0, sqA, sqB;
    char dir;
    for(int b = 0; b < M; b++) {
        for(int a = N-1; a >= 0; a--) {
            if(a > 0 && rooms[a][b] != rooms[a-1][b] && rCount[rooms[a][b]] + rCount[rooms[a-1][b]] > maxBr) {
                maxBr = rCount[rooms[a][b]] + rCount[rooms[a-1][b]];
                sqA = a + 1;
                sqB = b + 1;
                dir = 'N';
            }
            if(b < M-1 && rooms[a][b] != rooms[a][b+1] && rCount[rooms[a][b]] + rCount[rooms[a][b+1]] > maxBr) {
                maxBr = rCount[rooms[a][b]] + rCount[rooms[a][b+1]];
                sqA = a + 1;
                sqB = b + 1;
                dir = 'E';
            }
        }
    }
    ofstream fout("castle.out");
    fout << r << "\n";
    fout << maxR << "\n";
    fout << maxBr << "\n";
    fout << sqA << " " << sqB << " " << dir << "\n";
    fout.close();
    return 0;
}