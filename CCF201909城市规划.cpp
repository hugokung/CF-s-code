/**树形dp**/
/**dp[i][j]:在子树i选择了j个点之后对答案的贡献**/
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
int N,M,K;
ll dp[50010][110];
bool vis[50010];
int sum[50010];
vector<pair<int,ll> >g[50010];
ll tmp[110];
void dfs(int now,int fa)
{
    for(int i=0;i<=K;i++){  //对每个节点的初始化
        dp[now][i]=1e15;
    }
    dp[now][0]=0;           //dp边界的初始化
    if(vis[now]) {sum[now]=1;dp[now][1]=0;}
    for(auto x:g[now]){     //枚举连接的子节点
        if(x.first==fa) continue;
        dfs(x.first,now);   //遍历子树
        for(int i=0;i<=K;i++){tmp[i]=1e15;}
        for(int i=0;i<=min(sum[now],K);i++){
            for(int j=0;j<=min(sum[x.first],K)&&i+j<=K;j++){
                tmp[i+j]=min(tmp[i+j],dp[now][i]+dp[x.first][j]+1ll*(K-j)*j*x.second);//当前这条边对答案的贡献就是外面(K-j)个点到子树里的j个点的经过的次数
            }
        }
        sum[now]+=sum[x.first];
        for(int i=0;i<=min(sum[now],K);i++){
            dp[now][i]=min(dp[now][i],tmp[i]);
        }
    }
}
int main()
{
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1,x;i<=M;i++){scanf("%d",&x);vis[x]=1;}
    for(int i=1;i<=N-1;i++){
        int u,v;ll w;
        scanf("%d %d %lld",&u,&v,&w);
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    dfs(1,0);
    printf("%lld\n",dp[1][K]);
    return 0;
}
