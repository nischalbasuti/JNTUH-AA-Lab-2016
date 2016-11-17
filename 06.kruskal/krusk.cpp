#include<iostream>
#define INFINITY 999
class Kruskal{
	private:
		int graph[10][10];
		int parent[10];
		
		int find(int);
		int uni(int,int);//union
	public:
		Kruskal(int g[10][10],int num);
};

Kruskal :: Kruskal(int g[10][10], int n){
	int min;
	int mincost;
	mincost = 0;
	for(int i = 0; i < n; i++){
		parent[i] = 0;
		for(int j = 0; j < n; j++){
			graph[i][j] = g[i][j];
			std::cout << graph[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int ne = 1;
	int a,b;
	int u,v;

	while(ne < n){
		min = 999;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(graph[i][j] < min){
					min = graph[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);

		if(uni(u,v)){
			std::cout << ne 
				<< ". Edge ("<<a<<","<<b<<")="<< min 
				<< std::endl;
			ne++;
			mincost += min;
		}
		graph[a][b] = graph[b][a] = 999;
	}
	std::cout << "Minimum cost = "<<mincost << std::endl;
}

int Kruskal :: find(int i){
	while(parent[i]){
		i = parent[i];
	}
	return i;
}

int Kruskal :: uni(int i, int j){
	if(i!=j){
		parent[j] = i;
		return 1;
	}
	return 0;
}

int main(){

	int g[10][10] = {
		{0,3,1,6,0,0},
		{3,0,5,0,3,0},
		{1,5,0,5,6,4},
		{6,0,5,0,0,2},
		{0,3,6,0,0,6},
		{0,0,4,2,6,0}
	};
	int n = 6;
	Kruskal foobar(g,n);
	return 0;
}
