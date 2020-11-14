#include<stdio.h>
#include<algorithm>

using namespace std;
long long typedef ll;
int arr[100010], n;

struct str {
    int h, idx;

    bool operator<(const str &A) const {
        return h < A.h;
    }
};

str tr[400010];
const int inf = 1e9 + 1;

str update(int l, int r, int num, int idx) {
    if (num < l || r < num)
        return tr[idx];
    if (l == r)
        return tr[idx] = {arr[num], num};
    int mid = (l + r) / 2;
    return tr[idx] = min(update(l, mid, num, idx * 2), update(mid + 1, r, num, idx * 2 + 1));
}

str find(int l, int r, int s, int e, int idx) {
    if (r < s || e < l) return {inf, inf};
    if (s <= l && r <= e) return tr[idx];
    int mid = (l + r) / 2;
    return min(find(l, mid, s, e, idx * 2), find(mid + 1, r, s, e, idx * 2 + 1));
}

ll sol(int l, int r) {
    str v = find(1, n, l, r, 1);
    ll ans = 1LL * (r - l + 1) * v.h;
    if (l != v.idx) {
        ans = max(ans, sol(l, v.idx - 1));
    }
    if (r != v.idx) {
        ans = max(ans, sol(v.idx + 1, r));
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        update(1, n, i, 1);
    }
    printf("%lld\n", sol(1, n));

    return 0;
}