//13.Rabin Karp
//
#include<iostream>
#include<cstring>


void rabinKarp(char pattern[], char text[]){
	std::cout << "pattern: "<< pattern << std::endl;
	std::cout << "text: " << text << std::endl;

	int i, j;
	int m = strlen(pattern);
	int n = strlen(text);

	int p = 0; //hashvalue of pattern
	int t = 0; //hashvalue of text

	int h = 1;

	int q = 101; //a prime number
	int d = 256; //number of characters in language

	for (i = 0; i < m -1; i++) {
		h = (h*d)%q;
	}

	//calculating hashvalue of pattern and first window of text
	for (i = 0; i < m; i++) {
		p = (d*p + pattern[i])%q;
		t = (d*t + text[i])%q;
	}

	//moving pattern over by 1
	for (i = 0; i <= n - m; i++) {
		//checknig hash values
		if(p == t){
			//checking if pattern matches
			for (j = 0; j < m; j++) {
				//if a character doesn't match, exit loop
				if(text[i+j] != pattern[j]){
					break;
				}
			}	
			//if all characters match, index found
			if(j == m){
				std::cout << "pattern found at: "<< i << std::endl;
			}
			
		}

		//calculate hash for next window of text
		if(i< n-m){
			t = (d*(t - text[i]*h) + text[i+m])%q;
			if(t < 0)
				t = (t + q);
		}
	}
}	

int main(){
	char pattern[] = "wassa";
	char text[] = "wassa for the wassa";

	rabinKarp(pattern, text);

	return 0;
}
