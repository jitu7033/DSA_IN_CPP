#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	srand(time(NULL)); // if you are running this every time every time get random number 
	// if you are not running then you have given every time same output 
	for(int i = 0; i < 10; i++)printf("%d \n",rand());
}