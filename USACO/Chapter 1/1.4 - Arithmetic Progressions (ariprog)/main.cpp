/*
ID: apoorvk1
PROG: ariprog
LANG: C++
*/
#include <fstream>
using namespace std;

int main() {
    unsigned int N, M, counter = 0;
    ifstream fin("ariprog.in");
    fin >> N >> M;
    fin.close();
    bool bisquares[125001];
    int results[10000][2];
    for(int a = 0; a <= M;a++)
        for(int b = a; b <= M;b++)
            bisquares[a*a+b*b] = true;
    for(int a = 0; a <= M*M; a++) {
        if(bisquares[a] == 0) continue;
        for(int b = (125000 - a)/(N - 1); b > 0; b--) {
            int c;
            for(c = 1; c < N; c++)
               if(bisquares[a + c * b] == 0)
                   break;
            if(c == N) {
                results[counter][0] = a;
                results[counter++][1] = b;
            }
        }
    }
    int key, b[2];
    for(int a = 1; a < counter; a++){
        key = a;
        while(key > 0 && results[key][1] < results[key-1][1]){
            b[0] = results[key][0];
            b[1] = results[key][1];
            results[key][0] = results[key-1][0];
            results[key][1] = results[key-1][1];
            results[key-1][0] = b[0];
            results[key-1][1] = b[1];
            key--;
	}
    }
    ofstream fout("ariprog.out");
    if(counter == 0) fout << "NONE\n";
    else for(int a = 0; a < counter; a++)
        fout << results[a][0] << " " << results[a][1] << "\n";
    fout.close();
    return 0;
}