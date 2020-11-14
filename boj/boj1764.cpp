#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
string s[1000100];
string ans[501000];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char ch[26];
    for(int i= 0 ; i< n;++i){
        scanf(" %s",ch);
        s[i] = ch;
    }
    for(int i = n;i<n+m;++i){
        scanf(" %s",ch);
        s[i] = ch;
    }
    sort(s,s+n+m);

    int cnt = 0;
    for(int i =1;i<n+m;++i){
        if(s[i-1] == s[i])
            ans[cnt++] = s[i];
    }
    printf("%d\n",cnt);
    for(int i =0 ;i<cnt;++i)
        printf("%s\n",ans[i].data());


}