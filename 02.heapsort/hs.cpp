#include<iostream>
void max_heapify(int arr[],int n, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	//left is larger than root
	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	//if right is larger than largest
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}
	//if largest is not the root
	if(largest != i){
		std::swap(arr[i],arr[largest]);
		//heapify the effected subtree
		max_heapify(arr,n,largest);
	}
}

void heapsort(int arr[], int n){
	for(int i = n/2; i >= 0; i--){
		max_heapify(arr, n, i);
	}

	for(int i = n-1 ; i >= 0; i--){
		std::swap(arr[0], arr[i]);
		max_heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n){
	for (int i=0; i<n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(){
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	heapsort(arr, n);

	std::cout << "Sorted array is \n";
	printArray(arr, n);
}
