#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
long long _gcd(long long a,long long b){
    if(!b)
        return a;
    long long c = a%b;
    while(c){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long K,N,x1,y1,x2,y2;
        scanf("%lld %lld %lld %lld %lld %lld",&K,&N,&x1,&y1,&x2,&y2);
        int xgap = fabs(x2-x1),ygap = fabs(y2-y1);
        bool ans = false;
        int num = _gcd(max(K*2,N*2),min(K*2,N*2));
        if(!(xgap % num) && !(ygap % num)) // a,d 짝수, b,d 짝수
            ans = true;
        if(!((xgap+K)%num) && !((ygap+N)%num)) // a,d짝수 , b,d홀수
            ans = true;
        if(!((xgap+N)%num) && !((ygap+K)%num)) // a,d홀수 b,d짝수
            ans = true;
        if(!((xgap+N+K)%num) && !((ygap+N+K)%num)) // a,d홀수 b,d,홀수
            ans = true;

        if(ans == true)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}