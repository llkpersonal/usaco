/*
 ID: llkpers1
 PROG: friday
 LANG: C++
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int isLeapYear(int year) {
    if(year % 400 == 0) return 1;
    if(year % 100 == 0) return 0;
    if(year % 4 == 0) return 1;
    return 0;
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<int> cnt(7,0);
    int now = 0;
    for(int i = 1900 ; i <= 1900 + n - 1 ; i++) {
        for(int j = 1; j <= 12 ; j++) {
            if( i == 1900 && j == 1) {
                now = 13 % 7;
            } else {
                if( j == 3 ) {
                    now = (now + days[j - 1] + isLeapYear(i)) % 7;
                } else if( j == 1 ) {
                    now = (now + days[12]) % 7;
                } else {
                    now = (now + days[j - 1]) % 7;
                }
            }
            cnt[now]++;
        }
    }
    printf("%d %d %d %d %d %d %d\n", cnt[6], cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5]);
    return 0;
}
