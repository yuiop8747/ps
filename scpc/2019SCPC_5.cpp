#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;
int t, cs = 1,n;
struct str{
    long long x,y;
};
str arr[100010];
int main(){
    scanf("%d",&t);
    while(t--){
        long long l,r;
        scanf("%lld %lld",l,r);
        scanf("%d",&n);
        for(int i =0 ;i<n;++i){
            scanf("%lld %lld",&arr[i].x,&arr[i].y);
        }

    }
}