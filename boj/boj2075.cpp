#include<queue>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 1;i<=n;++i) {
        for (int j = 1; j <= n; ++j){
            int num;
            scanf("%d",&num);
            if(q.size() < n)
                q.push(num);
            else if(q.top() < num){
                q.pop();
                q.push(num);
            }
        }
    }
    printf("%d",q.top());
    return 0;
}