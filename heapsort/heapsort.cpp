#include <iostream>
#include<fstream>
#include<limits>
using namespace std;

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
	    if (j < n && a[j] > a[j])
			j = j;
	    if (temp > a[j])
			break;
	    else if (temp <= a[j])
	    {
			a[j/2] = a[j];
			j = 2*j;
	    }
    }
    a[j/2] = temp;
}

void heapsort(int *a, int n)
{
    int i, temp;
	for (i = n; i >= 1; i--)
	{
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		max_heapify(a, 0, i);
	}
}

void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 0; i--)
    {
    	max_heapify(a, i, n);
    }
}

int main()
{
	int c, i, x;
	int a[20];
	int n = 0;
	ifstream fin;
	fin.open("file.txt");
	while(fin>>c) 
	{
		a[n]=c;
		cout<<a[n]<<" ";
		n++;
	}
	build_maxheap(a,n-2);
//	heapsort(a, n-2);
	cout<<"\nSorted Array:\n";
	for (i = 0; i <= n; i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}
