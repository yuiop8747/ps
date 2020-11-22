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
struct str {
	int x, y, idx;
	bool operator < (const str& A) const {
		if (x == A.x)
			return y < A.y;
		else
			return x < A.x;
	}
};
str inp[MAX];
int p[MAX];
int find(int a) {
	if (a == p[a]) return a;
	else return p[a] = find(p[a]);
}
void merge(int a, int b) {
	int na = find(a);
	int nb = find(b);
	p[nb] = na;
	return;
}
bool comp(str A, str B) {
	if (A.y == B.y)
		return A.x < B.x;
	else
		return A.y < B.y;
}
set<int> st;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &inp[i].x, &inp[i].y);
		inp[i].idx = i;
		p[i] = i;
	}
	sort(inp, inp + n);
	int mx = inp[n-1].y, idx = inp[n-1].idx;
	for (int i = n - 2; i >= 0; --i) {
		if (inp[i].y <= mx && (find(inp[i].idx) != find(idx))) {
			merge(inp[i].idx, idx);
		}
		if (inp[i].y > mx) {
			mx = inp[i].y;
			idx = inp[i].idx;
		}
	}
	sort(inp, inp + n, comp);
	int mn = inp[0].x;
	idx = inp[0].idx;
	for (int i = 1; i < n; ++i) {
		if (inp[i].x >= mn && (find(inp[i].idx) != find(idx))) {
			merge(inp[i].idx, idx);
		}
		if (inp[i].x < mn) {
			mn = inp[i].x;
			idx = inp[i].idx;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		st.insert(find(i));
	}

	printf("%d\n", st.size());
	return 0;
}