/*
ID: apoorvk1
PROG: subset
LANG: C++
*/
#include <fstream>
using namespace std;

unsigned short int N, sum;
long long int number[820][40];

long long int ways(int a, int b) {
    if(a < 0 || b < 0)
        return 0;
    if(number[a][b] == -1) {
        if(a == 0 && b == 0)
            number[a][b] = 1;
	else number[a][b] = ways(a, b - 1) + ways(a - b, b - 1);
    }
    return number[a][b];
}

int main() {
    ifstream fin("subset.in");
    fin >> N;
    fin.close();
    sum = N*(N+1)/2;
    for(int a = 0; a < 820; a++)
        for(int b = 0; b < 40; b++)
    	    number[a][b] = -1;
    ofstream fout("subset.out");
    fout << (sum % 2 == 1 ? 0 : ways(sum/2, N) / 2) << "\n";
    fout.close();
    return 0;
}