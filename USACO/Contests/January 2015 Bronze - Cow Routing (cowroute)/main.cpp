#include <fstream>
using namespace std;

unsigned int start, end, N;
int main(int argc, char** argv) {
    ifstream fin("cowroute.in");
    fin >> start >> end >> N;
    unsigned int cost[N], numCities[N], city[N][500];
    for(int a = 0; a < N; a++) {
        fin >> cost[a] >> numCities[a];
        for(int b = 0; b < numCities[a]; b++)
            fin >> city[a][b];
    }
    fin.close();
    int min = 1001;
    for(int a = 0; a < N; a++) {
        int startPos = -1, endPos = -1;
        for(int b = 0; b < numCities[a]; b++) {
            if(city[a][b] == start) startPos = b;
            else if(city[a][b] == end) endPos = b;
        }
        if(startPos == -1 || endPos == -1) continue;
        if(endPos < startPos) continue;
        if(cost[a] < min) min = cost[a];
    }
    ofstream fout("cowroute.out");
    fout << (min == 1001 ? -1 : min) << "\n";
    fout.close();
    return 0;
}