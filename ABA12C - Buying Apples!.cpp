//ABA12C - Buying Apples!

#include<bits/stdc++.h>

using namespace std;

#define N 100005
#define ll int // long long
#define INF 100000
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[k];
    for(ll i = 0; i < k; i++)cin >> a[i];

    ll dp[k+1];
    for(ll i = 0; i <= k; i++) dp[i] = INF;

    dp[0] = 0;

    for(ll i = 0; i <= k; i++){
        for(ll j = 0; j < k; j++){
            if(a[j] == -1) continue;
            if(j+1+i <= k && dp[i] != INF) dp[j+1+i] = min(dp[j+1+i], dp[i]+a[j]);
        }
    }

    if(dp[k] == INF) dp[k] = -1;
    cout << dp[k] << endl;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
        solve();
}