/*
ID: apoorvk1
PROG: palsquare
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

bool isPal(string in){
    if(in.length() == 1){
        return true;
    }
    if(in.length() == 2 || in.length() == 3){
        if(in.at(0) == in.at(in.length()-1)){
            return true;
        } else {
            return false;
        }
    } else {
        do {
            if(in.at(0) == in.at(in.length()-1)){
                in = in.substr(1, in.length() - 2);
            } else {
                return false;
            }
        } while(in.length() > 3);
        if(in.length() == 3 || in.length() == 2){
            if(in.at(0) == in.at(in.length()-1)){
                return true;
            } else {
                return false;
            }
        }
    }
}

char* baseChar(int num, char* str, int base){
	int i = 0;
	while (num != 0) {
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
		num = num/base;
	}
	str[i] = '\0';
	int start = 0;
	i--;
	while (start < i){
		swap(*(str+start), *(str+i));
		start++;
		i--;
	}
	return str;
}

int main(){
    ifstream fin("palsquare.in");
    unsigned short int B;
    fin >> B;
    fin.close();
    char bufferCh[20];
    char aCh[15];
    ofstream fout("palsquare.out");
    for(int a = 1; a <= 300; a++){
        baseChar(a*a, bufferCh, B);
        string buffer(bufferCh);
        if(isPal(buffer)){
            baseChar(a, aCh, B);
            fout << aCh << " " << buffer << endl;
        }
    }
    fout.close();
    return 0;
}
