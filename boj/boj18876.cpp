#include<stdio.h>
#include<vector>
using namespace std;
long long typedef ll;
ll dp[10010][1301], n, m;
vector<int> vec;
bool chk[10010];
int main() {
	scanf("%lld %lld", &n, &m);
	vec.push_back(0);
	for (int i = 2; i <= n; ++i) {
		if (!chk[i]) {
			vec.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				chk[j] = true;
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < vec.size(); ++i)
		dp[0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < vec.size();++j) {
			ll x = vec[j];
			while (1) {
				if (x > i) break;
				dp[i][j] = (dp[i][j] + dp[i - x][j - 1] * x) % m;
				x *= vec[j];
			}
		}
		for (int j = 1; j < vec.size(); ++j) {
			dp[i][j] += dp[i][j - 1] % m;
			dp[i][j] %= m;
		}
	}
	ll ans = 0;
	printf("%lld\n", dp[n][vec.size()-1]);
	return 0;
}