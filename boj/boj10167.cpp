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
struct str {
	ll x, y, w;
};
str inp[3010];
struct node {
	ll lsum = 0, rsum = 0, totalsum = 0, maxsum = 0;
};
node tr[4010 * 4];
node update(int l, int r, int num, int idx,ll w) {
	if (num < l || r < num) return tr[idx];
	if (l == r) {
		tr[idx].lsum += w;
		tr[idx].rsum += w;
		tr[idx].totalsum += w;
		tr[idx].maxsum += w;
		return tr[idx];
	}
	int mid = l + r >> 1;
	node val1 = update(l, mid, num, idx * 2, w);
	node val2 = update(mid + 1, r, num, idx * 2 + 1, w);
	ll lsum = max(val1.totalsum + val2.lsum, val1.lsum);
	ll rsum = max(val2.totalsum + val1.rsum, val2.rsum);
	ll totalsum = val1.totalsum + val2.totalsum;
	ll maxsum = max({ lsum, rsum, totalsum, val1.rsum + val2.lsum,val1.maxsum,val2.maxsum });
	return tr[idx] = { lsum,rsum,totalsum,maxsum };
}
int main() {
	scanf("%d", &n);
	set<int> stx, sty;
	map<int, int> mpx, mpy;
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld %lld", &inp[i].x, &inp[i].y, &inp[i].w);
		stx.insert(inp[i].x);
		sty.insert(inp[i].y);
	}
	int cntx = 1;
	for (auto it = stx.begin(); it != stx.end(); ++it) {
		mpx[*it] = cntx++;
	}
	int cnty = 1;
	for (auto it = sty.begin(); it != sty.end(); ++it) {
		mpy[*it] = cnty++;
	}
	for (int i = 0; i < n; ++i) {
		inp[i] = { mpx[inp[i].x],mpy[inp[i].y],inp[i].w };
	}
	sort(inp, inp + n, [](str A, str B) {
		return A.y < B.y;
		});
	inp[n].y = -1e9;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		bool trig = false;
		for (int j = i; j < n; ++j) {
			update(1, cntx, inp[j].x, 1, inp[j].w);
			if (inp[j].y != inp[j + 1].y) {
				if (!trig) {
					trig = true; // y축의 기준값이 넘어가지는 부분은 처음으로 y축이 변할때이다.
					i = j;
				}
				ans = max(ans, tr[1].maxsum);
			}
		}
		for (int j = 0; j <= 16010; ++j) {
			tr[j] = { 0,0,0,0 };
		}
	}
	printf("%lld\n", ans);
}