/*
ID: apoorvk1
PROG: sprime
LANG: C++
*/
#include <fstream>
#include <math.h>
using namespace std;

ofstream fout("sprime.out");
short unsigned int N;
bool isPrime(int a) {
    if(a <= 1) return false;
    if(a == 2) return true;
    if(a % 2 == 0) return false;
    for(int b = 3; b <= sqrt(a*1.0); b += 2)
        if(a % b == 0)
            return false;
    return true;
}
int length(int x) {
    unsigned int len = 0;
    while(x > 0) {
        x /= 10;
        len++;
    }
    return len;
}
void add(int num) {
    int len = length(num);
    if(!isPrime(num)) return;
    if(len == N)
        fout << num << "\n";
    else if(len < N)
        for(int a = 1; a < 10; a += 2)
            add(num*10+a);
}
int main(int argc, char** argv) {
    ifstream fin("sprime.in");
    fin >> N;
    fin.close();
    add(2);
    for(int a = 3; a < 9; a += 2)
        add(a);
    fout.close();
    return 0;
}