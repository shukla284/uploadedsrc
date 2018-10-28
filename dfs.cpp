#include<bits/stdc++.h>
using namespace std;

#define pb push_back
enum col{white,grey,black};

void dfs(map<int,vector<int> > g,int v,vector<col> &color){
	cout<<"Vertex Encountered "<<v<<endl; 
	color[v]=grey;
	for (auto i:g[v])
	     if (color[i]==white) dfs(g,i,color);
	color[v]=black;     
}
int visitTimes(map<int,vector<int> > g,vector<int> st,vector<int> et,int v,vector<col> &color,int &time){
	cout<<"The vertex encountered "<<v<<endl;
	st[v]=time++;
	cout<<"The vertex "<<v<<" entered "<<time;
	color[v]=grey;
	
	for (auto x:g[v])
		if (color[x]==white) visitTimes(g,st,et,x,color,time);
	
	color[v]=black;
	cout<<"The vertex "<<v<<" exited "<<time;
	et[v]=time++;
}
int main(int argc,char** argv){
	int v,e;cin>>v>>e;
	map<int,vector<int> > g;
	for (int i=0;i<e;i++){
		int s,d;cin>>s>>d;
		g[s].pb(d);g[d].pb(s);
	}
	vector<col> color(v,white);	
	//visiting times
	int time=0;
	vector<int> st(v,time),et(v,time);
	visitTimes(g,st,et,0,color,time);

	return 0;
}
