#include<stdio.h>
using namespace std;
int _map[101][101];
int main(){
    int n,m,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n ;++i)
            for(int j = 1;j<=m;++j)
                scanf("%d",&_map[i][j]);


        for(int i = 1;i<=n;++i)
            for(int j = 1+(i%2); j <= m; j+=2)
                if(_map[i][j] & 1)
                    _map[i][j]++;

        for(int i = 1;i<=n;++i)
            for(int j = 1+!(i%2); j <= m; j+=2)
                if(!(_map[i][j]&1))
                    _map[i][j]++;

        for(int i = 1;i<=n;++i) {
            for (int j = 1; j <= m; ++j)
                printf("%d ", _map[i][j]);
            printf("\n");
        }
    }
    return 0;
}