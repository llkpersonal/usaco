/*
 ID: llkpers1
 PROG: namenum
 LANG: C++
 */
#include <map>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

map< string, vector<string> > dict;
int alphabet[] = {2,2,2,3,3,3,
    4,4,4,5,5,5,6,6,6,
    7,7,7,7,8,8,8,9,9,9,9
};

void init() {
    ifstream fin("dict.txt");
    string s;
    while( fin >> s ) {
        string brand = "";
        for(int i = 0 ; i < s.size() ; i++) {
            brand.append(1, char(alphabet[s[i]-'A'] + '0'));
        }
        dict[brand].push_back(s);
    }
    fin.close();
}

int main() {
    init();
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    string s;
    fin >> s;
    
    auto it = dict.find(s);
    
    if( it == dict.end() ) {
        fout << "NONE" << endl;
    } else {
        for(auto& ans: it->second) {
            fout << ans << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
