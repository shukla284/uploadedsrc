#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

#define lch(n) 2*n+1
#define rch(n) 2*n+2
#define chl cout<<endl;
#define vc vector
#define ll long long
#define var auto
#define repeat(i,j,s) for(ll x=i;x<j;x+=s)
#define print(x) cout<<x


/*
	Name: SkylineProblem
	Copyright: none
	Author: fucode
	Date: 03-09-18 11:51
	Description: 
	
	Algorithm
	
	**construction of the tree
	
	1.Segment tree is used for the purpose of querying the maximum height in the range
	2.Interval updation problem in which there would be update on the entire range rather than
	 at a single node.
	 encountering a single building comes with the problem of updating the information at each node,
	 therefore whenever we encounter the new building.
	3.For the interval 10**6 a segment tree can be constructed without cost incurment
	 the node at the leaves actually specify the exact position
	 [1:1],[2:2],[3:3]................[n:n]
	 the parent nodes would store the status of thier childs 
	 the store at each node is most probably
	 1.Maximum at this interval/node 
	 2.Minimum at this interval/node
	
	**finding the total overlap of the buildings
	
	1.If the present building now is the maximum in this interval it has overall coverage.
	  Otherwise simply the total interval overlap can be computed using the recursion at the chuild nodes
	2.The greater building here till now will give the clue to the overlap ....
	 The front building coverage even doesn't matters at all in the calculation of the overlap rather only 
	 the preceding buildings are responsible for this.
	
	Query part:
	  The segment tree here is the example of the Range Maximum and Range Minimum Query and along
	  with this there is continous calculations for the building overalps
	  Store this in the array /vector for further calculations otherwise a variable will work enough
	  
	  1.Query will be made aginst the interval of building i e.g,
	    [lb,rb] ::Find maximum here-Update the maximum
	   
	**calculation for the total
	
	sum(overlap_buildings(vector storing the overlap of the buildings)
*/



void update(vc<ll> &st,ll n,ll lo,ll hi,ll pos,ll val){
	
	if(n>st.size()) return;
	if(pos<lo or pos>hi) {
		return;
	}
    st[n]+=val;
    if(lo!=hi){
	var mid=(lo+hi)/2;
	update(st,lch(n),lo,mid,pos,val);
	update(st,rch(n),mid+1,hi,pos,val);
	st[n]=st[lch(n)]+st[rch(n)];	
	}
	return;
}
int query(vc<ll> st,ll n,ll lo, ll hi,ll ql,ll qh){
	if(qh<lo or ql>hi)
	  return 0;
	if(qh>=hi and ql<=lo)
	  return st[n];
	var mid=(lo+hi)>>1;
	return query(st,lch(n),lo,mid,ql,qh)+query(st,rch(n),mid+1,hi,ql,qh);
}
ll computeSize(ll n){
	var ht=ceil(log2(n));
	return 2*pow(2,ht);
}
void convert(vc<ll> &qa){
	
	vc<ll> tmp(qa);
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<qa.size();i++)
	  qa[i]=lower_bound(tmp.begin(),tmp.end(),qa[i])-tmp.begin()+1;  
}
void printTree(vc<ll> st){
	for(auto i:st) cout<<i<<" ";
}
int main(int argc,char** argv){
	ll n;cin>>n;
	vc<ll> qa(n);for(int i=0;i<n;i++) cin>>qa[i];
	convert(qa);
	vc<ll> st(3*n,0);
	
	ll lo=0,hi=n;var ans=0;
	repeat(0,qa.size(),1){
		ans+=query(st,0,lo,hi,qa[x],n);
		update(st,0,lo,hi,qa[x],1);
	}
	print(ans);chl
	return 0;
}
