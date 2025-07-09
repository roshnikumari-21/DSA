#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long int
#define cnt continue;
#define vpp vector<pair<long long, long long>>
#define minpq priority_queue<long long, vector<long long>, greater<long long>>
#define maxpq priority_queue<long long>
#define all(arr) arr.begin(), arr.end()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define ld long double
#define fi(i, ini, n) for (ll i = ini; i < n; i++)
#define fir(i, ini, n) for (ll i = ini; i >= n; i--)
#define dbg(x) cout << #x << " = " << x << endl;
#define testcases \
  ll t;           \
  cin >> t;       \
  while (t--)
// #define N 1000000007   1e9+7
// #define N 200005

//   bool cmp(pair<ll,ll>&a,pair<ll,ll>&b){
//  // if(a.first!=b.first) return a.first>b.first;
//    return a.second>b.second;

void solve(){
   
     
     ll n; cin>>n; 
     vector<ll>arr(n);
     fi(i,0,n) cin>>arr[i];
     vector<ll>mini(n),maxi(n);
     mini[0]=arr[0];
     fi(i,1,n){
        mini[i]=min(mini[i-1],arr[i]);
     }
     maxi[n-1]=arr[n-1];
     fir(i,n-2,0){
        maxi[i]=max(maxi[i+1],arr[i]);
        //cout<<maxi[i]<<" ";
     }

     fi(i,0,n){
        if(arr[i]==mini[i] || arr[i]==maxi[i]) cout<<1;
        else cout<<0;
     }
     cout<<endl;



}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  testcases
  {
      solve();
  }
}