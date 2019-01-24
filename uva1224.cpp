/*
Start where you are
Use what you have
Do what you can....I can and I will.
*/
#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define mapii map<int,int>
#define mapib map<int,bool>
#define mapiv map<int,vector>
#define rep(i,j,k) for(ll i=j;i<k;i++)
#define reps(i,j,k,s) for(ll i=j;i<j;i+=s)
#define down(i,j,k) for(ll i=j;i>k;i--)
#define downs(i,j,k,s) for(ll i=j;i>k;i-=s)
#define trv(i,v) for(auto i:v)
#define pb push_back
#define vc vector
#define ii pair<int,int>
#define mkp make_pair
#define null NULL
#define ordered_set oset
#define ff first
#define ss second
#define beg begin
#define vvi vc<vi>
#define vvl vc<vl>
#define vvs vc<vs>

const int maxn=32;

vl tot_ways(33),sym_ways(33);

void calc_total_ways(){
	tot_ways[0]=1;tot_ways[1]=1;tot_ways[2]=3;
	rep(i,3,33) tot_ways[i]=(tot_ways[i-2]<<1)+tot_ways[i-1];
}
void calc_symmetrical_ways(){
	sym_ways[0]=1;sym_ways[1]=1;sym_ways[2]=3;sym_ways[3]=1;
	rep(i,4,33) sym_ways[i]=(i&1)?tot_ways[i>>1]:sym_ways[i-2]+(sym_ways[i-4]<<1);
}
int main(int argc,char** argv){
   int t;cin>>t;
   calc_total_ways();
   calc_symmetrical_ways();
   
   while(t--){
   	  ll n;cin>>n;
   	  ll sym_way=sym_ways[n],tot_way=tot_ways[n];
   	  ll req=((tot_way-sym_way)>>1)+sym_way;
   	  cout<<req<<endl;
   }
   return 0;
}

