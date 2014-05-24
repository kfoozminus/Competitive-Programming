/*
ID: apoorvk1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
unsigned short int days[7], first = 2;

int thirty(unsigned short int dayone){
    switch(dayone){
        case 0:
            days[5]++;
            first = 2;
            break;
        case 1:
            days[6]++;
            first = 3;
            break;
        case 2:
            days[0]++;
            first = 4;
            break;
        case 3:
            days[1]++;
            first = 5;
            break;
        case 4:
            days[2]++;
            first = 6;
            break;
        case 5:
            days[3]++;
            first = 0;
            break;
        case 6:
            days[4]++;
            first = 1;
            break;
    }
}

int thirtyone(unsigned short int dayone){
    switch(dayone){
        case 0:
            days[5]++;
            first = 3;
            break;
        case 1:
            days[6]++;
            first = 4;
            break;
        case 2:
            days[0]++;
            first = 5;
            break;
        case 3:
            days[1]++;
            first = 6;
            break;
        case 4:
            days[2]++;
            first = 0;
            break;
        case 5:
            days[3]++;
            first = 1;
            break;
        case 6:
            days[4]++;
            first = 2;
            break;
    }
}

int reg_feb(unsigned short int dayone){
    switch(dayone){
        case 0:
            days[5]++;
            first = 0;
            break;
        case 1:
            days[6]++;
            first = 1;
            break;
        case 2:
            days[0]++;
            first = 2;
            break;
        case 3:
            days[1]++;
            first = 3;
            break;
        case 4:
            days[2]++;
            first = 4;
            break;
        case 5:
            days[3]++;
            first = 5;
            break;
        case 6:
            days[4]++;
            first = 6;
            break;
    }
}

int leap_feb(unsigned short int dayone){
    switch(dayone){
        case 0:
            days[5]++;
            first = 1;
            break;
        case 1:
            days[6]++;
            first = 2;
            break;
        case 2:
            days[0]++;
            first = 3;
            break;
        case 3:
            days[1]++;
            first = 4;
            break;
        case 4:
            days[2]++;
            first = 5;
            break;
        case 5:
            days[3]++;
            first = 6;
            break;
        case 6:
            days[4]++;
            first = 0;
            break;
    }
}

int main(){
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");
    unsigned short int N;
    for(int a = 0; a < 7; a++){
        days[a] = 0;
    }
    fin >> N;
    fin.close();
    for(int b = 0; b < N; b++){
        thirtyone(first);
        if((1900+b)%4 == 0 && (1900+b)%100 != 0 || (1900+b)%400 == 0){
            leap_feb(first);
        } else {
            reg_feb(first);
        }
        thirtyone(first);
        thirty(first);
        thirtyone(first);
        thirty(first);
        thirtyone(first);
        thirtyone(first);
        thirty(first);
        thirtyone(first);
        thirty(first);
        thirtyone(first);
    }
    fout << days[0] << " " << days[1] << " " << days[2] << " " << days[3] << " " << days[4] << " " << days[5] << " " << days[6] << endl;
    fout.close();
    return 0;
}
