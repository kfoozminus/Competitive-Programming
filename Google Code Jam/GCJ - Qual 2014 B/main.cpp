#include <iomanip>
#include <stdio.h>
#include <fstream>
using namespace std;

int main(){
    ifstream input;
    input.open("B-small-practice.in", ios::in);
    FILE * pFile;
    pFile = fopen("put.out", "w");
    unsigned short int cases;
    input >> cases;
    double c, f, x, time;
    if(cases >= 1 && cases <= 100){
        for(int i = 0; i < cases; i++){
            time = 0;
            input >> c >> f >> x;
            if(x <= c){
                time = x/2;
            } else {
                time = 1e30;
                for(int u = 1; u < 100000; u++){
                    double time2 = c/2;
                    for(int v = u - 1; v > 0; v--){
                        time2 += c/(2+v*f);
                    }
                    time2 += x/(2+u*f);
                    if(time2 < time){
                        time = time2;
                    } else break;
                }
            }
            fprintf(pFile, "Case #%d: %1.7lf\n", (i+1), time);
        }
    }
    input.close();
    fclose(pFile);
    return 0;
}
