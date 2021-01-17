#include<stdio.h>
#include<string>
using namespace std;
long long typedef ll;
int dp[5010][5010];
int sum[5010];
char ch[5010];
const int mod = 1e9+7;
int main(){
    scanf("%s",ch);
    string s = ch;
    if(s[0] == 'f')
        dp[0][1] = 1;
    else
        dp[0][0] = 1;

    for(int i = 1;i < s.size();++i){
        sum[0] = dp[i-1][0];
        for(int j = 1;j<=5000;++j){
            sum[j] = (sum[j-1] + dp[i-1][j])%mod;
            if(sum[j] < 0)
                sum[j] += mod;
        }
        if(s[i] == 'f'){
            if(s[i-1] == 'f'){ //ff
                for(int j = 0;j<=5000;++j){
                    dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % mod;
                }
            }
            else{ //ef
                for(int j = 0;j<=5000;++j) {
                    if(!j)
                        dp[i][j+1] = (dp[i][j+1] + sum[5000]) % mod;
                    else {
                        int val = sum[5000] - sum[j-1];
                        if(val < 0) val += mod;
                        dp[i][j + 1] = (dp[i][j + 1] + val) % mod;
                    }
                }
            }
        }
        else{
            if(s[i-1] == 'f'){ //fe
                for(int j = 0;j<=5000;++j){
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) %mod;
                }
            }
            else{ // ee
                for(int j = 0;j<=5000;++j) {
                    if(j == 0)
                        dp[i][j] = (dp[i][j] + sum[5000]) % mod;
                    else {
                        int val = sum[5000] - sum[j-1];
                        if(val < 0) val += mod;
                        dp[i][j] = (dp[i][j] + val) % mod;
                    }
                }
            };
        }
    }
    ll ans = 0;
    for(int i = 0;i<=5000;++i){
        ans = (ans + dp[s.size()-1][i]) % mod;
    }
    printf("%lld\n",ans);
}