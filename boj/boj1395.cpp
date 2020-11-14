#include<stdio.h>

using namespace std;
struct node {
    int lazy, light;
};
node tr[400010];

int update(int l, int r, int s, int e, int idx) {
    if (tr[idx].lazy) {
        tr[idx].light = (r-l+1) - tr[idx].light;
        if (l != r) {
            tr[idx * 2].lazy ^= 1;
            tr[idx * 2 + 1].lazy ^= 1;
        }
        tr[idx].lazy = 0;
    }
    if (r < s || e < l) return tr[idx].light;
    if (s <= l && r <= e) {
        if(l != r) {
            tr[idx * 2].lazy ^= 1;
            tr[idx * 2 + 1].lazy ^= 1;
        }
        return tr[idx].light = (r-l+1)-tr[idx].light;
    }
    int mid = l + r >> 1;
    return tr[idx].light = update(l, mid, s, e, idx * 2) + update(mid + 1, r, s, e, idx * 2 + 1);
}

int find(int l, int r, int s, int e, int idx) {
    if (tr[idx].lazy) {
        tr[idx].light = (r-l+1) - tr[idx].light;
        if (l != r) {
            tr[idx * 2].lazy ^= 1;
            tr[idx * 2 + 1].lazy ^= 1;
        }
        tr[idx].lazy = 0;
    }
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) {
        return tr[idx].light;
    }
    int mid = l + r >> 1;
    return find(l, mid, s, e, idx * 2) + find(mid + 1, r, s, e, idx * 2 + 1);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int o, s, t;
        scanf("%d %d %d", &o, &s, &t);
        if (!o) {
            update(1, n, s, t, 1);
        } else {
            printf("%d\n", find(1, n, s, t, 1));
        }
    }
    return 0;
}