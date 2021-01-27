#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
long long typedef ll;
int n,root;
bool flag;
double num = -1;
vector<int> vec[1010];
struct str{
    // cost : 답, sz : 크기, sum : cost 합
    ll ans, sz, sum;
    double ave;
};
str inp[1010];
void dfs(int cur,int p, bool trig){
    if(cur != root){
        if(trig && inp[cur].ave == num){
            ll sum = inp[p].sum + inp[cur].sum;
            ll sz = inp[p].sz + inp[cur].sz;
            ll ans = inp[p].ans + inp[cur].ans + inp[cur].sum * inp[p].sz;
            double ave = (1.0*sum) / sz;
            inp[p] = {ans,sz,sum,ave};
            for(int nxt : vec[cur]){
                vec[p].push_back(nxt);
            }
            for(int i = 0;i<vec[p].size(); ++i){
                if(vec[p][i] == cur) {
                    vec[p][i] = -1;
                    flag = true;
                    return;
                }
            }
        }
        else if(!trig){
            num = max(num,inp[cur].ave);
        }
    }
    for(int nxt : vec[cur]){
        if(!flag && nxt != -1) {
            dfs(nxt, cur, trig);
        }
    }
    return;
}

int main(){
    scanf("%d %d",&n,&root);
    for(int i = 1;i<=n;++i){
        int m;
        scanf("%d",&m);
        inp[i] = {m,1,m,1.0*m};
    }
    for(int i = 1;i<n;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        vec[u].push_back(v);
    }
    while(1) {
        num = -1;
        flag = false;
        dfs(root,-1,false);
        if(num == -1) break;
        else{
            dfs(root,-1,true);
        }
    }
    printf("%lld\n",inp[root].ans);
    return 0;
}