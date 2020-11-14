#include<stdio.h>
using namespace std;
bool chk[1001000];
int main(){
    for(int i = 2;i<=1000; ++i){
        if(!chk[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                chk[j] = true;
            }
        }
    }
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=n;i<=m;++i){
        if(!chk[i] && i != 1)
            printf("%d\n",i);
    }
    return 0;
}