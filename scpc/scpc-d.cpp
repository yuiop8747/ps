#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int T,X[3100],Y[3100],cs=1;
string s;
vector<string> vec;
char ch[51010];

string cal(string s,string val){
    if(val.size() > s.size())
        swap(val,s);
    int sz = s.size();
    bool trig = false;
    for(int i = sz-1;i>=0;--i){
        int cur = s[i]-'0' + trig;
        int num = val[i] - '0';
        int temp = cur+num;
        if(temp > 10) {
            temp -= 10;
            trig = true;
        }
        else trig = false;
    }
}

int main(){
    scanf("%d",&T);
    while(T--) {
        vec.clear();
        int N,k,m;
        scanf("%d %d %d",&N,&k,&m);
        scanf(" %s",ch);
        s = ch;
        int sz = s.size();
        for(int i = 0;i<sz-k;++i){
            string temp = s.substr(i,k);
            vec.push_back(temp);
            int t_sz = temp.size();
            for(int j = 0;j<t_sz;++j){
                if(temp[j] == '1')continue;
                char t_ch = temp[j];
                temp[j] = '1';
                vec.push_back(temp);
                temp[j] = t_ch;
            }
        }

        sort(vec.begin(),vec.end());
        for(int i = 0;i<vec.size();++i){

        }

    }
    return 0;
}