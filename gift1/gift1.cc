/*
 ID: llkpers1
 PROG: gift1
 LANG: C++
 */
#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> names;
    string name;
    for(int i = 0 ; i < n ; i ++) {
        cin >> name;
        names.push_back(name);
    }
    map<string, int> m;
    while( cin >> name ) {
        int a,b;
        cin >> a >> b;
        m[name] -= a;
        string given;
        for(int i = 0 ; i < b ; i++) {
            cin >> given;
            m[given] += a / b;
        }
        m[name] += b == 0 ? a : a % b;
    }
    for(int i = 0 ; i < names.size() ; i++) {
        cout << names[i] << " " << m[names[i]] << endl;
    }
    return 0;
}
