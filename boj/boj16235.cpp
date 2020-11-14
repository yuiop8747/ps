#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int A[11][11],_map[11][11];
int X[8] = {0,0,1,1,1,-1,-1,-1};
int Y[8] = {1,-1,0,-1,1,0,-1,1};
vector<int> vec[11][11];
vector<int> new_vec[11][11];
int main(){
    int n,m,k,cnt=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i =0 ;i<n;++i)
        for(int j =0 ;j<n;++j) {
            scanf("%d", &A[i][j]);
            _map[i][j] = 5;
        }
    for(int i = 0;i<m;++i) {
        int x, y, age;
        scanf("%d %d %d", &x, &y, &age);
        vec[x-1][y-1].push_back(age);
        cnt++;
    }
    while(k--){
        for(int i =0;i<n;++i) {
            for (int j = 0; j < n; ++j) {
                sort(vec[i][j].begin(), vec[i][j].end());
                bool trig = true;
                for (int tree : vec[i][j]) {
                    //printf("cnt : %d / 좌표 : %d,%d / 양분 : %d / tree : %d\n",cnt,i,j,_map[i][j],tree);
                    if(!trig){
                        _map[i][j] += tree/2;
                        cnt--;
                        continue;
                    }
                    if (_map[i][j] < tree){
                        trig = false;
                        _map[i][j] += tree/2;
                        cnt--;
                        continue;
                    }
                    _map[i][j] -= tree;
                    new_vec[i][j].push_back(tree+1);
                    if((tree + 1) % 5 == 0){
                        for(int l = 0; l < 8;++l){
                            int nx = i+X[l],ny = j+Y[l];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                            new_vec[nx][ny].push_back(1);
                            cnt++;
                        }
                    }
                }
                _map[i][j] += A[i][j];
            }
        }
        for(int i = 0;i<n;++i)
            for(int j = 0;j<n;++j) {
                vec[i][j] = new_vec[i][j];
                new_vec[i][j].clear();
            }

    }
    printf("%d\n",cnt);
}