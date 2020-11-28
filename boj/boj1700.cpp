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
int n, m, t, q, arr[101];
int main() {
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &arr[i]);
	int ans = 0;
	set<int> st;
	for (int i = 0; i < k; ++i) {
		if (st.size() < n || st.find(arr[i]) != st.end()) {
			st.insert(arr[i]);
		}
		else {
			map<int, int> mp;
			for (int j = i + 1; j < k; ++j) {
				if (!mp[arr[j]]) mp[arr[j]] = 1e9;
				mp[arr[j]] = min(mp[arr[j]], j);
			}
			int mx = 0, val;
			for (auto it = st.begin(); it != st.end(); ++it) {
				if (mp[*it] == 0) {
					val = *it;
					break;
				}
				else if (mx < mp[*it]) {
					val = *it;
					mx = mp[*it];
				}
			}
			st.erase(val);
			st.insert(arr[i]);
			++ans;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}