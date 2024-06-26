#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
 
int scan(){
	register int c = getchar_unlocked();
	register int n = 0;
	register int neg=0;
	for( ; ((c<48 || c>57)&&c!='-'); c = getchar_unlocked() );
	if(c=='-') {
		neg=1; c=getchar_unlocked();
	}
	for( ; (c>47 && c<58); c = getchar_unlocked() ){
		n = (n<<1) + (n<<3) +c -48;
	}
	if(neg) return -n;
	else return n;
}

bool isprime(int n){
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void solve(){
	int n=2;
	int val=0;
	while(val!=10001){
		if(isprime(n)){
			val++;
		}
		n++;
	}
	cout<<n-1<<endl;
}
 
int main(){
    solve();
	return 0;
}
