#include<stdio.h>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<vector>
using namespace std;
struct str {
	int w, x, d;
	bool operator < (const str& A) const {
		return x < A.x;
	}
};
long long typedef ll;
str inp[50010];
int N, L, W;
queue<int> que;
int sol() {
	vector<pair<int,int> > left, right;
	for (int i = 1; i <= N; ++i) {
		if(inp[i].d < 0) {
			left.push_back({ inp[i].x,inp[i].w });
		}
		else {
			right.push_back({ inp[i].x,inp[i].w });
		}
	}

	vector<pair<int, int> > lst;
	int cnt = 0;
	for (int i = 0; i < left.size(); ++i) {
		lst.push_back({ left[i].first,inp[i + 1].w });
	}
	for (int i = 0; i < right.size(); ++i) {
		lst.push_back({ L - right[i].first, inp[left.size() + i + 1].w });
	}
	sort(lst.begin(), lst.end());
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += lst[i].second;
		if (sum * 2 >= W) {
			return lst[i].first;
		}
	}
}
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; ++i) {
		int w, x, d;
		scanf("%d %d %d", &w, &x, &d);
		inp[i] = { w,x,d };
		W += w;
	}
	sort(inp + 1, inp + N + 1);
	int T = sol();
	ll ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (inp[i].d > 0) {
			que.push(inp[i].x);
		}
		else {
			while (!que.empty()) {
				int v = que.front();
				if (v < inp[i].x - 2*T) que.pop();
				else break;
			}
			ans += (int)que.size();
		}
	
	}
	printf("%lld\n", ans);
	return 0;
}