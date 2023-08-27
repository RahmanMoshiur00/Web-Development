#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 1 )

#define mxn           200010


int tree[4*mxn];
int cnt[mxn], ans = 0;

void propagate(int idx, int l, int r)
{
    if(l != r){
        int left = idx << 1;
        int right = left + 1;
        tree[left] = tree[right] = tree[idx];
        tree[idx] = -1;
    }
}

void update(int idx, int l, int r, int i, int j, int q)
{
    if(tree[idx] != -1) propagate(idx, l, r);

    if(r<i || l>j) return;
    if(l>=i && r<=j){
        tree[idx] = q;
        propagate(idx, l, r);
        return;
    }

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    update(left, l, mid, i, j, q);
    update(right, mid+1, r, i, j, q);
}

void query(int idx, int l, int r)
{
    if(tree[idx] != -1) propagate(idx, l, r);

    if(l==r){

        if(tree[idx] == -1) return; // because queries may not end at 2*n, in that case tree[idx] == -1

        if(cnt[tree[idx]] == 0) ans++;
        cnt[tree[idx]]++;
        return;
    }

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    query(left, l, mid);
    query(right, mid+1, r);
}

void solve(int tc)
{
    int n, l, r; sfi(n);

    MINUS(tree), ZERO(cnt);

    rep(i, 0, n){
        sfi2(l, r);
        update(1, 1, 2*n, l, r, i+1);
    }

    ans = 0;

    query(1, 1, 2*n);

    pfs("Case "), pfi(tc), pfs(": "), pfin(ans);
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

