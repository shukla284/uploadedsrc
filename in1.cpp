#include<bits/stdc++.h>
using namespace std;

#define rep(i,j,k) for(ll i=j;i<k;i++)
#define ll long long
#define vcii vector<int> 

int bs(vcii a,int lo,int hi,int key){
	while(hi-lo>1){
		int m=(lo+hi)/2;
		if (a[m]>=key) hi=m;
		else lo=m;
	}
	cout<<"The selected index "<<hi;
	return hi;
}
int solveEff(vcii a){
	vcii tail(a.size(),0);
	tail[0]=a[0];
	int len=1;
	rep(i,1,a.size()){
		cout<<"Iteration "<<i<<endl;
		if (tail[0]>a[i]) tail[0]=a[i];
		else if (tail[len-1]<a[i]) tail[len++]=a[i];
		else tail[bs(tail,0,len-1,a[i])]=a[i];
	}
	cout<<"Length "<<len<<endl;
    //for (auto i:tail) cout<<i<" ";
	return len;
}
int solvesh(vcii a){
	vcii tail(a.size(),0);
	int len=1;tail[0]=a[0];
	rep(i,1,a.size()){
		if (tail[len-1]<a[i]) tail[len++]=a[i];
		*upper_bound(tail.begin(),tail.begin()+len,a[i])=a[i];
	}
	return len;
}

int solve(vcii a){
	vcii dp(a.size(),1);
	/*rep(i,0,a.size()){
		int cc=1;
		rep(j,i+1,a.size())
		This aproach is not far worth in terms of finding the LIS
		this will only count the cases in which 
		
		1.Variation with difference of 1 with adjacent element
		  --counting the adjacent pairs with everyu start of i as different element
		
			if(a[j]>=a[j-1]) dp[j]=max(dp[j],++cc);
	}		
	for(auto x:dp) cout<<x<<" ";
	return *max_element(dp.begin(),dp.end());*/
	for (int i=1;i<a.size();i++){
		int cmx=0;
		for (int j=0;j<i;j++)
		   if (a[j]<a[i] && cmx<dp[j])
		      cmx=dp[j];
	    dp[i]=1+cmx;
	}
	return *max_element(dp.begin(),dp.end());
}

int main(int argc,char** argv){
	int n;cin>>n;
	vcii a(n);rep(i,0,n) cin>>a[i];
	cout<<solve(a)<<endl;
	cout<<solvesh1(a)<<endl;
	return 0;
}
