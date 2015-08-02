/* 
ID: apoorvk1
PROG: prefix
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> primitives;
bool visited[200000];
string S = "";

int main(int argc, char** argv) {
    ifstream fin("prefix.in");
    string hold;
    while(fin >> hold && hold != ".") primitives.push_back(hold);
    sort(primitives.begin(), primitives.end());
    while(fin >> hold) S += hold;
    fin.close();
    for(int a = 0; a < 200000; a++) visited[a] = false;
    for(int a = 0; a < S.length(); a++) {
        if(a != 0 && !visited[a - 1]) continue;
        for(int b = 0; b < primitives.size(); b++)
            if(S.length() >= a + primitives.at(b).length() && S.substr(a, primitives.at(b).length()) == primitives.at(b))
                visited[a + primitives.at(b).length() - 1] = true;
    }
    ofstream fout("prefix.out");
    for(int a = S.length() - 1; a >= -1; a--) {
        if(visited[a] || a == -1) {
            fout << (a+1) << "\n";
            break;
        }
    }
    fout.close();
    return 0;
}