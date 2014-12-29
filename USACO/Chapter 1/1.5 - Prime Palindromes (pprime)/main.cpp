/*
ID: apoorvk
PROG: pprime
LANG: C++
*/
#include <fstream>
#include <math.h>
#include <sstream>
#include <string>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#define getDigit(num, x) SSTR(num).at(x-1) - 48
using namespace std;

ofstream fout("pprime.out");
unsigned int a, b;
bool isPrime(int a) {
    if(a <= 1) return false;
    if(a == 2) return true;
    if(a % 2 == 0) return false;
    for(int b = 3; b <= sqrt(a*1.0); b += 2)
        if(a % b == 0)
            return false;
    return true;
}
void recPal(int num, int length) {
    int curLen = 0;
    int num2 = num;
    while(num2 > 0) {
        num2 /= 10;
        curLen++;
    }
    bool odd = length % 2 == 1;
    if(num == 0)
        for(int c = 1; c < 10; c += 2)
            recPal(c, length);
    else if(curLen < length / 2 || curLen == length / 2 && odd)
        for(int c = 0; c < 10; c++)
            recPal(num*10+c, length);
    else if(curLen < length)
        recPal(num*10+getDigit(num, length - curLen), length);
    else if(num >= a && num <= b && isPrime(num))
        fout << num << "\n";
}
int main(int argc, char** argv) {
    ifstream fin("pprime.in");
    fin >> a >> b;
    fin.close();
    for(int c = SSTR(a).length(); c <= SSTR(b).length(); c++)
        recPal(0, c);
    fout.close();
    return 0;
}