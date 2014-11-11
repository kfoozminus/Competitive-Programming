#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    unsigned long long int n, m, a;
    cin >> n >> m >> a;
    n = 1 + ((n-1)/a);
    m = 1 + ((m-1)/a);
    cout << m*n << endl;
    return 0;
}