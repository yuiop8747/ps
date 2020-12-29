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
int n, m, k, t, q, arr[MAX * 3],L[MAX],R[MAX];
char ch[10010];
string s;

int main() {
	scanf("%d", &n);
	scanf("%s", ch);
	s = ch;
	int prv = -1e9, temp = 1e9;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0')
			L[i] = prv;
		else {
			if (prv != -1e9) {
				temp = min(temp,i - prv);
			}
			prv = i;
		}
	}
	prv = 1e9;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '0')
			R[i] = prv;
		else
			prv = i;
	}
	
	int l = 0, r = n - 1, ans = 0;
	while (l < r) {
		while (s[l] == '1') {
			++l;
		}
		while (s[r] == '1') {
			--r;
		}
		int lval = min(R[l] - l, l - L[l]), rval = min(r - L[r], R[r] - r);

		ans = max(ans, min(lval, min(rval, r - l)));
		if (lval < rval)
			++l;
		else
			--r;
	}
	printf("%d\n", min(temp,ans));
	return 0;
}