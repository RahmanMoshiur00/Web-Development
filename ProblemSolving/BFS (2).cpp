#include <bits/stdc++.h>
using namespace std;

const int mxn = 100010;
vector < pair<int,int> > adj[mxn];
bool vis[mxn];
int parent[mxn], weight[mxn];

void BFS(int x, int y)
{
    queue< pair<int,int> > qu;
    qu.push(make_pair(0, x));
    vis[x] = true;

    pair<int,int> pp;
    int u, v, w, ww;

    while(!qu.empty()){
        pp = qu.front();
        qu.pop();
        u = pp.second, w = pp.first;

        cout << "debug: " << u << endl;

        if(u == y){
            cout << "Solution is found!" << endl;
            return;
        }

        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i].first, ww = adj[u][i].second;
            if(!vis[v]){
                vis[v] = true;
                qu.push(make_pair(w+ww, v));
                parent[v] = u;
                weight[v] = w + ww;
            }
        }
    }

    cout << "No solution is found!" << endl;
}

void Solution(int x, int y)
{
    if(x == y) return;
    Solution(x, parent[y]);
    cout << parent[y] << " -> ";
}

int main()
{
    int n, m, x, y, u, v;

    cout << "Enter the source and destination nodes respectively: ";
    cin >> x >> y;

    cout << "Enter the number of edges: ";
    cin >> m;

    for(int i=0; i<mxn; i++){
        adj[i].clear();
        vis[i] = false;
        parent[i] = -1;
        weight[i] = 0;
    }

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(make_pair(v, 1));
        adj[v].push_back(make_pair(u, 1));
    }

    BFS(x, y);

    cout << "Total distance from " << x << " to " << y << ": " << weight[y] << endl;

    cout << "Solution path: ";
    Solution(x, y);
    cout << y << endl;

    return 0;
}


/*

1 2
1 3
2 4
2 5
6 3
3 7
8 3

*/
