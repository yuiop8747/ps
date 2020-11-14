#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vec[101],W,RW;
int fail[10100],rfail[10010],n,k;

void make_fail(){
    int i = 0,j= -1;
    fail[0] = -1;
    while(i < k){
        if(j < 0 || W[i] == W[j]){
            ++i;
            ++j;
            fail[i] = j;
        } else j = fail[j];
    }
    return;
}

void rmake_fail(){
    int i = 0,j= -1;
    rfail[0] = -1;
    while(i < k){
        if(j < 0 || RW[i] == RW[j]){
            ++i;
            ++j;
            rfail[i] = j;
        } else j = rfail[j];
    }
    return;
}

bool find(int len,int idx){
    int i = 0,j = 0;
    while(i < len){
        if(j < 0 || vec[idx][i] == W[j]){
            ++j;
            ++i;
            if(j == k)
                return true;
        } else j = fail[j];
    }
    return false;
}

bool rfind(int len,int idx){
    int i = 0,j = 0;
    while(i < len){
        if(j < 0 || vec[idx][i] == RW[j]){
            ++i;
            ++j;
            if(j == k)
                return true;
        }
        else j = rfail[j];
    }
    return false;
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;++i){
        int m;
        scanf("%d",&m);
        if(m < k) {
            printf("NO\n");
            return 0;
        }
        for(int j = 0; j<m;++j){
            int num; scanf("%d",&num);
            vec[i].push_back(num);
        }
    }
    int len = vec[0].size();
    bool trig;
    for(int i = 0;i <= len - k;++i){
        W.clear();
        RW.clear();
        for(int j = i; j < i+k; ++j){
            W.push_back(vec[0][j]);
            RW.push_back(vec[0][j]);
        }
        reverse(RW.begin(),RW.end());
        make_fail();
        rmake_fail();
        trig = true;
        for(int i = 1;i<n && trig;++i){
            int sz = vec[i].size();
            trig = find(sz,i) || rfind(sz,i);
        }
        if(trig) break;
    }
    printf("%s\n",trig ? "YES" : "NO");
    return 0;
}