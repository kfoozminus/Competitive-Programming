#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    string word;
    unsigned int n;
    cin >> n;
    for(int a = 0; a < n; a++) {
        cin >> word;
        if(word.length() > 10)
            cout << word.at(0) << word.length() - 2 << word.at(word.length()-1) << "\n";
        else cout << word << "\n";
    }
    return 0;
}