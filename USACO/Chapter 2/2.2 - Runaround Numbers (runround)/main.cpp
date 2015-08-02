/*
ID: apoorvk1
PROG: runround
LANG: C++
*/
#include <fstream>
using namespace std;

bool isRound(int num) {
    bool unq[10] = { false };
    int temp = num, len = 0;
    while(temp > 0) {
        int dig = temp % 10;
        temp /= 10;
        if(unq[dig])
            return false;
        unq[dig] = true;
        len++;
    }
    if(unq[0]) return false;
    temp = num;
    int digits[len], count = len - 1;
    while(temp > 0 && count >= 0) {
        digits[count--] = temp % 10;
        temp /= 10;
    }
    bool visited[len];
    for(int a = 0; a < len; a++)
        visited[a] = false;
    int pos = 0, curDig = 0;
    for(int a = 0; a < len; a++) {
        curDig = digits[pos];
        if(visited[pos]) return false;
        visited[pos] = true;
        if(pos + curDig < len)
            pos += curDig;
        else pos = (curDig - len + pos) % len;
    }
    return pos == 0;
}
int main() {
    int M;
    ifstream fin("runround.in");
    fin >> M;
    fin.close();
    while(!isRound(++M));
    ofstream fout("runround.out");
    fout << M << "\n";
    fout.close();
    return 0;
}