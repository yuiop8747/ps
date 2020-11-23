#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<memory.h>
#include<string>
#include<stack>
#include<queue>
#include<string.h>
#include<unordered_map>
#include<set>
#define mod 1000000007
#define fio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int GO_MAX = 26;
const int ESP = 1e-9;
const int MAX = 100001;
const int INF = 1e9;
int n, m, t, q, arr[MAX * 3];
ll tr[MAX * 4];
vector<ll> vec[MAX];
ll update(int l, int r, int num, int idx) {
	if (num < l || r < num) return tr[idx];
	if (l == r) return ++tr[idx];
	int mid = l + r >> 1;
	return tr[idx] = update(l, mid, num, idx * 2) + update(mid + 1, r, num, idx * 2 + 1);
}
ll find(int l, int r, int s, int e, int idx) {
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) return tr[idx];
	int mid = l + r >> 1;
	return find(l, mid, s, e, idx * 2) + find(mid + 1, r, s, e, idx * 2 + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		ll num = find(1, n, arr[i]+1, n, 1);
		vec[arr[i]].push_back(num);
		update(1,n,arr[i],1);
	}
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		printf("%lld\n", sum);
		for (auto e : vec[i]) {
			sum += e;
		}
	}
	return 0;
}