/*
 ID: llkpers1
 PROG: palsquare
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

void reverse(char* dst) {
    int len = strlen(dst);
    for(int i = 0 ; i < len / 2 ; i++) {
        char t = dst[i];
        dst[i] = dst[len-i-1];
        dst[len-i-1] = t;
    }
}

int main() {
    freopen("palsquare.in",  "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int B;
    scanf("%d", &B);
    char n[50], s[50];
    for( int i = 1 ; i <= 300 ; i++) {
        parse(i*i, s, B);
        if( isPalindromic(s) ) {
            parse(i, n, B);
            reverse(n);
            printf("%s %s\n", n, s);
        }
    }
    return 0;
}
