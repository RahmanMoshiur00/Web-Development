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

    int sum = 0;
    for(int k=3; k<=n; k++){
        sum = 0;
        sum += (4*k - 4) * (4*k - 7);
        sum += (4*k - 8) * (4*k - 13);
        if(k>=4) sum += (k*k - 8*k + 12) * (k*k - 8*k + 3);
        sum /= 2;
        cout << "k=" << k << " " << sum << endl;
    }


}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}
