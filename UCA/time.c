#include<stdio.h>
#include<time.h>

int main(){
	clock_t  start_time;
	clock_t end_time;
	start_time = clock();
	
	// write your code to check how much time taken by your code in sec 

	end_time = clock();
	float time = (end_time-start_time)/CLOCKS_PER_SEC;
	printf("%fsec",time );
}
