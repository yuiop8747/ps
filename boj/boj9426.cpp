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
int n, m, t, q, arr[MAX * 3];
priority_queue<int> mxque,mxdel;
priority_queue<int,vector<int>,greater<int> >mnque,mndel;
int chk[70100];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	for (int i = 0; i < k; ++i) {
		if (!mxque.size()) {
			mxque.push(arr[i]);
		}
		else {
			if (mxque.top() < arr[i]) {
				mnque.push(arr[i]);
			}
			else {
				mxque.push(arr[i]);
			}
		}
		while (mxque.size() < mnque.size()) {
			mxque.push(mnque.top());
			mnque.pop();
		}
		int mxsize = mxque.size(),mnsize = mnque.size();
		while (mxsize-2 >= mnsize) {
			mnque.push(mxque.top());
			mxque.pop();
			mxsize = mxque.size();
			mnsize = mnque.size();
		}
	}

	ll sum = mxque.top();
	int idx = 0;
	for (int i = k; i < n; ++i) {
		if (mxque.top() < arr[idx])
			mndel.push(arr[idx++]);
		else
			mxdel.push(arr[idx++]);

		if (mxque.top() < arr[i]) {
			mnque.push(arr[i]);
		}
		else {
			mxque.push(arr[i]);
		}
		while (mxque.size()-mxdel.size() < mnque.size()-mndel.size()) {
			if (mndel.size() > 0 && mndel.top() == mnque.top()) {
				while (mndel.size() > 0 && mnque.top() == mndel.top()) {
					mnque.pop();
					mndel.pop();
				}
			}
			if (mxdel.size() > 0 && mxdel.top() == mxque.top()) {
				while (mxdel.size() > 0 && mxque.top() == mxdel.top()) {
					mxque.pop();
					mxdel.pop();
				}
			}
			mxque.push(mnque.top());
			mnque.pop();
		}
		int mxsize = mxque.size() - mxdel.size(), mnsize = mnque.size() - mndel.size();
		while (mxsize - 2 >= mnsize) {
			if (mndel.size() > 0 && mndel.top() == mnque.top()) {
				while (mndel.size() > 0 && mnque.top() == mndel.top()) {
					mnque.pop();
					mndel.pop();
				}
			}
			if (mxdel.size() > 0 && mxdel.top() == mxque.top()) {
				while (mxdel.size() > 0 && mxque.top() == mxdel.top()) {
					mxque.pop();
					mxdel.pop();
				}
			}
			mnque.push(mxque.top());
			mxque.pop();
			mxsize = mxque.size() - mxdel.size();
			mnsize = mnque.size() - mndel.size();
		}
		if (mndel.size() > 0 && mndel.top() == mnque.top()) {
			while (mndel.size() > 0 && mnque.top() == mndel.top()) {
				mnque.pop();
				mndel.pop();
			}
		}
		if (mxdel.size() > 0 && mxdel.top() == mxque.top()) {
			while (mxdel.size() > 0 && mxque.top() == mxdel.top()) {
				mxque.pop();
				mxdel.pop();
			}
		}
		sum += mxque.top();
	}
	printf("%lld\n", sum);
}