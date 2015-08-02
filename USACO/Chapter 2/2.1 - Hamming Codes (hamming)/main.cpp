/*
ID: apoorvk1
PROG: hamming
LANG: C++
*/
#include <fstream>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;

unsigned short int N, B, D;

bool ham(string x, string y) {
    int hammingSep = 0;
    for(int a = 0; a < 8; a++)
        if(x.at(a) != y.at(a))
            hammingSep++;
    return hammingSep >= D;
}

int main() {
    ifstream fin("hamming.in");
    fin >> N >> B >> D;
    fin.close();
    vector<bitset<8> > list;
    for(int a = 0; a < pow(2, B); a++) {
        if(list.size() >= N)
            break;
        bitset<8> value = a;
        bool hamming = true;
        for(int c = 0; c < list.size(); c++)
            if(!ham(value.to_string(), list.at(c).to_string()))
                hamming = false;
        if(hamming)
            list.push_back(value);
    }
    ofstream fout("hamming.out");
    for(int a = 0; a < list.size(); a++) {
        if(a % 10 != 0)
            fout << " ";
        fout << list.at(a).to_ulong();
        if(a == list.size() - 1 || (a+1) % 10 == 0)
            fout << "\n";
    }
    fout.close();
    return 0;
}