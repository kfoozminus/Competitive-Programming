/*
Google Code Jam: Qualification Round
Author: Apoorv Khandelwal(aprooro)
Year: 2014
Problem: A.Magic Trick
*/
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream input;
    input.open("A-small-attempt0.in", ios::in);
    unsigned short int cases, a1, a2, ca1[4][4], ca2[4][4];
    input >> cases;
    unsigned short int y[cases];
    if(cases >= 1 && cases <= 100){
        for(int i = 0; i < cases; i++){
            input >> a1;
            a1--;
            if(a1 == 0 || a1 == 1 || a1 == 2 || a1 == 3){
                for(int i = 0; i < 4; i++){
                    input >> ca1[i][0] >> ca1[i][1] >> ca1[i][2] >> ca1[i][3];
                }
                input >> a2;
                a2--;
                if(a2 == 0 || a2 == 1 || a2 == 2 || a2 == 3){
                    for(int i = 0; i < 4; i++){
                        input >> ca2[i][0] >> ca2[i][1] >> ca2[i][2] >> ca2[i][3];
                    }
                }
                int ans = 0;
                for(int a = 0; a <= 3; a++){
                    for(int b = 0; b <= 3; b++){
                        if(ca1[a1][a] == ca2[a2][b]){
                            y[i] = ca1[a1][a];
                            ans++;
                        }
                    }
                }
                if(ans == 0){
                    y[i] = 0;
                }
                if(ans > 1){
                    y[i] = 17;
                }
            }
        }
    }
    input.close();
    ofstream output;
    output.open ("put.out");
    for(int i = 0; i < cases; i++){
        output << "Case #" << (i+1) << ": ";
        if(y[i] != 0 && y[i] != 17){
            output << y[i] << endl;
        }
        if(y[i] == 0){
            output << "Volunteer cheated!" << endl;
        }
        if(y[i] == 17){
            output << "Bad magician!" << endl;
        }
    }
    output.close();
    return 0;
}
