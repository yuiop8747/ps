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
ll n, m, k, t, q, arr[5010], cnt[MAX * 40], num[5010][5010], dp[5010][5010];
int main() {
	scanf("%lld %lld", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &arr[i]);
		arr[i] += 1e6;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cnt[arr[j]] = 0;
		for (int j = i + 1; j <= n; ++j) {
			int temp = arr[i] + arr[j];
			if (temp <= 3e6) {
				num[i][j] = cnt[3000000 - temp];
			}
			cnt[arr[j]]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i-1; j >= 1; --j) {
			dp[j][i] = dp[j + 1][i] + dp[j][i - 1] + num[j][i] - dp[j + 1][i - 1];
		}
	}
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", dp[a][b]);
	}
}