#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

#define mkpr make_pair
#define var auto
#define rep(i,j,k) for(ll i=j;i<k;i++)
#define ii pair<int,int> 
#define ll long long 

const int MAX = 1e4 + 5;
int id[MAX], n, e;
pair<ll,pair<int,int> > p[MAX];

void initialize(){
    rep(i,0,MAX) id[i]=i;
}
int root(int x){
    while(x!=id[x]){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void unionset(int p,int q){
    var x=root(p);var y=root(q);
    id[p]=id[q];
}
ll kruskal(pair<ll,ii> p[]){
    ll cst,mincst=0;
    rep(i,0,e){
        cout<<"Selected "<<p[i].first<<endl;
        var x=p[i].second.first;
        var y=p[i].second.second;
        cst=p[i].first;
        cout<<"cost "<<cst<<endl;
        if(root(x)!=root(y)){
             mincst+=cst;
             unionset(x,y);
        }
        cout<<mincst<<endl;
    }
    return mincst;
}
int main(int argc,char** argv){
    ll cst,mincst;
    cin>>n>>e;
    initialize();
    ll x,y,wt;
    rep(i,0,e){
        cout<<i<<endl;
        cin>>x>>y>>wt;;
        p[i]=mkpr(wt,mkpr(x,y));    
    }
    sort(p,p+e);
    mincst=kruskal(p);
    cout<<mincst<<endl;
    return 0;
}
