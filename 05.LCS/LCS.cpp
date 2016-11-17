//05.LCS
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

	//finding length of subsequence and indeces to trace
	for(int i = 0 ; i<=m ; i++) {
		for(int j = 0; j<=n; j++) {
			if(i==0 || j==0){
				L[i][j] = 0;
			}
			else if(x[i-1]==y[j-1]){
				L[i][j] =  L[i-1][j-1] + 1;
			}
			else if(x[i-1]!=y[j-1]){
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}

	//tracing sub sequence
	iSub = L[m][n];
	sub[iSub] = '\0';
	iSub--;
	int i = m;
	int j = n;

	while(i>>0 && j>>0){
		if(x[i-1]==y[j-1]){
			sub[iSub] = x[i-1];
			i--;
			j--;
			iSub--;
		}
		else if(L[i-1][j] > L[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}

	cout<<"LCS is: "<<sub<<endl;

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
