/*
ID: apoorvk1
PROG: lamps
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

unsigned short int N, C;
vector<int> on, off;
vector<string> states;

void flip(string switches, int countON) {
    if(countON > C || C % 2 != countON % 2) return;
    string lamps = "";
    for(int a = 0; a < N; a++)
        lamps += '1';
    for(int a = 0; a < 4; a++)
	if(switches.at(a) == '1')
            for(int b = (a == 2 ? 1 : 0); b < N; b += (a < 2 ? a+1 : a))
		lamps[b] = lamps[b] == '0' ? '1' : '0';
    for(int a = 0; a < on.size(); a++)
	if(lamps.at(on.at(a) - 1) == '0') return;
    for(int a = 0; a < off.size(); a++)
        if(lamps.at(off.at(a) - 1) == '1') return;
    states.push_back(lamps);
}

int main() {
	ifstream fin("lamps.in");
	fin >> N >> C;
        short int hold;
	while(fin >> hold && hold != -1)
            on.push_back(hold);
	while(fin >> hold && hold != -1)
            off.push_back(hold);
	fin.close();
        for(int a = 0; a < 16; a++) {
            string buttons = ((bitset<4>) a).to_string();
            flip(buttons, count(buttons.begin(), buttons.end(), '1'));
        }
        sort(states.begin(), states.end());
	ofstream fout("lamps.out");
	if(states.size() == 0) fout << "IMPOSSIBLE\n";
	else for(int a = 0; a < states.size(); a++)
            fout << states.at(a) << "\n";
	fout.close();
	return 0;
}