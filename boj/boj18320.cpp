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
ll n, m, k, t, q, arr[MAX * 3];
int main() {
	scanf("%lld %lld %lld", &n, &k, &m);
	ll l = 1, r = 1e12;
	while (l <= r) {
		ll mid = l + r >> 1, cur = 0;
		ll y = (n-cur)/mid, cnt = 0;
		while (y > m) {
			ll temp = (n - mid * y);
			ll givy = (temp - cur);
			ll day = givy / y + 1;
			cur += (y * day);
			cnt += day;
			y = (n - cur) / mid;
		}
		cnt += (n - cur + m - 1) / m;
		if (cnt <= k)
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%lld\n", r);
}