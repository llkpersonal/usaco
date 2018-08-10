/*
 ID: llkpers1
 PROG: transform
 LANG: C++
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool rotate(int N,
             char m[11][11],
             char q[11][11],
             int degree) {
    for(int x = 0 ; x < N ; x++) {
        for(int y = 0 ; y < N ; y++) {
            if( degree == 0 ) {
                if( m[x][y] != q[x][y] )
                    return false;
            } if( degree == 90 ) {
                if( q[y][N-1-x] != m[x][y] )
                    return false;
            } else if( degree == 180 ) {
                if( q[N-1-x][N-1-y] != m[x][y] )
                    return false;
            } else if( degree == 270 ) {
                if( q[N-1-y][x] != m[x][y] )
                    return false;
            }
        }
    }
    return true;
}

void reflection(int N,
                char src[11][11],
                char dst[11][11]) {
    char t[11][11];
    memcpy(t, src, sizeof(t));
    for(int x = 0 ; x < N ; x++) {
        for(int y = 0; y < N ; y++) {
            dst[x][N-1-y] = t[x][y];
        }
    }
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int N;
    char m[11][11];
    char q[11][11];
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        scanf("%s", m[i]);
    }
    for(int i = 0 ; i < N ; i++) {
        scanf("%s", q[i]);
    }
    
    int ans = 7;
    
    if( rotate(N, m, q, 0) ) {
        ans = min(ans, 6);
    }
    if( rotate(N, m, q, 90) ) {
        ans = min(ans, 1);
    }
    if( rotate(N, m, q, 180) ) {
        ans = min(ans, 2);
    }
    if( rotate(N, m, q, 270) ) {
        ans = min(ans, 3);
    }
    
    reflection(N, m, m);
    
    if( rotate(N, m, q, 0) ) {
        ans = min(ans, 4);
    }
    if( rotate(N, m, q, 90) ||
        rotate(N, m, q, 180) ||
        rotate(N, m, q, 270)) {
        ans = min(ans, 5);
    }
    
    printf("%d\n", ans);
    return 0;
}
