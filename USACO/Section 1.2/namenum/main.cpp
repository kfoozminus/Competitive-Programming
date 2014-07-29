/*
ID: apoorvk1
PROG: namenum
LANG: C++
*/
#include <fstream>
#include <math.h>
#include <string>
using namespace std;
int char2int(char x){
    if(x == 'A' || x == 'B' || x == 'C'){
        return 2;
    }
    if(x == 'D' || x == 'E' || x == 'F'){
        return 3;
    }
    if(x == 'G' || x == 'H' || x == 'I'){
        return 4;
    }
    if(x == 'J' || x == 'K' || x == 'L'){
        return 5;
    }
    if(x == 'M' || x == 'N' || x == 'O'){
        return 6;
    }
    if(x == 'P' || x == 'R' || x == 'S'){
        return 7;
    }
    if(x == 'T' || x == 'U' || x == 'V'){
        return 8;
    }
    if(x == 'W' || x == 'X' || x == 'Y'){
        return 9;
    }
}
int main(){
    ifstream fin ("namenum.in");
    unsigned long long int N, num;
    unsigned short int length = 0, counter = 0;
    fin >> N;
    fin.close();
    num = N;
    while(num > 0){
        num /= 10;
        length++;
    }
    ifstream din ("dict.txt");
    string tempDict[4617];
    for(int d = 0; d < 4617; d++){
        din >> tempDict[d];
    }
    din.close();
    ofstream fout ("namenum.out");
    for(int a = 0; a < 4617; a++){
        if(tempDict[a].length() == length){
            unsigned long long int dictNum = char2int(tempDict[a].at(0));
            for(int b = 1; b < tempDict[a].length(); b++){
                dictNum = dictNum * 10 + char2int(tempDict[a].at(b));
            }
            if(dictNum == N){
                fout << tempDict[a] << endl;
                counter++;
            }
        }
    }
    if(counter == 0){
        fout << "NONE" << endl;
    }
    fout.close();
    return 0;
}
