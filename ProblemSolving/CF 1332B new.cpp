#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long intu;
typedef long long int intl;
//-----------------directions-----------------//
// int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction
// int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
// int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
// int dx[]={2,1,-1,-2,-1,1}; int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//-------------------debug--------------------//
#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define FastRead        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define OUTPUT          freopen("output.txt","w",stdout);
#define INPUT           freopen("input.txt","r",stdin);
//------------------policy DS--------------------//
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//------------------print--------------------//
#define int             long long
#define pfi(a)          printf("%lld", (intl)a)
#define pfin(a)         printf("%lld", (intl)a), printf("\n")
#define pfis(a)         printf("%lld", (intl)a), printf(" ")
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define pfsn(a)         printf("%s", a), printf("\n")
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '
//------------------input--------------------//
#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)
//-------------------loop-------------------//
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
//--------------initialization--------------//
#define ZERO(a)         memset(a, 0, sizeof(a))
#define MINUS(a)        memset(a, 0xff, sizeof(a))
#define setval(a, v)    for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
//-------------------misc.------------------//
#define all(a)          a.begin(), a.end()
#define max3(a, b, c)   max(a,max(b,c))
#define min3(a, b, c)   min(a,min(b,c))
#define INF             1000000007
#define debug           if( 0 )

const int mxn = 100010;

vector<int> Factors(int x)
{
    vector<int> f;
    for(int j=2; j<=sqrt(x); j++){
        if(x%j==0){
            f.push_back(j);
            while(x%j==0) x /= j;
        }
    }
    if(x>1) f.push_back(x);

    return f;
}

void solve(int tc)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> adj[mxn];
    for(int i=0; i<n; i++){
        vector<int> v = Factors(arr[i]);
        for(auto &f : v) adj[f].push_back(i);
    }

    int m = 0, ans[n]; MINUS(ans);
    bool vis[mxn]; ZERO(vis);
    for(int i=0; i<n; i++){

        int x = arr[i];
        vector<int> v;
        for(int j=2; j<=sqrt(x); j++){
            if(x%j==0){
                if(!vis[j]) v.push_back(j);
                while(x%j==0) x /= j;
            }
        }
        if(x>1 && !vis[x]) v.push_back(x);

        for(auto &f : v){
            m++;
            vis[f] = true;
            for(auto &x : adj[f]) if(ans[x] == -1) ans[x] = m;
        }
    }

    cout << m << endl;
    for(int i=0; i<n; i++) cout << ans[i] << ' '; cout << '\n';

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ans[i]==ans[j] && __gcd(arr[i], arr[j])==1){
                cout << "Error: " << i << ' ' << j << endl;
            }
        }
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

