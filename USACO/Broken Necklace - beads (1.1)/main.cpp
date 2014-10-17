/*
ID: apoorvk1
PROG: beads
LANG: C++
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    unsigned short int N, maxBeads = 0;
    string beads;
    fin >> N >> beads;
    fin.close();
    if(N >= 3 && N <= 350 && beads.length() == N){
        for(int i = 0; i < N; i++){
            unsigned short int buffer;
            if(i != 0){
                char hold = beads.at(0);
                beads[0] = beads[N-1];
                for(int repChar = N; repChar > 1; repChar--){
                    beads[repChar - 1] = beads[repChar - 2];
                }
                beads[1] = hold;
            }
            if(count(beads.begin(), beads.end(), 'w') == N || count(beads.begin(), beads.end(), 'r') == N || count(beads.begin(), beads.end(), 'b') == N){
                buffer = N;
            } else {
                if(count(beads.begin(), beads.end(), 'b') == 0 || count(beads.begin(), beads.end(), 'r') == 0){
                    buffer = N;
                } else {
                    if(beads.at(0) == 'b'){
                        buffer = beads.find_first_of('r');
                    }
                    if(beads.at(0) == 'r'){
                        buffer = beads.find_first_of('b');
                    }
                    if(beads.at(0) == 'w'){
                        if(beads.find_first_of('b') < beads.find_first_of('r')){
                            buffer = beads.find_first_of('r');
                        } else {
                            buffer = beads.find_first_of('b');
                        }
                    }
                    if(beads.at(N-1) == 'b'){
                        buffer += N - 1 - beads.find_last_of('r');
                    }
                    if(beads.at(N-1) == 'r'){
                        buffer += N - 1 - beads.find_last_of('b');
                    }
                    if(beads.at(N-1) == 'w'){
                        if(beads.find_last_of('b') < beads.find_last_of('r')){
                            buffer += N - 1 - beads.find_last_of('b');
                        } else {
                            buffer += N - 1 - beads.find_last_of('r');
                        }
                    }
                }
            }
            if(buffer > maxBeads){
                maxBeads = buffer;
            }
        }
    }
    if(maxBeads > N){
        maxBeads = N;
    }
    fout << maxBeads << endl;
    fout.close();
    return 0;
}
