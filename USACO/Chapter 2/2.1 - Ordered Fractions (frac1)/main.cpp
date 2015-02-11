/*
ID: apoorvk1
PROG: frac1
LANG: C++
*/
#include <fstream>
#include <vector>
using namespace std;

struct fraction {
    int num;
    int denom;
    double val;
};
unsigned short int N;
int main(int argc, char** argv) {
    ifstream fin("frac1.in");
    fin >> N;
    fin.close();
    short unsigned int length = 0, counter = 0;
    for(int a = 2; a <= N + 1; a++)
        length += a;
    vector<fraction> v(length);
    for(int a = 1; a <= N; a++) {
        for(int b = 0; b <= a; b++) {
            v[counter].num = b;
            v[counter].denom = a;
            v[counter++].val = 1.0*b/a;
        }
    }
    for(int a = 0; a < v.size(); a++)
        for(int b = a + 1; b < v.size();)
            if(v[a].val == v[b].val)
                v.erase(v.begin() + b);
            else b++;
    for(int j = 1; j < v.size(); j++) {
        fraction key = v[j];
        int i = j - 1;
        while(i >= 0 && v[i].val > key.val) {
            v[i + 1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
    ofstream fout("frac1.out");
    for(int a = 0; a < v.size(); a++)
        fout << v[a].num << "/" << v[a].denom << "\n";
    fout.close();
    return 0;
}