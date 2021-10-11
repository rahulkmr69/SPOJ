#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll x, ll y,ll p)
{
    ll res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=((res%p)*(x%p))%p;
        y=y>>1;
        x=((x%p)*(x%p))%p;
    }
    return res;
}
bool isprime(ll n)
{
    if(n<2) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    else
    {
        ll z=sqrt(n);
        rep(i,z-1) if(n%(i+2)==0) return false;
        return true;
    }
}
string solve(ll n,vi &mod,vi &p)
{
    queue<ll> q;
    q.push(1%n);
    mod[1%n]=1;
    p[1%n]=1%n;
    while(true)
    {
        ll c=q.front();
        q.pop();
        if(c==0) break;
        ll c1=((10%n)*c)%n;
        ll c2=((((10%n)*c)%n)+(1%n))%n;
        if(mod[c1]==-1)
        {
            mod[c1]=0;
            p[c1]=c;
            q.push(c1);
        }
        if(mod[c2]==-1)
        {
            mod[c2]=1;
            p[c2]=c;
            q.push(c2);
        }
    }
    string s;
    ll t=0;
    while(p[t]!=t)
    {
        s.pb(mod[t]+'0');
        t=p[t];
    }
    s.pb(mod[t]+'0');
    reverse(all(s));
    return s;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vi mod(n,-1);
        vi p(n);
        rep(i,n) p[i]=i;
        string ans=solve(n,mod,p);
        cout<<ans<<endl;
    }
    return 0;
}
