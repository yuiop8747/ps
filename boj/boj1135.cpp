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
vector<int> vec[51];
vector<int> lst[51];
bool vst[51];
int dfs(int cur) {
	vst[cur] = true;
	int ans = -1, cnt = 0;
	for (auto nxt : vec[cur]) {
		if (!vst[nxt]) {
			lst[cur].push_back(dfs(nxt));
		}
	}
	sort(lst[cur].begin(), lst[cur].end());
	for (int i = lst[cur].size() - 1; i >= 0; --i) {
		ans = max(ans, lst[cur][i]+cnt);
		++cnt;
	}
	return ans+1;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		if (num == -1) continue;
		vec[i].push_back(num);
		vec[num].push_back(i);
	}
	printf("%d\n", dfs(0));
}