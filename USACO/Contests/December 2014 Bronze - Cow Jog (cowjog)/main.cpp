#include <fstream>
using namespace std;

unsigned int N;
int main() {
    ifstream fin("cowjog.in");
    fin >> N;
    unsigned int pos[N], speed[N];
    for(int a = 0; a < N; a++)
        fin >> pos[a] >> speed[a];
    fin.close();
    unsigned int count = 0;
    for(int a = N-1; a >= 0; a--) {
        if(speed[a-1] > speed[a]) {
            speed[a-1] = speed[a];
            pos[a-1] = pos[a] - 1;
        } else count++;
    }
    ofstream fout("cowjog.out");
    fout << count << "\n";
    fout.close();
    return 0;
}