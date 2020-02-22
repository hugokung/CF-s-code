/**dp[i][j]表示在t1串里匹配到位置i，t2串里匹配到位置j的在s里匹配到的最短长度**/
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <iostream>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
const int MAXN = 51111;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const int maxn=100010;
const double PI=3.14159265;
typedef long long LL;
string s,t;
int dp[500][500];
vector<vector<int> >nex;
bool check(string a,string b)
{
    memset(dp,inf,sizeof dp);
    dp[0][0]=0;
    for(int i=0;i<=(int)a.size();i++){
        for(int j=0;j<=(int)b.size();j++){
            if(dp[i][j]>(int)s.size()) continue;
            int len=dp[i][j];
            if(nex[len][a[i]-'a']<inf) dp[i+1][j]=min(dp[i+1][j],nex[len][a[i]-'a']+1);
            if(nex[len][b[j]-'a']<inf) dp[i][j+1]=min(dp[i][j+1],nex[len][b[j]-'a']+1);
         }
    }
    return dp[(int)a.size()][(int)b.size()]<inf;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>s>>t;
        int flag=0;
        nex.assign((int)s.size()+1,vector<int>(26,inf));
        for(int i=(s.size()-1);i>=0;i--){
            nex[i]=nex[i+1];
            nex[i][s[i]-'a']=i;
        }
        for(int i=0;i<(int)t.size();i++){
            if(check(t.substr(0,i),t.substr(i,(int)t.size()))){cout<<"YES"<<'\n';flag=1;break;}
        }
        if(!flag) cout<<"NO"<<'\n';
    }
    return 0;
}
