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
struct trie {
	trie* bit[2];
	bool end = false;
	trie() {
		bit[0] = bit[1] = nullptr;
	}
	~trie() {
		for (int i = 0; i < 2; ++i) {
			if (bit[i]) delete(bit[i]);
		}
	}
	void update(char* str) {
		int ch = *str - '0';
		if (*str == '\0') {
			end = true;
		}
		else {
			if (!bit[ch]) {
				bit[ch] = new trie();
			}
			bit[ch]->update(str + 1);
		}
	}
	int find(char* str,int cnt) {
		if (*str == '\0') {
			return 0;
		}
		int cur = *str - '0';
		if (cur == 0 && bit[1]) {
			return (bit[1]->find(str + 1, cnt - 1) + pow(2, cnt));
		}
		else if(cur == 1 && bit[0]){
			return (bit[0]->find(str + 1, cnt - 1) + pow(2, cnt));
		}
		else {
			for (int i = 0; i < 2; ++i) {
				if (bit[i])
					return bit[i]->find(str + 1, cnt - 1);
			}
		}
	}

};
int main() {
	scanf("%d",&n);
	trie* root = new trie;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		char ch[33] = { 0 };
		int cnt = 0;
		for (int j = 31; j >= 0; --j) {
			if ((1 << j) & arr[i])
				ch[cnt++] = '1';
			else
				ch[cnt++] = '0';
		}
		root->update(ch);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		char ch[33] = { 0 };
		int cnt = 0;
		for (int j = 31; j >= 0; --j) {
			if ((1 << j) & arr[i])
				ch[cnt++] = '1';
			else
				ch[cnt++] = '0';
		}
		ans = max(ans, root->find(ch, 31));
	}
	printf("%d\n", ans);
	delete(root);
	return 0;
}