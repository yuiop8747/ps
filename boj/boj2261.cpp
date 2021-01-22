#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;
typedef pair<int,int> pii;
struct str{
    int x, y;
    bool operator < (const str&A)const{
        if(y == A.y)
            return x < A.x;
        else
            return y < A.y;
    }
};
set<str> st;
str inp[100100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i){
        scanf("%d %d",&inp[i].x,&inp[i].y);
    }
    sort(inp+1,inp+1+n,[](str A,str B){
        return A.x < B.x;
    });
    int mn = 1e9,idx = 0;

    for(int i = 1;i<=n;++i){
        str p = inp[i];
        while(st.size() > 0){
             str cur = inp[idx];
             int xv = p.x - cur.x;
             int val = xv * xv;
             if(val > mn) {
                 st.erase({cur.x, cur.y});
                 idx++;
             }
             else
                 break;
        }
        if(st.size() > 0){
            int num = sqrt(mn) + 1;
            auto loweridx = st.lower_bound({-100000,p.y - num});
            auto upperidx = st.upper_bound({100000,p.y + num});
            for(auto it = loweridx; it != upperidx; it++){
                str cur = *it;
                int xv = cur.x - p.x, yv = cur.y-p.y;
                mn = min(mn,xv*xv+yv*yv);
            }
        }

        st.insert({inp[i].x,inp[i].y});
    }
    printf("%d\n",mn);
}