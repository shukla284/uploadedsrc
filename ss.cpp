#include<bits/stdc++.h>
using namespace std;

enum e{white,grey,black};

void dfs(int v,map<int,vector<int> > g,int m,vector<e> &col,vector<int> cnct,vector<int> cp,int np){
	if (g[v].size()==1 && cnct[v]<=m) np++;
	col[v]=grey;
	for (int i=0;i<g[v].size();i++){
		if (col[g[v][i]]==white){
			cnct[i]=(cp[i]==1)?cnct[v]+1:0;
			if (cnct[i]<=m) dfs(g[v][i]);
		}
	} 
	col[v]=black;
}
int solve(int n,map<int,vector<int> > g,int m,vector<int> cp){
	int v=0;
	vector<e> col(n,white);
	vector<int> cnct(n);
	cnct[0]=cp[0];
	int np=0;
	dfs(v,g,m,col,cnct,cp,np);
}
int main(int argc,char** argv){
	int n,m;cin>>n>>m;
	vector<int> cp(n);  
	map<int,vector<int> > g;
	for (int i=0;i<n;i++) cin>>cp[i];
	for (int i=0;i<n-1;i++){
		int s,d;cin>>s>>d;
		g[s].push_back(d);g[d].push_back(s);
	} 
	cout<<solve(n,g,m,cp);
	return 0;
}
