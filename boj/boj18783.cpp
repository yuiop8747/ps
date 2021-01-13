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
int n, m, k, t, q, arr[MAX * 3];
vector<pii> vec;
vector<int> cycle[MAX];
int chk[MAX], ans[MAX], mem[MAX];
bool vst[MAX];
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		chk[i] = i;
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		vec.push_back({ l,r });
		while (l <= r) {
			swap(chk[l++], chk[r--]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		mem[chk[i]] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vst[i]) {
			vst[i] = true;
			int st = i, cur = mem[i];
			cycle[cnt].push_back(i);
			while (st != cur) {
				vst[cur] = true;
				cycle[cnt].push_back(cur);
				cur = mem[cur];
			}
			++cnt;
		}
	}

	for (int i = 0; i < cnt; ++i) {
		int sz = cycle[i].size();
		int val = k % sz, seq = 0;
		for (int j = val; j < sz; ++j) {
			ans[cycle[i][j]] = cycle[i][seq++];
		}
		for (int j = 0; j < val; ++j) {
			ans[cycle[i][j]] = cycle[i][seq++];
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}