/*
ID: apoorvk1
PROG: holstein
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

unsigned short int V, G, req[25], vit[15][25], minScoops = 16;
bool feeds[15];

int count(string s, char check) {
  int count = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == check) count++;
  return count;
}

string binInc(string original) {
    if(count(original, '0') == 0) return "";
    bool overflow = false;
    for(int a = G - 1; a >= 0; a--) {
        if(!overflow) original[a] = original.at(a) == '0' ? '1' : '0';
        if(!(original.at(a) == '0' ? true : false)) break;
    }
    return original;
}

bool check(string combo) {
    for(int a = 0; a < V; a++) {
        int temp = 0;
        for(int b = 0; b < G; b++)
            if(combo.at(b) == '0') continue;
            else temp += vit[b][a];
        if(temp < req[a]) return false;
    }
    return true;
}

void solve() {
    string original = "";
    for(int a = 0; a < G; a++)
        original += "0";
    while(original != "") {
        int ones = count(original, '1');
        if(check(original) && ones <= minScoops) {
            minScoops = ones;
            for(int a = 0; a < G; a++)
                feeds[a] = original.at(a) == '1' ? 1 : 0;
        }
        original = binInc(original);
    }
}

int main(int argc, char** argv) {
    ifstream fin("holstein.in");
    fin >> V;
    for(int a = 0; a < V; a++)
        fin >> req[a];
    fin >> G;
    for(int a = 0; a < G; a++)
        for(int b = 0; b < V; b++)
            fin >> vit[a][b];
    fin.close();
    for(int a = 0; a < 15; a++)
        feeds[a] = false;
    solve();
    ofstream fout("holstein.out");
    fout << minScoops;
    for(int a = 0; a < G; a++)
        if(feeds[a])
            fout << " " << (a+1);
    fout << "\n";
    fout.close();
    return 0;
}