#include<stdio.h>
using namespace std;
bool chk[10100];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 2;i<=100;++i){
        if(!chk[i]){
            for(int j = i*i; j<=10000; j+=i)
                chk[j] = true;
        }
    }
    int sum = 0,mn = 1e9;
    for(int i = n;i<=m;++i){
        if(!chk[i] && i != 1){
            sum += i;
            if(mn == 1e9)
                mn = i;
        }
    }
    if(mn == 1e9)
        printf("-1");
    else
        printf("%d\n%d",sum,mn);
}