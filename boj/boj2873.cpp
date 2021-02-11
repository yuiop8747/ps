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
int n, m, k, t, q, x, y, arr[1010][1010];
string ans;
int main() {
	int r, c, mn = 1e9;
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j) {
			scanf("%d", &arr[i][j]);
			if ((i % 2) != (j % 2)) {
				if (mn > arr[i][j]) {
					mn = arr[i][j];
					x = i; y = j;
				}
			}
		}

	if (r % 2 || c % 2) {
		if (r % 2) {
			for (int i = 1; i <= r; ++i) {
				if (i % 2) {
					for (int j = 2; j <= c; ++j)
						ans += 'R';
				}
				else {
					for (int j = 2; j <= c; ++j)
						ans += 'L';
				}
				if (i != r)
					ans += 'D';
			}
		}
		else {
			for (int i = 1; i <= c; ++i) {
				if (i % 2) {
					for (int j = 2; j <= r; ++j)
						ans += 'D';
				}
				else {
					for (int j = 2; j <= r; ++j)
						ans += 'U';
				}
				if (i != c)
					ans += 'R';
			}
		}
	}
	else {
		int tx = (x + 1) / 2, tr = (r + 1) / 2;
		int ty = (y + 1) / 2, tc = (c + 1) / 2;
		for (int i = 1; i < tx; ++i) {
			for (int j = 2; j <= c; ++j)
				ans += 'R';
			ans += 'D';
			for (int j = 2; j <= c; ++j)
				ans += 'L';
			ans += 'D';
		}
		for (int i = 1; i < ty; ++i) {
			ans += "DRUR";
		}
		int cury = (ty-1) * 2 + 1;
		if (y == cury) {
			ans += "RD";
		}
		else {
			ans += "DR";
		}
		for (int i = 0; i < tc - ty; ++i) {
			ans += "RURD";
		}
		for (int i = 0; i < tr - tx; ++i) {
			ans += 'D';
			for (int j = 2; j <= c; ++j) {
				ans += 'L';
			}
			ans += 'D';
			for (int j = 2; j <= c; ++j) {
				ans += 'R';
			}
		}
	}
	printf("%s\n", ans.data());
	return 0;
}