/*
 ID: llkpers1
 PROG: milk
 LANG: C++
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Farmar{
    int P, A;
};

bool cmp(const Farmar& a, const Farmar& b) {
    return a.P < b.P;
}

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    
    int N,M;
    scanf("%d%d", &N, &M);
    vector<Farmar> farmar(M, Farmar());
    for(int i = 0 ; i < M ; i++) {
        scanf("%d%d", &farmar[i].P, &farmar[i].A);
    }
    
    sort(farmar.begin(), farmar.end(), cmp);
    
    int ans = 0;
    int i = 0;
    while( N > 0 && i < M) {
        int buy = min(N, farmar[i].A);
        N = N - buy;
        ans = ans + buy * farmar[i].P;
        i++;
    }
    
    printf("%d\n", ans);
    return 0;
}
