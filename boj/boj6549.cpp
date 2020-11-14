#include<stdioh.>
#include<algorithm>
using namespace std;
long long typedef ll;
ll arr[100010],tr[400010];
int update(int l,int r,int num,int idx){
    if(num < l || r < num)
        return tr[idx];
    if(l == r)
        return tr[idx] = arr[num];
    int mid = l+r>>1;
    return tr[idx] = max(update(l,mid,num,idx*2),update(mid+1,r,num,idx*2+1));
}
int find(int l,int r,int s,int e, int idx){
    if(r < s || e < l )return 0;
    if(s <= l && r <= e)return tr[idx];
    int mid = l+r>>1;
    return max(find(l,mid,s,e,idx*2),find(mid+1,r,s,e,idx*2+1));
}
int sol(int cur){
    int l = cur,r = n;
    ll prv = 0;
    while(l <= r){
        int mid = l + r >> 1;
        ll val = find(1,n,cur,mid,1);
        if(prv > val)
            l = mid+1;
    }
}
int main(){
    while(true) {
        int n;
        scanf("%d", &n);
        if(!n)
            break;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            find(1,n,i,1);
        }
        for(int i = 1;i<=n;++i){

        }
    }
    return 0;
}