#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    unsigned short int n, k, count = 0;
    cin >> n >> k;
    unsigned short int a[n+1];
    for(int b = 1; b <= n; b++)
        cin >> a[b];
    for(int b = 1; b <= n; b++)
        if(a[b] >= a[k] && a[b] > 0)
            count++;
    cout << count << "\n";
    return 0;
}