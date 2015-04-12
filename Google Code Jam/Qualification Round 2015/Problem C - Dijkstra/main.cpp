/*
Google Code Jam: Qualification Round
Author: Apoorv Khandelwal(apoorvk)
Year: 2015
Problem: C.Dijkstra
*/
#include <fstream>
using namespace std;

struct CBBB { char a; bool b; bool c; bool d; };
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
unsigned short int T;
char multiply(char a, char b) {
    if(a == '1')
	return b;
    if(b == '1')
        return a;
    if(a == b)
        return '1';
    switch(a) {
	case 'i':
            if (b == 'j')
                return 'k';
            if (b == 'k')
                return 'j';
	case 'j':
            if (b == 'i')
                return 'k';
       	    if (b == 'k')
                return 'i';
	case 'k':
            if (b == 'i')
                return 'j';
            if (b == 'j')
                return 'i';
    }
    return '0';
}
bool pos(char a, char b) {
    if(a == '1' || b == '1')
        return false;
    if(a == b || a == 'i' && b == 'k' || a == 'j' && b == 'i' || a == 'k' && b == 'j')
	return true;
    return false;
}
CBBB check(string a, char b, bool c, bool d, bool e) {
    for (int g = 0; g < a.length(); g++) {
	char f = a.at(g);
	c = c ^ pos(b, f);
	b = multiply(b, f);
	if (b == 'i' && !c)
            d = true;
	if (d && b == 'k' && !c)
            e = true;
    }
    return {b, c, d, e};
}
int main(int argc, char** argv) {
    fin >> T;
    for(int cases = 1; cases <= T; cases++) {
        unsigned long long int L, X;
        string lett;
        fin >> L >> X >> lett;
	bool minus = false, foundOne = false, foundTwo = false;
        char ans = '1';
        for(int a = 0; a < X; a++) {
            CBBB ch = check(lett, ans, minus, foundOne, foundTwo);
	    ans = ch.a;
	    minus = ch.b;
	    foundOne = ch.c;
	    foundTwo = ch.d;
        }
        fout << "Case #" << cases << ": ";
        if (minus && ans == '1' && foundOne && foundTwo)
	    fout << "YES\n";
        else fout << "NO\n";
    }
    fin.close();
    fout.close();
    return 0;
}