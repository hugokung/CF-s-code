/**题意：给出一个长度为N的数组m，求一个序列，满足当前位置i的值不大于m[i]且两边不存同时比他大的数**/
/**分治**/
/**假设当前处理到区间[L,R]，找到区间的最小值是mi,位置是pos，只需要找到是把pos左边这段变成mi比较大还是把右边这段变成mi比较大就可以了。**/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
const int MAXN = 51111;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const int maxn=500010;
const double PI=3.14159265;
typedef long long LL;
int n;
ll a[maxn];
ll b[maxn];
struct seg
{
    int l,r;
    pair<ll,int> va;
}tree[maxn<<2];
void pushup(int rt)
{
    if(tree[rt<<1].va.first>tree[rt<<1|1].va.first) tree[rt].va=tree[rt<<1|1].va;
    else tree[rt].va=tree[rt<<1].va;
}
void build(int rt,int l,int r)
{
    tree[rt].l=l;tree[rt].r=r;
    if(l==r){
        tree[rt].va=make_pair(a[l],l);
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
pair<ll,int> query(int rt,int L,int R)
{
    if(tree[rt].l>=L&&tree[rt].r<=R){
        return tree[rt].va;
    }
    int mid=(tree[rt].l+tree[rt].r)>>1;
    pair<ll,int> t1={1000000000,1},t2={1000000000,1};
    if(mid>=L) t1=query(rt<<1,L,R);
    if(mid<R) t2=query(rt<<1|1,L,R);
    if(t1.first>t2.first) return t2;
    else return t1;
}
ll solve(int l,int r)
{
    if(l>r) return 0ll;
    if(l==r) {b[l]=a[l];return a[l];}
    pair<ll,int> mi=query(1,l,r);
    int pos=mi.second;
    ll sum1=solve(l,pos-1);
    ll sum2=solve(pos+1,r);
    if(sum1+mi.first*(r-pos+1)*1ll>sum2+mi.first*(pos-l+1)*1ll){
        for(int i=pos;i<=r;i++) b[i]=mi.first;
        return sum1+mi.first*(r-pos+1)*1ll;
    }
    else {
        for(int i=l;i<=pos;i++) b[i]=mi.first;
        return sum2+mi.first*(pos-l+1)*1ll;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    ll tmp=solve(1,n);
    for(int i=1;i<=n;i++) printf("%lld%c",b[i],i==n?'\n':' ');
    return 0;
}
