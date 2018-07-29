/*
 ID: llkpers1
 PROG: ride
 LANG: C++
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    char s1[10], s2[10];
    scanf("%s%s",s1,s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int mul1 = s1[0] - 'A' + 1;
    int mul2 = s2[0] - 'A' + 1;
    for(int i = 1; i < len1; i ++) {
        mul1 = (mul1 * (s1[i] - 'A' + 1)) % 47;
    }
    for(int i = 1; i < len2; i++) {
        mul2 = (mul2 * (s2[i] - 'A' + 1)) % 47;
    }
    printf(mul1 == mul2 ? "GO\n" : "STAY\n");
    return 0;
}
