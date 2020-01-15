#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
 
int main(){
	ll perimeter = 1000;
	ll i,j,c;
	bool flag=false;
	for(i=1;i<=perimeter;i++){
		for(j=i+1;j<=perimeter;j++){
			c=perimeter-i-j;
			ll val = i*i + j*j;
			if(val==c*c){
				flag=true;
				break;
			}	
		}
		if(flag) break;
	}
	cout<<i<<" "<<j<<" "<<c<<endl;
	i*=j;
	i*=c;
	cout<<i<<endl;
	return 0;
}
