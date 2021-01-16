#include<stdio.h>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;
struct str{
    int s,e;
    bool operator < (const str&A)const{
        return e < A.e;
    }
};
const int MAX = 100010;
str inp[MAX];
multiset<int>st;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;++i){
        scanf("%d %d",&inp[i].s,&inp[i].e);
    }
    sort(inp,inp+n);
    int cnt = k - 1,ans =0,last = 0;
    st.insert(1e9+1);
    st.insert(1e9+1);
    for(int i = 0; i<n;++i){
        str cur = inp[i];
        if(last >= cur.s) continue;
        auto val = st.lower_bound(cur.s);
        if(val != st.begin()) {
            --val;
        }
        if(*val < cur.s) {
            st.erase(val);
            st.insert(cur.e);
        }
        else{
            if(cnt){
                st.insert(cur.e);
                --cnt;
            }
            else {
                ++ans;
                last = cur.e;
            }
        }
    }
    printf("%d\n",ans);
}