/*
 ID: llkpers1
 PROG: dualpal
 LANG: C++
 */
#include <cstdio>
#include <cstring>
using namespace std;

void parse(int src, char* dst, int base) {
    static char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int ptr = 0;
    while( src ) {
        dst[ptr++] = alphabet[src % base];
        src /= base;
    }
    dst[ptr] = '\0';
}

bool isPalindromic(char* dst) {
    int len = strlen(dst);
    for(int i = 0 ; i < len / 2 ; i++) {
        if( dst[i] != dst[len-i-1] )
            return false;
    }
    return true;
}

bool check(int x) {
    char s[50];
    int cnt = 0;
    for(int i = 2 ; i <= 10 ; i++) {
        parse(x, s, i);
        if( isPalindromic(s) ) {
            cnt++;
        }
        if( cnt == 2 ) return true;
    }
    return false;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int N,S;
    scanf("%d%d", &N, &S);
    int j = 0;
    for(int i = S+1 ; j < N; i++) {
        if(check(i)) {
            printf("%d\n", i);
            j++;
        }
    }
    return 0;
}
