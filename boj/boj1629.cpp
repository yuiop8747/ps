#include<stdio.h>
using namespace std;
long long typedef ll;
ll mul[32];
int main(){
    ll A,B,C;
    scanf("%lld %lld %lld",&A,&B,&C);
    mul[0] = A;
    for(int i = 1;i<=31;++i){
        mul[i] = (mul[i-1]*mul[i-1]) % C;
    }
    ll ans = 1;
    for(ll i = 0;i<=31;++i){
        if((1 << i) & B){
            ans = (mul[i]*ans) % C;
        }
    }
    printf("%lld\n",ans);
}