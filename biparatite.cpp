#include<bits/stdc++.h>
using namespace std;

enum e{black,white,grey};

bool biparatite(map<int,vector<int> > g,int v){
    vector<e> col(v,white);
    queue<int> q;q.push(1);
    col[1]=black;
    while (!q.empty()){
        int u=q.front();q.pop();
        for (auto i:g[u]){
            if (col[i]==white){
                if (col[u]==black) col[i]=grey;
                else if (col[u]==grey) col[i]=black;
                q.push(i);
            }
            else if (col[i]!=white && col[i]==col[u])
               return false;
        }
    }
    return true;
}

int main(int argc,char** argv){
    int v,e;cin>>v>>e;
    map<int,vector<int> > g;
    for (int i=0;i<e;i++){
        int s,d;cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    cout<<biparatite(g,v);
    return 0;
}
