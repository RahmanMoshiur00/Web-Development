#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n+1];
    for(int i=1; i<=n; i++) cin >> arr[i];

    int dp[n+1], mx;

    mx = dp[n] = arr[n];
    for(int i=n-1; i>=1; i--){
        if(i+arr[i]<=n) dp[i] = arr[i] + dp[i+arr[i]];
        else dp[i] = arr[i];

        mx = max(mx, dp[i]);
    }

    cout << mx << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

