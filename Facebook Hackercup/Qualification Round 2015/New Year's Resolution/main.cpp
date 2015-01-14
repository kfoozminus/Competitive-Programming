#include <fstream>
using namespace std;

bool iS(int P[], int C[], int F[], int n, int sumP, int sumC, int sumF) {
    if (sumP == 0 && sumC == 0 && sumF == 0)
        return true;
    if (n == 0 && (sumP != 0 || sumC != 0 || sumF != 0))
        return false;
    if (P[n-1] > sumP || C[n-1] > sumC || F[n-1] > sumF)
        return iS(P, C, F, n-1, sumP, sumC, sumF);
    return iS(P, C, F, n-1, sumP, sumC, sumF) || iS(P, C, F, n-1, sumP-P[n-1], sumC-C[n-1], sumF-F[n-1]);
}
int main() {
    int T;
    ifstream fin("input.file");
    fin >> T;
    ofstream fout("output.file");
    for(int a = 1; a <= T; a++) {
        int caseN = a;
        int GP, GC, GF, N;
        fin >> GP >> GC >> GF >> N;
        int P[N], C[N], F[N];
        for(int a = 0; a < N; a++)
            fin >> P[a] >> C[a] >> F[a];
        fout << "Case #" << caseN;
        if(iS(P, C, F, N, GP, GC, GF))
            fout << ": yes\n";
        else fout << ": no\n";
    }
    fin.close();
    fout.close();
    return 0;
}