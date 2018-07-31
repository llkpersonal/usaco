/*
 ID: llkpers1
 PROG: beads
 LANG: C++
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int n;
string s;
// 这里我一开始使用了s[1000], 然后后面用的C语言的函数拼接的字符串，可是报错了。不知道原因是什么。。

int getMaxColor(const char *s, int idx) {
    int l = idx, r = idx + n - 1;
    //for(int i = l ; i <= r ; i++) fprintf(stderr, "%c", s[i]); fprintf(stderr, "\n");
    char color = 'w';
    int cnt = 0;
    while( l <= r ) {
        if(s[l] == 'w') cnt++;
        else if( color != 'w' && s[l] == color ) cnt++;
        else if( color == 'w' ) color = s[l], cnt++;
        else break;
        l++;
    }
    color = 'w';
    while( r >= l ) {
        if( s[r] == 'w' ) cnt++;
        else {
            if( color != 'w' && s[r] == color ) cnt++;
            else if( color == 'w' ) color = s[r], cnt++;
            else break;
        }
        r--;
    }
    return cnt;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    cin >> n >> s;
    s = s + s;
    //fprintf(stderr, "%s\n", s.c_str());
    int ans = getMaxColor(s.c_str(), 0);
    for(int i = 1; i < n ; i++) {
        ans = max(ans, getMaxColor(s.c_str(), i));
    }
    cout << ans << endl;
    return 0;
}
