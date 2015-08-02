/*
ID: apoorvk1
PROB: preface
LANG: C++11
*/
#include <fstream>
#include <map>
using namespace std;

unsigned short int N;
const char letters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int main() {
    ifstream fin("preface.in");
    fin >> N;
    fin.close();
    map<char, int> numerals;
    for(int a = 0; a < 7; a++)
        numerals[letters[a]] = 0;
    for(int a = 1; a <= N; a++) {
        int t = a, counter = 0;
        while(t > 0 && counter < 4) {
            int digit = t % 10;
            if(counter == 3) numerals['M'] += digit;
            else {
                char one = letters[counter*2], five = letters[1 + counter*2], ten = letters[2+counter*2];
                if(digit < 4) numerals[one] += digit;
                else {
                    if(digit != 9) numerals[five]++;
                    else numerals[ten]++;
                    if((digit+1) % 5 == 0) numerals[one]++;
                    else if(digit > 5) numerals[one] += digit - 5;
                }
            }
            counter++;
            t /= 10;
        }
    }
    ofstream fout("preface.out");
    for(int a = 0; a < 7; a++)
        if(numerals[letters[a]] != 0)
            fout << letters[a] << " " << numerals[letters[a]] << "\n";
    fout.close();
}