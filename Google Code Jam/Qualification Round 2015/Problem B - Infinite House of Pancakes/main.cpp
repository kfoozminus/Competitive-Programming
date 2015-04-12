/*
Google Code Jam: Qualification Round
Author: Apoorv Khandelwal(apoorvk)
Year: 2015
Problem: B.Infinite House of Pancakes
*/
#include <fstream>
#include <vector>
#include <algorithm>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;

unsigned int T;
bool empty(vector<int> &pan) {
    bool rVal = true;
    for(int a = 0; a < pan.size();)
        if(pan[a] > 0) { rVal = false; a++; }
        else pan.erase(pan.begin() + a);
    return rVal;
}
vector<int> operate(vector<int> pan) {
    for(int a = 0; a < pan.size();)
        if(--pan[a] == 0)
            pan.erase(pan.begin() + a);
        else a++;
    return pan;
}
vector<int> half(vector<int> pan) {
    if(pan[0] == 9) {
        pan.push_back(3);
        pan[0] = 6;
    } else {
        pan.push_back((int)(pan[0]/2));
        pan[0] -= pan[pan.size() - 1];
    }
    return pan;
}
int solve(vector<int> pancakes, int mins) {
    sort(pancakes.begin(), pancakes.end());
    reverse(pancakes.begin(), pancakes.end());
    if(empty(pancakes)) return mins;
    int max = pancakes[0];
    int val1 = solve(operate(pancakes), mins + 1);
    if(max < 2) return val1;
    int val2 = solve(half(pancakes), mins + 1);
    return MIN(val1, val2);
}
int main(int argc, char** argv) {
    ifstream fin("pancakes.in");
    fin >> T;
    ofstream fout("pancakes.out");
    for(int cases = 1; cases <= T; cases++) {
        vector<int> pancakes;
        unsigned int D, temp;
        fin >> D;
        for(int a = 0; a < D; a++) {
            fin >> temp;
            pancakes.push_back(temp);
        }
        fout << "Case #" << cases << ": " << solve(pancakes, 0) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
