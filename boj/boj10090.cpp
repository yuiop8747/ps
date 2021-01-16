#include<stdio.h>
#include<set>
using namespace std;
long long typedef ll;
ll tr[(int)1e6*4+1];
ll update(int l,int r,int num,int idx){
    if(num < l || r < num) return tr[idx];
    if(l == r)return ++tr[idx];
    int mid = l+r>>1;
    return tr[idx] = update(l,mid,num,idx*2) + update(mid+1,r,num,idx*2+1);
}
ll find(int l,int r,int s,int e,int idx){
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return tr[idx];
    int mid = l + r >> 1;
    return find(l,mid,s,e,idx*2) + find(mid+1,r,s,e,idx*2+1);
}
int main(){
    ll n,sum = 0;
    scanf("%lld",&n);
    set<int> st;
    for(int i = 1;i<=n;++i){
        int num;
        scanf("%d",&num);
        sum += find(1,n,num+1,n,1);
        update(1,n,num,1);
    }
    printf("%lld\n",sum);
}