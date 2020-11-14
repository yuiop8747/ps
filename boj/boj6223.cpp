#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
long long typedef ll;
ll n,arr[1100],cnt = -1;
int idx[1100],brr[1100];
vector<ll> vec[1100];
bool vst[1100];
map<int,int> mp;

void find(ll cur){
    while(!vst[cur]){
        vst[cur] = true;
        vec[cnt].push_back(arr[cur]);
        cur = mp[arr[cur]];
    }
}

int main(){
    scanf("%lld",&n);
    ll val = 1e9;
    for(int i = 1;i<=n;++i) {
        scanf("%lld", &arr[i]);
        brr[i] = arr[i];
        val = min(val,arr[i]);
    }
    sort(brr+1,brr+n+1);
    for(int i = 1; i<=n;++i)
        mp[brr[i]] = i;

    for(int i = 1;i <= n;++i){
        if(!vst[i])++cnt;
        find(i);
    }
    ll ans = 0;
    for(int i = 0;i<=cnt;++i) {
        sort(vec[i].begin(), vec[i].end());
        for (int j = 1; j < vec[i].size(); ++j) {
            ans += vec[i][j];
        }
        ll mn = min((vec[i][0]+val)*2 + val*(vec[i].size()-1),(vec[i][0]*(vec[i].size()-1)));
        ans += mn;
    }
    printf("%lld",ans);
    return 0;
}