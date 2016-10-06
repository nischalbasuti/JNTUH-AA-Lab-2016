#include<iostream>
using namespace std;
class Activity{
public:
	Activity(float, float);
	
	float startTime;
	float finishTime;
};

Activity :: Activity(float start, float finish){
	startTime = start;
	finishTime = finish;
}

class ActivitySelection{
public:
	ActivitySelection(Activity activities[], int size){
		int j = 0;
		cout<<0<<". "<<activities[0].startTime<<" "<<activities[0].finishTime<<endl;
		for(int i = 0; i < size; i++){
			if(activities[i].startTime > activities[j].finishTime){
				cout<<i<<". "<<activities[i].startTime<<" "<<activities[i].finishTime<<endl;
				j = i;
			}
		}
	}
};

int main(){
	
	Activity activities[6] = {
							Activity(1,2),
							Activity(3,4),
							Activity(0,6),
							Activity(5,7),
							Activity(8,9),
							Activity(5,9)	
							};
	
	ActivitySelection selection(activities,sizeof(activities)/sizeof(activities[0]));
}
