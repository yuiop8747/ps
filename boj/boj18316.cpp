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
int n, m, k, t, q, arr[1010], dp[1010][1010];
vector<int> vec[1010];
int main() {
	int c;
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);

	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	memset(dp, -1, sizeof dp);
	dp[1][0] = 0;
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[j][i] != -1) {
				for (auto e : vec[j]) {
					dp[e][i + 1] = max(dp[e][i + 1], dp[j][i] + arr[e]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 1000; ++i)
		ans = max(ans, dp[1][i] - c * i * i);
	printf("%d\n", ans);
	return 0;
}