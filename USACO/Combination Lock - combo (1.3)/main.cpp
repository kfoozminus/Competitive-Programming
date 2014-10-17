/*
ID: apoorvk1
PROG: combo
LANG: C++
*/
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    unsigned short int N, fCombo[3], mCombo[3];
    ifstream fin("combo.in");
    fin >> N;
    for(char a = 1; a >= 0; a--)
        for(int b = 0; b < 3; b++)
            a ? fin >> fCombo[b] : fin >> mCombo[b];
    fin.close();
    unsigned short int count = 0, duplicate = 0;
    if(N >= 5) {
        string valid[2][125];
        unsigned short int cycle[N+4];
        cycle[0] = N-1, cycle[1] = N, cycle[N+2] = 1, cycle[N+3] = 2;
        for(int a = 2; a < N+2; a++) {
            cycle[a] = a - 1;
        }
        ostringstream ss;
        for(int a = fCombo[0] - 1; a <= fCombo[0] + 3; a++) {
            for(int b = fCombo[1] - 1; b <= fCombo[1] + 3; b++) {
                for(int c = fCombo[2] - 1; c <= fCombo[2] + 3; c++) {
                    ss << cycle[a] << " " << cycle[b] << " " << cycle[c];
                    valid[0][count] = ss.str();
                    ss.str(string());
                    count++;
                }
            }
        }
        count = 0;
        for(int a = mCombo[0] - 1; a <= mCombo[0] + 3; a++) {
            for(int b = mCombo[1] - 1; b <= mCombo[1] + 3; b++) {
                for(int c = mCombo[2] - 1; c <= mCombo[2] + 3; c++) {
                    ss << cycle[a] << " " << cycle[b] << " " << cycle[c];
                    valid[1][count] = ss.str();
                    ss.str(string());
                    count++;
                }
            }
        }
        for(int a = 0; a < 125; a++) {
            for(int b = 0; b < 125; b++) {
                if(valid[0][a] == valid[1][b]) {
                    duplicate++;
                    break;
                }
            }
        }
    }
    ofstream fout("combo.out");
    if(N >= 5) fout << 250 - duplicate << endl;
    else fout << N*N*N << endl;
    fout.close();
    return 0;
}