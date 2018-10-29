#include<bits/stdc++.h>
using namespace std;

int solve(vector<pair<pair<ll,ll>,ll > > e,map<int,bool> store){
	ll md=numeric_limits<ll>:max();
	for (ll i=0;i<e.size();i++)
	 if (md<e.second && store[e[i].first.first]^store[e.first.second])
	    md=min(md,e.second);
	return md;    
}
int main(int argc,char** argv){
	int n,m,k;cin>>n>>m>>k;
	map<int,bool> store;
	vector< pair<pair <ll,ll>,ll> > e; 
 	
	 for (int i=0;i<m;i++){
 		int s,d,l;cin>>s>>d>>l;
 		e.push_back(make_pair(make_pair(s,d),l));
	 }
	
	 for (int i=0;i<k;i++){
	 	int a;cin>>a;
	 	store[a]=true;
	 }
	 cout<<solve(e,store);
	 return 0;
}
