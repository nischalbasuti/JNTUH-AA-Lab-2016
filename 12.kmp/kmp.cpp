//12.knuth-morris-pratt
//
#include <iostream>
#include <cstring>
using namespace std;

void preKMP(string pattern, int f[]){
	int m = pattern.length(), k;
	f[0] = -1;

	for (int i = 1; i < m; i++){
	    k = f[i - 1];
	    while (k >= 0){
	        if (pattern[k] == pattern[i - 1])
	            break;
	        else
	            k = f[k];

	    }
	    f[i] = k + 1;
	}
}

//check whether text string contains pattern
void KMP(string pattern, string text){

	cout<<"pattern: "<<pattern<<endl;
	cout<<"text: "<<text<<endl;

    int m = pattern.length();
    int n = text.length();
    int f[m];

    preKMP(pattern, f);

    int i = 0;
    int j = 0;

    while (i < n){
        if (j == -1){
            i++;
            j = 0;
        }

        else if (text[i] == pattern[j]){
            i++;
            j++;
            if (j == m){
            	cout<<"pattern found at: "<<i-j<<endl;
                j = f[j];
            }
        }
        else
            j = f[j];
    }
}

int main(){
    string tar = "asdf wassa for the wassa asdf";
    string pat = "wassa";

    KMP(pat, tar);

    return 0;
}
