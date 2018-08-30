#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

#define lch(n) n<<2+1
#define rch(n) n<<2+2
#define chl cout<endl;
#define vc vector
#define ll long long
#define var auto

void update(vc<ll> &st,ll n,ll lo,ll hi,ll pos,ll val){
	cout<<"called"<<lo<<" "<<hi<<"  "<<n<<endl;
	if(pos<lo or pos>hi) return;
	if(lo==hi){
		cout<<"updated with value "<<val<<endl;
		cout<<st[n];
		st[n]+=val;
		cout<<st[n];return;}
	var mid=(lo+hi)>>1;
	cout<<"\n\t\t\t"<<lch(n)<<"  "<<rch(n)<<endl;
	update(st,lch(n),lo,mid,pos,val);
	update(st,rch(n),mid+1,hi,pos,val);
	st[n]=st[lch(n)]+st[rch(n)];	
	return;
}
int query(vc<ll> st,ll n,ll lo, ll hi,ll ql,ll qh){
	cout<<"called query"<<endl;
	if(qh<lo or ql>hi)
	  return 0;
	if(qh>=hi and ql<=lo)
	  return st[n];
	cout<<lo<<" "<<hi<<endl;
	var mid=(lo+hi)>>1;
	var pl=query(st,lch(n),lo,mid,ql,qh);
	var ph=query(st,rch(n),mid+1,hi,ql,qh);
	return pl+ph;
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
	//for(int i=0;i<n;i++)
	//{
		update(st,0,lo,hi,3,1);
	printTree(st);
	cout<<query(st,0,lo,hi,2,5);
	//}
	
	return 0;
}
