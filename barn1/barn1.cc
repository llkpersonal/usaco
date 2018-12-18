/*
 ID: llkpers1
 PROG: barn1
 LANG: C++
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
using namespace std;

int barn_id[201];
int length[200];

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    
    int M, S, C;
    scanf("%d%d%d", &M, &S, &C);
    
    for(int i = 0; i < C; i++) {
        scanf("%d", &barn_id[i]);
    }
    
    sort(barn_id, barn_id+C);
    
    int ans = barn_id[C-1] - barn_id[0] + 1;
    
    for(int i = 0; i < C-1; i++) {
        length[i] = barn_id[i+1] - barn_id[i];
    }
    
    sort(length, length+C-1, greater<int>());

    for(int i = 0; i < min(C-1, M-1); i++) {
        ans = ans - (length[i] - 1);
    }
    
    printf("%d\n", ans);
    return 0;
}
