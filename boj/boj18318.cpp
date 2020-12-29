#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
set<ll> sty;
map<ll,ll> mpy;
struct str{
    ll x,y,idx;
    bool chk;
    bool operator < (const str&A)const{
        if(x == A.x)
            return y < A.y;
        return x < A.x;
    }
};
str inp[201000];
ll tr[801000],val[100010],gap[100010];

void update(int l,int r,int s,int e,int idx, ll val){
    if(e < l || r < s) return;
    if(s <= l && r <= e) {
        tr[idx] = max(tr[idx],val);
        return;
    }
    int mid = l+r >> 1;
    update(l,mid,s,e,idx*2,val);
    update(mid+1,r,s,e,idx*2+1,val);
    return;
}

ll find(int l,int r,int num,int idx){
    if(num < l || r < num) return 0;
    if(l == r) return tr[idx];
    int mid = l + r >> 1;
    ll mx = max(find(l,mid,num,idx*2),find(mid+1,r,num,idx*2+1));
    return max(mx,tr[idx]);
}

int main(){
    int n,p,lst = 0;
    scanf("%d %d",&n,&p);
    for(int i =0;i<p;++i){
        ll x1,y1,x2,y2,v = 0;
        scanf("%lld %lld",&x1,&y1);
        inp[lst++] = {x1,y1,i,true};
        sty.insert(y1);
        scanf("%lld %lld",&x2,&y2);
        inp[lst++] = {x2,y2,i,false};
        sty.insert(y2);
        gap[i] = x2-x1+y2-y1;
    }

    ll cnt = 1,ans=2*n;
    for(auto e : sty)
        mpy[e] = cnt++;

    sort(inp,inp+lst);
//    printf("%d\n",cnt);
    for(int i = 0;i<lst;++i){
        ll y = mpy[inp[i].y];
        if(inp[i].chk){ // bg
//            printf("bg : %d / %d\n",inp[i].idx,gap[inp[i].idx]);
            val[inp[i].idx] = find(1,cnt,y,1) + gap[inp[i].idx];
        }
        else{
//            printf("ed : %d / %lld\n",inp[i].idx,val[inp[i].idx]);
            ans = min(ans,2*n-val[inp[i].idx]);
            update(1,cnt,y,cnt,1,val[inp[i].idx]);
        }
    }

    printf("%lld\n",ans);
    return 0;
}