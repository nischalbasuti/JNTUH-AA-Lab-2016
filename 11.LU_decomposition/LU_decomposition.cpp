//LU Decomposition
//
#include<iostream>
using namespace std;

class LUD{
	int L[20][20], U[20][20], a[20][20];
	int n;

	void displayMatrix(int a[20][20]);

	public:
	LUD(int a[20][20], int m);
};

LUD :: LUD(int q[20][20], int m){
	n = m;

	//initializing L, U and a
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			L[i][j] = 0;
			U[i][j] = 0;
			a[i][j] = q[i][j];
		}
	}

	//calculating L and U
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j < i){
				L[j][i] = 0;
			}
			else{
				L[j][i] = a[j][i];
				for(int k = 0;k < i;k++){
					L[j][i] = L[j][i] - L[j][k] * U[k][i];
				}
			}
		}
		for(int j = 0;j < n;j++){
			if (j < i){
				U[i][j] = 0;
			}
			else if (j == i){
				U[i][j] = 1;
			}
			else{
				U[i][j] = a[i][j] / L[i][i];
				for (int k = 0; k < i; k++){
					U[i][j] = U[i][j] - ((L[i][k] * U[k][j]) / L[i][i]);
				}
			}
		}

	}
	int mult[20][20];
	for(int i=0; i < n; i++){
		for(int j=0; j < n;j++){
			mult[i][j] = 0;
		}
	}

	//displaying a, L and U
	cout << "\na:";
	displayMatrix(a);

	cout << "\n\nL:";
	displayMatrix(L);

	cout << "\n\nU:";
	displayMatrix(U);

}
void LUD :: displayMatrix(int m[20][20]){
	cout<<"\n.....";
	for(int i = 0; i < n; i++){
		cout<<"\n";
		for(int j = 0; j < n; j++){
			cout<<m[i][j]<<" ";
		}
	}
}

int main(){
	int a[20][20] = {
					{4,5,6},
					{1,2,3},
					{7,8,9}
				};
	LUD lud(a,3);

	cout << endl;
	return 0;
}
