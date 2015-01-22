#include <fstream>
#include <cmath>
using namespace std;

int distance(short int x1, short int y1, short int x2, short int y2) {
    return abs(x1-x2) + abs(y1-y2);
}
int main(int argc, char** argv) {
    unsigned int N;
    ifstream fin("marathon.in");
    fin >> N;
    short int x[N+1], y[N+1];
    for(int a = 1; a <= N; a++)
        fin >> x[a] >> y[a];
    fin.close();
    unsigned int min = 4294967295;
    for(int a = 2; a < N; a++) {
        unsigned int sum = 0;
        for(int b = 1; b < N; b++) {
            if(b == a) continue;
            if(b + 1 != a)
                sum += distance(x[b], y[b], x[b+1], y[b+1]);
            else
                sum += distance(x[b], y[b], x[b+2], y[b+2]);
        }
        if(sum < min) min = sum;
    }
    ofstream fout("marathon.out");
    fout << min << "\n";
    fout.close();
    return 0;
}