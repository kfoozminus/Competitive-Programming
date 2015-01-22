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
    int min = 2001;
    for(int a = 0; a < N; a++) {
        int startPos = -1, pEndPos = -1;
        for(int b = 0; b < numCities[a] && startPos == -1; b++)
            if(city[a][b] == start)
                startPos = b;
        if(startPos == -1 || startPos == numCities[a] - 1) continue;
        for(int b = 0; b < numCities[a] && pEndPos == -1; b++)
            if(city[a][b] == end)
                pEndPos = b;
        if(pEndPos > startPos) {
            if(cost[a] < min) min = cost[a];
            continue;
        }
        for(int b = 0; b < N; b++) {
            if(b == a || cost[a] + cost[b] > min) continue;
            int endPos = -1;
            for(int c = 0; c < numCities[b]; c++)
                if(city[b][c] == end)
                    endPos = c;
            if(endPos == -1) continue;
            for(int c = startPos + 1; c < numCities[a]; c++) {
                int bPos = -1;
                for(int d = 0; d < numCities[b] && bPos == -1; d++)
                    if(city[a][c] == city[b][d])
                        bPos = d;
                if(bPos == -1) continue;
                if(bPos < endPos) min = cost[a] + cost[b];
            }
        }
    }
    ofstream fout("cowroute.out");
    fout << (min == 2001 ? -1 : min) << "\n";
    fout.close();
    return 0;
}