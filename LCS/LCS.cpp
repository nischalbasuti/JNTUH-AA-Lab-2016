#include<iostream>
#include<cstring>
using namespace std;

class LCS{
	private:
		char sub[10];
		int iSub;
		
		char x[10], y[10];
		
		int lcs(int, int);
		int max(int, int);
	public:
		LCS(char xTemp[], char yTemp[], int m, int n){
			iSub = 0;
			for(int i=0;i<m;i++){
				x[i] = xTemp[i];
				cout << x[i];
			}
			cout<<endl;
			for(int j=0;j<n;j++){
				y[j] = yTemp[j];
				cout << y[j];
			}
			cout<<endl;
			cout<<"length="<<lcs(m,n)<<endl;
		}	
};

int LCS :: lcs(int m, int n){
	int L[m+1][n+1];

	for(int i =0 ;i<=m ;i++) {
		for(int j =0;j<=n;j++) {
			if(i==0 || j==0){
				L[i][j] = 0;
			}
			else if(x[i-1]==y[j-1]){
				L[i][j] =  L[i-1][j-1] + 1;
			//	sub[iSub] = y[j-1];
			//	cout<<y[j-1];
			//	cout<<sub[iSub]<<endl;
			//	iSub++;
			}
			else if(x[i-1]!=y[j-1]){
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	
	return L[m][n];
}

int LCS :: max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;	
	}
}
int main(){
	char x[] = "AGGTABA";
	char y[] = "GXTXAYB";
	
	LCS foo(x,y,strlen(x),strlen(y));
	 
	return 0;
}
