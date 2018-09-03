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

//Lazy propagation technique for the interval updation

void applyPendingUpdate(vc<ll> &lazy,ll n,ll lo, ll hi){
	if(not lazy[n]==0){
		st[n]+=(hi-lo+1)*lazy[n];
		if(not lo==hi){
			lazy[lch(n)]+=lazy[n];
			lazy[rch(n)]+=lazy[n];
		}
		lazy[n]=0;
	}
	return;
}
void updateRange(vc<ll> &st,ll n,ll lo,ll hi,ll us,ll ue,ll val,vc<ll> &lazy){
	applyPendingUpdate(lazy,n,lo,hi);
	if(st.size()<n or lo>ue or hi<us) return;
	if(us<=ss and se<=ue){
		st[n]+=(hi-lo+1)*val;
     	if(not lo==hi){
		   st[lch(n)]+=val;
		   st[rch[n]]+=val;
	    }
	return;
	}
	var mid=(lo+hi)/2;
	updateRange(st,lch(n),lo,mid,us,ue,val,lazy);
	updateRange(st,lch(n),lo,mid,us,ue,val,lazy);

	st[n]=st[lch(n)]+st[rch(n)];
}
ll queryRange(vc<ll> st,ll n,ll lo, ll hi, ll ql,ll qh,vc<ll> &lazy){
	
	applyPendingUpdate(lazy,n,lo,hi);
	if(ql>hi or qe<lo) return 0;
	if(ql>=lo and qh<=hi) return st[n];
	
	var mid=(lo+hi)/2;
	var pl=queryRange(st,lch(n),lo,mid,ql,qh,lazy);
	var pr=queryRange(st,rch(n),mid+1,hi,ql,qh,lazy);
	return pl+pr;
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
	
}
