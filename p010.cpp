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
 
int main(){
    int n=2000000;
    vector<int> prime(n+1,0);
    prime[0]=prime[1]=1;
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i]==0){
            for(int j=2;i*j<=n;j++){
                prime[i*j]=1;
            }
        }
    }
    long long ans=0;
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            ans+=i;
        }
    }
    cout<<ans<<endl;
	return 0;
}
