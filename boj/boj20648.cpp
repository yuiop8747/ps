#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
struct str{
    int x,y;
    bool operator < (const str&A) const{
        return x < A.x;
    }
};
long long typedef ll;
set<int> st;
map<int,int> mp;
str inp[2501];
int tr[10010];
int update(int l,int r,int idx,int num){
    if(r < num || num < l) return tr[idx];
    if(l == r) return tr[idx] += 1;
    int mid = l+r >> 1;
    return tr[idx] = update(l,mid,idx*2,num) + update(mid+1,r,idx*2+1,num);
}
int find(int l,int r,int s,int e,int idx){
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return tr[idx];
    int mid = l+r >> 1;
    return find(l,mid,s,e,idx*2) + find(mid+1,r,s,e,idx*2+1);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i){
        scanf("%d %d",&inp[i].x,&inp[i].y);
        st.insert(inp[i].y);
    }
    int cnt = 1;
    for(auto e : st){
        mp[e] = cnt++;
    }
    sort(inp+1,inp+1+n);
    for(int i = 1;i<=n;++i){
        inp[i].y = mp[inp[i].y];
    }
    ll ans = n+1;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n*4;++j)
            tr[j] = 0;
        for(int j = i+1; j<=n;++j){
            int hi = inp[i].y,lo = inp[j].y;
            if(hi < lo) swap(lo,hi);
            ll a = find(1,n,hi+1,cnt,1),b = find(1,n,1,lo-1,1);
            ans += (a+1) * (b+1);
            update(1,n,1,inp[j].y);
        }
    }
    printf("%lld\n",ans);
    return 0;
}