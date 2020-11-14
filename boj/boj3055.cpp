#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;
int r,c;
struct str{
    int x,y,time;
};
queue<str> que;
queue<str> water_que;
char _map[51][51] = {0};
bool vst[51][51];
int water[51][51];
int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};
int main(){
    scanf("%d %d",&r,&c);
    memset(water,0x3f,sizeof water);
    for(int i = 0;i < r;++i)
        for(int j = 0;j< c; ++j) {
            scanf(" %c",&_map[i][j]);
            if(_map[i][j] == 'S') {
                que.push({i, j, 0});
            }
            if(_map[i][j] == '*') {
                water_que.push({i, j, 0});
            }
        }

    while(!water_que.empty()){
        str cur = water_que.front();water_que.pop();
        if(water[cur.x][cur.y] != 0x3f3f3f3f)
            continue;
        water[cur.x][cur.y] = cur.time;

        for(int i = 0;i < 4;++i){
            int nx = cur.x + X[i],ny = cur.y + Y[i];
            //printf("%d %d\n",nx,ny);
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(water[nx][ny] == 0x3f3f3f3f && _map[nx][ny] != 'X' && _map[nx][ny] != 'D'){
                water_que.push({nx,ny,cur.time+1});
            }
        }
    }
    int ans = -1;
    while(!que.empty()){
        str cur = que.front();que.pop();
        if(_map[cur.x][cur.y] == 'D'){
            ans = cur.time;
            break;
        }
        if(vst[cur.x][cur.y])continue;
        vst[cur.x][cur.y] = true;
        for(int i =0 ;i<4;++i){
            int nx = cur.x+X[i],ny = cur.y+Y[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(cur.time+1 < water[nx][ny] && _map[nx][ny] != 'X'){
                que.push({nx,ny,cur.time+1});
            }
        }
    }
    if(ans != -1)
        printf("%d",ans);
    else
        printf("KAKTUS");
}