#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const ll INF = 1e9 + 5;

int main() {
    FAST
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (auto &x : v) cin >> x;

        vector<ll> dp0(n + 1, INF), dp1(n + 1, INF);
        dp1[0] = 0;

        for (ll i = 0; i < n; i++) {
            for (ll k = 1; k <= min(n - i, 2LL); k++) 
            {
                ll h=0;
                if(k==1) h=v[i];
                if(k==2) h=v[i]+v[i+1];
                dp0[i + k] = min(dp0[i + k], dp1[i] + h);
                dp1[i + k] = min(dp1[i + k], dp0[i]);
            }
        }

        cout << min(dp0[n], dp1[n]) << endl;
    }
}
