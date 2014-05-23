/*
ID: apoorvk1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    short signed int np, value, numpeople;
    string giver, reciever;
    cin >> np;
    signed int wallet[np];
    string names[np];
    for(int y = 0; y < np; y++){
        cin >> names[y];
    }
    /*
    for(int i = 0; i < np; i++){
        cin >> names[i];
        wallet[i] = 0;
    }
    for(int i = 0; i < np; i++){
        cin >> giver >> value >> numpeople;
        for(int f = 0; f < np; f++){
            out++;
            cout << out << endl;
        }
    }
        /*
        for(int basew = 0; basew < np; basew++){
            if(giver == names[basew]){
                wallet[basew] -= (value - (value % numpeople));
            }
        }
        */
        /*
        cin >> giver >> value >> numpeople;
        for(int basew = 0; basew < np; basew++){
            if(giver == names[basew]){
                wallet[basew] -= (value - (value % numpeople));
            }
        }
        */
        /*
        if(numrecievers != 0){
            //Input name of reciever, and add to their wallet
            for(int c = 0; c < numrecievers; c++){
                fin >> reciever;
                for(int co = 0; co < np; co++){
                    if(reciever == names[co]){
                        wallet[co] += (value - (value % numrecievers))/numrecievers;
                    }
                }
            }
        }
        */
        //fout << names[i] << " " << wallet[i] << endl;
    //}
    //for(int i = 0; i < np; i++){
        //cout << names[i] << " " << wallet[i] << endl;
    //}
    return 0;
}
