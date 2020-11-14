#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
long long typedef ll;
int t, cs = 1;
ll L, S, E, A, B;
struct str {
    ll len, height;
};
struct rect{
    ll ceil,floor,width,record_height;
};
str Ceil[100010], Floor[100010];
rect rec[200100];
ll sol(){
    ll ans = 0;
    int f_idx = 0,c_idx= 0,cnt=0;
    for(cnt=0;(cnt < A+B && c_idx < A && f_idx < B);cnt++){
        int mn = min(Ceil[c_idx].len,Floor[f_idx].len);
        rec[cnt] = {Ceil[c_idx].height,Floor[f_idx].height,mn};
        Ceil[c_idx].len -= mn;
        Floor[f_idx].len -= mn;
        c_idx += !(Ceil[c_idx].len);
        f_idx += !(Floor[f_idx].len);
    }
    ll cur_height = S;
    for(int i = 0;i < cnt;++i){
        if(rec[i].floor > cur_height){
            cur_height += (rec[i].floor - cur_height);
        }
        else if(rec[i].ceil < cur_height){
            cur_height -= (cur_height - rec[i].ceil);
        }
        rec[i].record_height = cur_height;
    }
    cur_height = E;
    for(int i = cnt-1; i >= 0; --i){
        if(rec[i].floor > cur_height){
            cur_height += (rec[i].floor - cur_height);
        }
        else if(rec[i].ceil < cur_height){
            cur_height -= (cur_height - rec[i].ceil);
        }
        ans += (abs(rec[i].record_height-cur_height)*rec[i].width);
    }
    return ans;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %lld", &L, &S, &E);
        scanf("%lld", &A);
        for (int i = 0; i < A; ++i)
            scanf("%lld %lld", &Ceil[i].len, &Ceil[i].height);

        scanf("%lld", &B);
        for (int i = 0; i < B; ++i) {
            scanf("%lld %lld", &Floor[i].len, &Floor[i].height);
        }
        printf("Case #%d\n%lld\n", cs++, sol());
    }
    return 0;
}

