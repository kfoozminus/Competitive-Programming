/*
ID: apoorvk1
PROG: crypt1
LANG: C++
*/
#include <fstream>
using namespace std;

unsigned short int N;

int pow(int a, int n) {
    if(n == 0) return 1;
    if(n == 1) return a;
    int t = pow(a, n/2);
    return t * t * pow(a, n%2);
}

int getDigitFromNum(int num, int digit){
    num /= pow(10, digit);
    return num % 10;
}

bool is(int input, unsigned short int digits[], int reqLen) {
    bool inner;
    int n = input, length = 0;
    while(n > 0) {
        length++;
        n /= 10;
    }
    if(length != reqLen) return false;
    int inputVal[length];
    for(int a = 0; a < length; a++) inputVal[a] = getDigitFromNum(input, a);
    for(int a = 0; a < length; a++) {
        inner = false;
        for(int b = 0; b < N; b++) if(inputVal[a] == digits[b]) {
            inner = true;
            break;
        }
        if(!inner) return false;
    }
    return true;
}

bool gen(int a, int b, int c, int d, int e, unsigned short int digits[]) {
    int abc = digits[a]*100 + digits[b]*10 + digits[c], de = digits[d]*10 + digits[e], abcd = digits[d]*abc, abce = digits[e]*abc, abcde = abc*de;
    return is(abce, digits, 3) && is(abcd, digits, 3) && is(abcde, digits, 4);
}

int main() {
    unsigned short int total = 0;
    ifstream fin("crypt1.in");
    fin >> N;
    unsigned short int digits[N];
    for(int a = 0; a < N; a++) fin >> digits[a];
    fin.close();
    for(int a = 0; a < N; a++)
        for(int b = 0; b < N; b++)
            for(int c = 0; c < N; c++)
                for(int d = 0; d < N; d++)
                    for(int e = 0; e < N; e++)
                        if(gen(a, b, c, d, e, digits)) total++;
    ofstream fout("crypt1.out");
    fout << total << endl;
    fout.close();
    return 0;
}