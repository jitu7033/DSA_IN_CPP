#include<stdio.h>


void binary_search(int arr,int n){
	int l = 0;
	int r = n-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(arr[mid]==target){
			printf("%d",mid);
			return;
		}
		if(arr[mid]<target){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
}

int main(){

}