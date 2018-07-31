/*
 ID: llkpers1
 PROG: milk2
 LANG: C++
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    
    int N, s, t;
    vector<int> time(1000010, 0);
    scanf("%d", &N);
    int minn = 1111111, maxn = -1;
    for(int i = 0 ; i < N; i++) {
        scanf("%d%d", &s, &t);
        minn = min(minn, s);
        maxn = max(maxn, t);
        time[s]++;
        time[t]--;
    }
    int sum = 0, cnt_feed = 0, cnt_notfeed = 0;
    int maxfeed = 0 , maxnotfeed = 0;
    for(int i = minn ; i <= maxn; i++) {
        sum += time[i];
        if( sum > 0 ) {
            if( cnt_notfeed != 0 ) {
                maxnotfeed = max(maxnotfeed, cnt_notfeed);
                cnt_notfeed = 0;
            }
            cnt_feed++;
        } else if( sum == 0 ) {
            if( cnt_feed != 0 ) {
                maxfeed = max(maxfeed, cnt_feed);
                cnt_feed = 0;
            }
            cnt_notfeed++;
        }
    }
    printf("%d %d\n", maxfeed, maxnotfeed);
    return 0;
}
