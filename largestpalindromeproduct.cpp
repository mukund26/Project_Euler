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

bool palindrome(int n){
    int x=n;
    int r=0;
    while(n>0){
        r=(r*10)+(n%10);
        n=n/10;
    }
    //cout<<x<<"-"<<r<<endl;
    return (r==x);
}

int main(){
    int ans,m=-1;
    for(int i=999;i>=100;i--){
        for(int j=999;j>=100;j--){
            ans=i*j;
            if(palindrome(ans) && m<ans){
                m=ans;
            }
        }
    }
    cout<<m<<endl;
	return 0;
}
