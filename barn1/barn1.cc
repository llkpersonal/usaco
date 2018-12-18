/*
 ID: llkpers1
 PROG: barn1
 LANG: C++
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
    int length;
    int index;
};

Node node[201];
int barn_id[201];

bool compare(const Node& a, const Node& b) {
    return a.length > b.length;
}

bool compare_index(const Node& a, const Node& b) {
    return a.index > b.index;
}

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
        node[i].length = barn_id[i+1] - barn_id[i];
        node[i].index = i;
    }
    
    sort(node, node+C-1, compare);

    for(int i = 0; i < min(C-1, M-1); i++) {
        ans = ans - (node[i].length - 1);
    }
    
    printf("%d\n", ans);
    return 0;
}
