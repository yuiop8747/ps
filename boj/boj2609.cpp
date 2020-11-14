#include<stdio.h>
using namespace std;
int _gcd(int a,int b){
    int c = a%b;
    while(c){
        a = b;
        b =c;
        c = a%b;
    }
    return b;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int ans_gcd = _gcd(n,m);
    int ans_lcd = n*m/ans_gcd;
    printf("%d\n%d",ans_gcd,ans_lcd);
}