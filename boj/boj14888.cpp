#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int arr[101],N,cnt;
char op[101];
bool chk[101];
int mxdfs(int val,int idx){
    if(idx == N-1) {
        //printf("val is : %d\n",val);
        return val;
    }
    int mx = -1e9-1;
    for(int i=0;i<cnt;++i){
        if(chk[i] == false){
            chk[i] = true;
            if(op[i] == '+')
                mx = max(mx,mxdfs(val+arr[idx+1],idx+1));
            if(op[i] == '*')
                mx = max(mx,mxdfs(val*arr[idx+1],idx+1));
            if(op[i] == '/')
                mx = max(mx,mxdfs(val/arr[idx+1],idx+1));
            if(op[i] == '-')
                mx = max(mx,mxdfs(val-arr[idx+1],idx+1));
            chk[i] = false;
        }
    }
    return mx;
}
int mndfs(int val,int idx){
    if(idx == N-1)
        return val;
    int mn = 1e9+1;
    for(int i=0;i<cnt;++i){
        if(chk[i] == false){
            chk[i] = true;
            if(op[i] == '+')
                mn = min(mn,mndfs(val+arr[idx+1],idx+1));
            if(op[i] == '*')
                mn = min(mn,mndfs(val*arr[idx+1],idx+1));
            if(op[i] == '/')
                mn = min(mn,mndfs(val/arr[idx+1],idx+1));
            if(op[i] == '-')
                mn = min(mn,mndfs(val-arr[idx+1],idx+1));
            chk[i] = false;
        }
    }
    return mn;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&arr[i]);
    }
    int plus,minus,mul,div;
    scanf("%d %d %d %d",&plus,&minus,&mul,&div);
    for(int i =0;i<plus;++i)
        op[cnt++] = '+';
    for(int i = 0;i< minus; ++i)
        op[cnt++] = '-';
    for(int i =0;i<mul;++i)
        op[cnt++] = '*';
    for(int i=0;i<div;++i)
        op[cnt++] = '/';

    int mxans = mxdfs(arr[0],0);

    //memset(chk,0,sizeof chk);

    int mnans = mndfs(arr[0],0);
    printf("%d\n%d\n",mxans,mnans);
}