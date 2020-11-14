#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<memory.h>
#include<algorithm>
using namespace std;
int T,X[3100],Y[3100],cs=1;
int dp[3010][3010],n,k,win=1;
int dfs(int x_idx,int y_idx){
    if(dp[x_idx][y_idx] != -1) {
        return dp[x_idx][y_idx];
    }
    int num = 0;
    int flag = false;
    for(int i = x_idx; i >= 1; --i){
         num += X[i];
         if(num > k)
             break;
         else{
             int temp = dfs(i-1,y_idx);
             if(temp == false) {
                 flag = true;
                 break;
             }
         }
    }
    num = 0;
    for(int i = y_idx; i>= 1;--i){
        num += Y[i];
        if(num > k)
            break;
        else{
            int temp = dfs(x_idx,i-1);
            if(temp == false) {
                flag = true;
                break;
            }
        }
    }
    win += flag;
    return dp[x_idx][y_idx] = flag;
}
int main(){
    setbuf(stdout, NULL);
    scanf("%d",&T);
    while(T--) {
        win = 1;
        scanf("%d %d",&n,&k);
        for(int i = 0;i<=n;++i)
            for(int j=0;j<=n;++j)
                dp[i][j] = -1;

        dp[0][0] = 1;
        for(int i=1;i<=n;++i)
            scanf("%d",&X[i]);
        for(int i=1;i<=n;++i)
            scanf("%d",&Y[i]);
        dfs(n,n);
        int l = (n+1)*(n+1)-win;
        printf("Case #%d\n%d %d\n",cs++,win,l);
    }
    return 0;
}