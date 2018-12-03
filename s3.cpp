#include<bits/stdc++.h>
using namespace std;

struct e{int i,j,k,q;};
vector<int> fen(30010);
vector<e> a(230000);

bool cmp(const e &a,const e &b){
    if (a.k==b.k) return a.j>b.j;
    return a.k>b.k;	
}
int getnext(int c){return c+(c&-c);};
int getparent(int c){return c-(c&-c);};

void update(int idx,int val,int n){
     while (idx<=n) {
        fen[idx]+=val;idx=getnext(idx);	
     }	
}
int query(int idx){
     int sum=0;
     while (idx>0){
         sum+=fen[idx];
         idx=getparent(idx);	
     }
     return sum;	
}

int main(int argc,char** argv){
     int n,qu;cin>>n;
     for (int m=0;m<n;m++){
        int i,j,k,q;
        i=m+1;j=-1;cin>>k;q=-1;a[m]=e{i,j,k,q};	
     } 
     cin>>qu;vector<int> res(qu);
     for (int m=0;m<qu;m++){
        int i,j,k,q;
        cin>>i>>j>>k;q=m;	
        a[n+m]=e{i,j,k,q};
     }
     sort(a.begin(),a.begin()+qu+n,cmp);
     for (int x=0;x<n+qu;x++)
        if (a[x].q==-1)
          update(a[x].i,1,n);
        else 
          res[a[x].q]=query(a[x].j)-query(a[x].i-1);  	
     
     for (int i=0;i<res.size();i++) cout<<res[i]<<endl;
     return 0; 
} 
