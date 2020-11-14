#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
bool chk[1003100];
vector<int> vec;
bool sol(string tar){
    int l = 0,r = tar.size()-1;
    while(l <= r){
        if(tar[l] != tar[r])
            break;
        l++;
        r--;
    }
    return r <= l;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 2;i<=1500;++i){
        if(!chk[i]){
            for(int j = i*i; j <= 1003001; j += i)
                chk[j] = true;
        }
    }
    int ans = 0;
    for(int i = n;i<=1003001;++i){
        if(!chk[i] && i != 1){
            string temp = "";
            int idx = 1,num = i;
            for(int j = 0; j < 7; ++j){
                if(idx*10 > i)
                    break;
                idx *= 10;
            }
            while(idx){
                int t = num/idx;
                temp += t + '0';
                num -= t*idx;
                idx /= 10;
            }
            if(sol(temp)){
                ans = i;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}