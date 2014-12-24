#include <iostream>
#define ABS(a)((a) < 0 ? -(a):(a))
using namespace std;

int main(int argc, char** argv) {
    short int N;
    cin >> N;
    cout << (int)((1+N)/2.0*(1+ABS(1-N)));
    return 0;
}