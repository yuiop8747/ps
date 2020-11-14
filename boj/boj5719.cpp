#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<queue>
#include<string.h>
#include<string>
#include<map>
#include<stack>
#include<vector>
#define mod 1000000007
using namespace std;
struct str {
    int cur,cost;
    bool operator < (const str&A)const {
        return cost > A.cost;
    }
};
vector<str> vec[600];
vector<int> back[600];
priority_queue<str> que;
int n,m,s,e;
int d[600];
queue<int> que_2;
bool chk[600];
int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (!n && !m)break;
        memset(chk,0,sizeof chk);
        scanf("%d %d", &s, &e);
        for (int i = 0; i <= 500; i++) {
            d[i] = 1e9; vec[i].clear(); back[i].clear();
        }
        d[s] = 0;
        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            vec[u].push_back({ v,p });
        }
        que.push({ s,0 });
        while (!que.empty()) {
            str temp = que.top(); que.pop();
            int start = temp.cur;
            if (d[start] < temp.cost)continue;
            int sz = vec[start].size();
            for (int i = 0; i < sz; i++) {
                int end = vec[start][i].cur;
                int cost = vec[start][i].cost;
                if (d[end] > d[start] + cost) {
                    d[end] = d[start] + cost;
                    back[end].clear();
                    back[end].push_back(start);
                    que.push({ end,d[end] });
                }
                else if (d[end] == d[start] + cost)
                    back[end].push_back(start);
            }
        }
        que_2.push(e);
        while (!que_2.empty()) {
            int temp = que_2.front(); que_2.pop();
            if(chk[temp])continue;
            chk[temp] = true;
            int sz = back[temp].size();
            for (int i = 0; i < sz; i++) {
                int st = back[temp][i];
                for (int j = 0; j < vec[st].size(); j++) {
                    if (vec[st][j].cur == temp) {
                        vec[st][j].cost = 1e9;
                        que_2.push(st);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++)d[i] = 1e9;
        d[s] = 0;
        que.push({ s,0 });
        while (!que.empty()) {
            str temp = que.top(); que.pop();
            int start = temp.cur;
            if (d[start] < temp.cost)continue;
            int sz = vec[start].size();
            for (int i = 0; i < sz; i++) {
                int end = vec[start][i].cur;
                int cost = vec[start][i].cost;
                if (d[end] > d[start] + cost) {
                    d[end] = d[start] + cost;
                    que.push({ end,d[end] });
                }
            }
        }
        if (d[e] == 1e9)printf("-1\n");
        else printf("%d\n", d[e]);
    }
    return 0;
}