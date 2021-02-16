#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,arr[2020];
long long dp[2020][2020];
int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;++i)
        scanf("%d",&arr[i]);

    for(int i = 0;i<=n;++i){
        if(i >= 2)
            dp[i][i-1] = dp[i-1][i] = 3e9;
        for(int j = 0; j < i-1; ++j){
            dp[i][j] = dp[i-1][j] + abs(arr[i] - arr[i-1]);
            long long v1 = dp[j][i-1],v2 = dp[i-1][j];
            dp[j][i] = dp[j][i-1] + abs(arr[i]-arr[i-1]);
            if(j > 0) {
                v1 += abs(arr[i] - arr[j]);
                v2 += abs(arr[i] - arr[j]);
            }
            dp[i][i-1] = min(dp[i][i-1],v1);
            dp[i-1][i] = min(dp[i-1][i],v2);
        }
    }
    long long ans = 3e9;
    for(int i = 0;i<n;++i){
        ans = min(dp[n][i],ans);
    }
    printf("%lld\n",ans);
    return 0;
}