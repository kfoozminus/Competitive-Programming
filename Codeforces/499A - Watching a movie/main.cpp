#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    short unsigned int n;
    unsigned int x;
    cin >> n >> x;
    unsigned int l[n], r[n];
    for(int a = 0; a < n; a++)
        cin >> l[a] >> r[a];
    unsigned int length = (l[0] - 1) % x;
    for(int a = 0; a < n; a++)
        length += r[a] - l[a] + 1;
    for(int a = 1; a < n; a++)
        length += (l[a] - (r[a-1] + 1)) % x;
    cout << length;
    return 0;
}