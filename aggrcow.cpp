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
bool check(int arr[],int n,int c,int d){
    int cnt=1,pre=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-pre>=d){
            cnt++;
            pre=arr[i];
        }
        if(cnt==c) return true;
    }
    return false;
}
int solve(int arr[],int n,int c){
    int low=0,high=arr[n-1]-arr[0];
    while(low<=high){
        if(low==high) return high;
        else if(high-low==1){
            if(check(arr,n,c,high)) return high;
            return low;
        }
        int mid=(low+high)>>1;
        if(check(arr,n,c,mid)) low=mid;
        else high=mid;
    }
    return high;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        if(n<c){
            cout<<0<<endl;
            continue;
        }
        sort(arr,arr+n);
        cout<<solve(arr,n,c)<<endl;
    }
}
 
