/*
ID: apoorvk1
PROG: dualpal
LANG: C++
*/
#include <fstream>
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
bool b2pal(int start){
    int counter = 0;
    char result[20];
    for(int a = 2; a <= 10; a++){
        if(isPal(baseChar(start, result, a))){
            counter++;
        }
    }
    if(counter >= 2){
        return true;
    } else {
        return false;
    }
}
int main(){
    ifstream fin("dualpal.in");
    unsigned short int N;
    unsigned int S;
    fin >> N >> S;
    fin.close();
    ofstream fout("dualpal.out");
    while(N != 0){
        S++;
        if(b2pal(S)){
            fout << S << endl;
            N--;
        }
    }
    fout.close();
    return 0;
}
