#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int T,cs=1;
struct str{
    int to,high,cost;
    bool operator < (const str&A)const{
        return high < A.high;
    }
};

vector<str> vec[2100];
vector<str> route;

void dfs(int cur,int h,int val,int node){
    if(node == cur) {
        route.push_back({cur, h, val});
    }
    int cnt = 0;
    for(auto nxt : vec[cur]){
        if(h+1 <= nxt.high){
            dfs(nxt.to,nxt.high,val+cnt,node);
            cnt++;
        }
    }
    return;
}
int main(){
    scanf("%d",&T);
    while(T--) {
        int N,k,m;
        scanf("%d %d %d",&N,&k,&m);
        for(int i = 0;i<=N;++i)
            vec[i].clear();

        for(int i=1;i<=k;++i){
            int x,y;
            scanf("%d %d",&x,&y); // 가로
            vec[x].push_back({y,i});
            vec[y].push_back({x,i});
        }

        int ans = 0;
        for(int i=0;i<m;++i){ // query
            int s,e;
            scanf("%d %d",&s,&e);
            int mn = 1e9;
            route.clear();
            //node = e;
            dfs(s,0,0,e);
            sort(route.begin(),route.end());
            int idx = vec[e].size()-1;
            for(int i = route.size()-1; i >= 0; --i){
//                printf("to : %d / cost : %d / hight : %d\n",route[i].to,route[i].cost,route[i].high);
                while(vec[e][idx].high != route[i].high){
                    idx--;
                }
                int val = vec[e].size() - idx - 1 + route[i].cost;
                mn = min(mn,val);
            }
//            printf("-------\n");
            if(mn == 1e9){
                ans -= 1;
            }
            else{
                ans += mn;
            }
        }
        printf("Case #%d\n",cs++);
        printf("%d\n",ans);
    }
    return 0;
}