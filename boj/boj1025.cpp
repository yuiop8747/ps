#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int _map[10][10],n,m,ans = -1;
void find(int x,int y){

    for(int i = -9; i<=9;++i){
        for(int j = -9; j<= 9;++j){
            if(!i && !j)continue;
            int val = 0,cur_x = x,cur_y = y;
            while(!(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m)){
                val *= 10;
                val += _map[cur_x][cur_y];
                cur_x += i;
                cur_y += j;
                int num = sqrt(val);
                if(num * num == val){
                    ans = max(ans,val);
                }
            }
        }
    }
    return;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;++i)
        for(int j = 0;j<m;++j)
            scanf("%1d",&_map[i][j]);
    for(int i = 0;i<n;++i)
        for(int j = 0;j<m;++j){
            find(i,j);
        }
    printf("%d",ans);
    return 0;
}