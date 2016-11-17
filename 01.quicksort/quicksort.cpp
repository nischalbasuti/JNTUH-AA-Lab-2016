//quicksort
#include<iostream>
#include<fstream>

class Quicksort {

protected:
	int a[20];
	int size;
	void swap(int, int);
public:
	Quicksort(int array[], int sizeTemp){
		size = sizeTemp;

		for (int i = 0; i < size; i++){
			a[i] = array[i];
		}

		display();

		quicksort(0,size-1);

		display();
		std::cout << std::endl;

	}
	void display(){
		std::cout << std::endl;
		for (int i = 0; i < size; i++){
			std::cout << a[i] << " ";
		}
	}

	void quicksort(int, int);
	int partition(int, int);
};

void Quicksort :: quicksort(int low, int high){
	if (low < high){
		//display();
		int p = partition(low, high);
		quicksort(low,p-1);
		quicksort(p+1,high);
	}
}

int Quicksort :: partition(int low, int high){
	int pValue = a[high];
	int pIndex = high;
	int j = low;

	for(int i = low; i <= high; i++){
		if(a[i] < pValue){
			swap(i,j);
			j++;
		}
	}
	swap(j,high);
	//display();
	return j;
}

void Quicksort :: swap(int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int main(){
	std::ifstream file;
	file.open("file.txt");

	int a[20];

	int temp;
	int i = 0;
	while(file>>temp){
		a[i] = temp;
		i++;
	}
	
	//std::cout << sizeof(a) << " "<< sizeof(a[0])<<std::endl;
	Quicksort foobar(a, i);
}
