#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(int argc, char** argv) {
    unsigned long long int num;
    double val[150000];
    unsigned int counter = 0;
    while(cin >> num)
        val[counter++] = sqrt(num*1.0);
    for(int a = counter - 1; a >= 0; a--)
        cout << fixed << setprecision(4) << val[a] << endl;
    return 0;
}