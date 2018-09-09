#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

#define pb push_back
#define ll long long 
#define vc vector
#define mkpr make_pair
#define rep(i,j,k) for(ll i=j;i<k;i++)

const int MAX = 1e4 + 5;
typedef pair<long long, int> pll;
bool marked[MAX];
vector <pll> adj[MAX];

ll prim(int s){
    priority_queue<pll,vc<pll>,greater<pll> > q;
    int next;ll mincst=0;pll p;
    q.push(mkpr(0,s));
    while(!q.empty()){
        p=q.top();q.pop();
        s=p.second;
        if(marked[s]) continue;
        mincst+=p.first;marked[s]=true;
        rep(i,0,adj[s].size()){
            next=adj[s][i].second;
            if(marked[next]==false)
                  q.push(adj[s][i]);
        }
    }
    return mincst;
}
int main(int argc,char** argv){
    int v,e,x,y;
    ll wt,mincst;cin>>v>>e;
    rep(i,0,e){
        cin>>x>>y>>wt;
        adj[x].pb(make_pair(wt,y));
        adj[y].pb(make_pair(wt,x));
    }
    mincst=prim(1);
    cout<<mincst;
    return 0;
}
