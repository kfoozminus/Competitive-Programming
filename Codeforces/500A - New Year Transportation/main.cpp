#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    unsigned int n, t;
    cin >> n >> t;
    unsigned int a[n];
    for(int b = 1; b < n; b++)
        cin >> a[b];
    bool works = false;
    int pos = 1;
    while(pos < n) {
        pos += a[pos];
        if(pos == t) {
            works = true;
            break;
        }
        if(pos > t) break;
    }
    if(works)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}