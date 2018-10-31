// Problem link
// https://www.spoj.com/problems/PALIN/

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
bool allNine(string s){
    rep(i,s.length()) if(s[i]!='9') return false;
    return true;
}
string nextpalin(string s){
    if(allNine(s)){
        string ans="1";
        rep(i,s.length()-1) ans+='0';
        ans+='1';
        return ans;
    }
    else if(s.length()==1){
        s[0]++;
        return s;
    }
    int n=s.length();
    int i=n/2-1,j=n/2;
    if(n%2) i++;
    bool change=false;
    while(i>=0 && s[i]==s[j]) j++,i--;
    if(i<0 || s[i]<s[j]) change=true;
    while(i>=0){
        s[j]=s[i];
        j++;
        i--;
    }
    if(!change) return s;
    int car=1;
    j=n/2;
    (n%2)?i=n/2:i=n/2-1;
    while(i>=0){
        if(s[i]=='9' && car){
            s[i--]='0';
            s[j++]='0';
        }
        else if(car){
            car=0;
            s[i]++;
            s[j]=s[i];
            j++;
            i--;
        }
        else{
            s[j]=s[i];
            j++;
            i--;
        }
    }
    return s;
}
int main(){
    io
    int q;
    cin>>q;
    rep(test,q){
        string s;
        cin>>s;
        cout<<nextpalin(s)<<endl;
    }
}
