#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int n,arr[10010];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    bool trig = false;
    int idx = -1;
    for(int i =n-2;i >= 0;--i){
        if(arr[i] > arr[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1)
        printf("-1");
    else{
        int mx = 0,toggle_idx = 0;
        for(int i = idx+1; i < n; ++i){
            if(arr[i] < arr[idx]){
                if(mx < arr[i]){
                    mx = arr[i];
                    toggle_idx = i;
                }
            }
        }
        swap(arr[toggle_idx],arr[idx]);
        for(int i = 0;i<=idx;++i)
            printf("%d ",arr[i]);
        for(int i = n-1;i > idx; --i)
            printf("%d ",arr[i]);
    }
}