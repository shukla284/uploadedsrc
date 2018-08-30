#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

#define lch(n) 2*n+1
#define rch(n) 2*n+2
#define chl cout<endl;
#define vc vector
#define ll long long
#define var auto

void update(vc<ll> &st,ll n,ll lo,ll hi,ll pos,ll val){
	
	if(pos<lo or pos>hi) return;
    st[n]+=val;
    if(lo!=hi){
	var mid=(lo+hi)>>1;
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
	return 2*pow(2,ht)-1;
}
void convert(vc<ll> &qa){
	sort(qa.begin(),qa.end());
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
	
	vc<ll> st(computeSize(n),0);
	
	ll lo=0,hi=n-1;
	for(int i=0;i<n;i++)
	{
		update(st,0,lo,hi,qa[i],1);
	}
	cout<<query(st,0,lo,hi,2,5);
	return 0;
}
