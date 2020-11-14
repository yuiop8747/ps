#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
struct str{
    int to,cost;
};
vector<str> vec[10100];
vector<int> lst[10100];
bool vst[10100];
int dfs(int cur){
    vst[cur] = true;
    int len = 0;
    for(auto nxt : vec[cur]){
        if(vst[nxt.to])continue;
        else{
            int temp = dfs(nxt.to) + nxt.cost;
            if(lst[cur].size() == 2){
                if(lst[cur][1] < lst[cur][0])
                    swap(lst[cur][1],lst[cur][0]);
                if(lst[cur][0] < temp)
                    lst[cur][0] = temp;
            }
            else
                lst[cur].push_back(temp);
            len = max(len,temp);
        }
    }
    return len;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    dfs(1);
    int ans =0 ;
    for(int i = 1;i<=n;++i){
        if(lst[i].size() == 2)
            ans = max(ans,lst[i][0]+lst[i][1]);
        else if(lst[i].size() == 1)
            ans = max(ans,lst[i][0]);
    }
    printf("%d\n",ans);
}