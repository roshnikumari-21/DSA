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

void sorti(vector<int>&arr){
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return;

}

void solve(){

    ll n; cin>>n;

    vector<vector<int>>arr(n,vector<int>(n));
    fi(i,0,n){
        fi(j,0,n){
            cin>>arr[i][j];
        }
    }


    fi(i,0,n){
        if(i%2==0){
             sorti(arr[i]);
        }
        else {
            sorti(arr[i]);
            
        }
       
    }

    fi(j,0,n){
        vector<int>temp;
        fi(i,0,n){
            temp.push_back(arr[i][j]);
        }
        if(j%2==0)  sort(temp.rbegin(),temp.rend());

        else sort(temp.begin(),temp.end());
          fi(i,0,n){
            arr[i][j]=temp[i];
        }

    }
    

     fi(i,0,n){
        fi(j,0,n){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
   
     
     
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
//   testcases
//   {
      solve();
 // }
}