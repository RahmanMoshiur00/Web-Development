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
#define debug         if( 0 )

const int mxn = 100010;

vector<string> str, rem;

bool cmp(string a, string b)
{
    if(a.size() == b.size()) return (a < b);
    else return (a.size() < b.size());
}

string remaining_string(string s)
{

    stack<char> st;
    int sz = s.length();
    rep(i, 0, sz){
        if(s[i]=='(') st.push('(');
        else{
            if(!st.empty() and st.top()=='(') st.pop();
            else st.push(')');
        }
    }

    string ret;
    char last;
    bool isSame = true;

    if(!st.empty()) ret += st.top(), last = st.top(), st.pop();
    while(!st.empty()){
        ret += st.top();
        if(last != st.top()) isSame = false;
        st.pop();
    }

    debug cout<<"main: "<<s<<"      "<<"rem: "<<ret<<endl;

    string tmp = "-1";
    if(isSame){
        reverse(all(ret));
        return ret;
    }
    else{
        return tmp;
    }
}

void solve(int tc)
{
    int n; cin>>n;
    str.resize(n);

    rep(i, 0, n) cin>>str[i];

    int blank = 0;
    string temp;
    rep(i, 0, n){
        temp = remaining_string(str[i]);
        if(temp == "-1") continue;
        else if(temp.size()) rem.push_back(temp);
        else blank++;
    }

    sort(all(rem), cmp);

    debug cout<<"debugging:: "<<endl;
    debug rep(i, 0, rem.size()) cout<<rem[i]<<endl;

    int ans = blank / 2, sz = rem.size(), last = 0;
    bool taken[sz]; ZERO(taken);
    for(int i=0; i<sz; i++){
        if(taken[i]) continue;
        int szi = rem[i].size(), j;
        bool ok = false;
        for(j=last+1; j<sz and rem[j].size() == szi; j++){
            if(rem[i] != rem[j] and !taken[j]){
                taken[i] = taken[j] = true;
                ans++;
                last = j;
                ok = true;
                debug cout<<"valid:: "<<rem[i]<<"  "<<rem[j]<<endl;
                break;
            }
        }
        if(!ok){
            i = j-1;
            last = i;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    FastRead
    solve(1);
    //int tc; sfl(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}
