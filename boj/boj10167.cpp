#include<stdio.h>
#include<map>
#include<set>
using namespace std;
int n;
typedef long long ll;
map<int,int> mp;
struct str{
    int x,y,w;
};
struct node {
    int lsum=0,rsum=0;
};
str inp[6010];
node tr[6010*4];
node update(int l,int r,int s,int e,int idx,int val){
    if(r < s || e < l){
        return tr[idx];
    }
    if(s <= l && r <= e) {
        tr[idx].lsum += val;
        return tr[idx];
    }
    int mid = l+r >> 1;
    update(l,mid,s,e,idx*2,val);
    update(mid+1,r,s,e,idx*2+1,val);
    return tr[idx] = {tr[idx*2].lsum + tr[idx*2+1].lsum,tr[idx*2].rsum+tr[idx*2+1].rsum};
}

int find(int l,int r, int s,int e,int idx,bool v){
    if(r < s || e < l) {
        if(v){

        }
        else {
            return 
        }
    }
    if(s <= l && r <= e)
        return tr[idx];
    int mid = l+r >> 1;
    find(l,mid,s,e,idx*2,v);
    find(mid+1,r,s,e,idx*2+1,v);
    if(v)
        return tr[idx].lsum;
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;++i){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        mp[x] = 1;
        mp[y] = 1;
        inp[i] = {x,y,w};
    }
    int cnt = 1;
    for(auto it = mp.begin(); it != mp.end(); it++){
        it->second = cnt++;
    }
    for(int i = 0;i<n;++i){
        inp[i] = {mp[inp[i].x],mp[inp[i].y]};
    }

    return 0;
}