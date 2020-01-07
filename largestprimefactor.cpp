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

ll maxprimefactor(ll n){
    ll ans=-1;
    while(n%2==0){
        ans=2;
        n>>=1;
    }
    for(int i=3;i<=sqrt(n);i++){
        while(n%i==0){
            n/=i;
            ans=i;
        }
    }
    if(n>2){
        ans=n;
    }
    return ans;
}

int main(){
    ll n = 600851475143;
    cout<<maxprimefactor(n)<<endl;
    return 0;
}
