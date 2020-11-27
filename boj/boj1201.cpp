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
int n, m, k, t, q;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	if (m + k > n + 1)printf("-1\n");
	else {
		int num = 1;
		vector<vector<int> > ans;
		vector<int> temp;
		while (n >= m) {
			for (int i = 0; i < m; ++i) {
				temp.push_back(num++);
			}
			n -= m;
			--k;
			ans.push_back(temp);
			temp.clear();
		}
		for (int i = 1; i <= n; ++i) {
			temp.push_back(num++);
		}
		if (temp.size() > 0) {
			ans.push_back(temp);
			--k;
		}

		for (int i = 1; i < ans.size() && k > 0; ++i) {
			int cur = 0;
			while (k > 0) {
				int lastNum = ans[i][ans[i].size() - 1];
				if (ans[i][cur] >= lastNum) break;
				ans[i].insert(ans[i].begin()+cur,lastNum);
				ans[i].pop_back();
				++cur;
				--k;
			}
		}
		if (k == 0) {
			for (int i = ans.size() - 1; i >= 0; --i) {
				for (auto e : ans[i])
					printf("%d ", e);
			}
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}