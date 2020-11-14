#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n,arr[200010];
bool chk[100010];
long long typedef ll;
int main(){
    for(int i = 1;i<=1e5;++i) chk[i] = true;
    for(int i = 2;i<=100000;++i){
        if(chk[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                chk[j] = false;
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        ll p,q;
        scanf("%lld %lld",&p,&q);
        for(int i = 2;i<=sqrt(q);++i){
            if(chk[i]){
                while(!(q % i)){
                    q /= i;
                    arr[i]++;
                }
            }
        }
        
    }
}