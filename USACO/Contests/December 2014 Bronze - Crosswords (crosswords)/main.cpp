#include <fstream>
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
using namespace std;

unsigned short int N, M;
char grid[51][51];
int main() {
    ifstream fin("crosswords.in");
    fin >> N >> M;
    for(int a = 1; a <= N; a++)
        for(int b = 1; b <= M; b++)
            fin >> grid[a][b];
    fin.close();
    for(int a = 0; a <= N; a++)
        grid[a][0] = '#';
    for(int a = 0; a <= M; a++)
        grid[0][a] = '#';
    string finalOut = "";
    unsigned int count = 0;
    for(int a = 1; a <= N; a++) {
        for(int b = 1; b <= M; b++) {
            if((grid[a][b] == '.' && grid[a][b-1] == '#' && b+2 <= M && grid[a][b+1] == '.' && grid[a][b+2] == '.')
                || (grid[a][b] == '.' && grid[a-1][b] == '#' && a+2 <= N && grid[a+1][b] == '.' && grid[a+2][b] == '.')) {
                count++;
                finalOut += SSTR(a) + " " + SSTR(b) + "\n";
            }
        }
    }
    ofstream fout("crosswords.out");
    fout << count << "\n" << finalOut;
    fout.close();
    return 0;
}