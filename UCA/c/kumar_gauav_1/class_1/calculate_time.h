#include<stdio.h>
#include<sys/time.h>
#include<time.h>

// https://kaksha-dev.github.io/

int main()
{
	struct timeval before;
	gettimeofday(&before,NULL);
	long long before_millis = before.tv_sec*1000LL+before.tv_usec/1000LL;

	struct timeval after;
	gettimeofday(&after,NULL);
	long long after_millis = before.tv_sec*1000LL+before.tv_usec/1000LL;

	printf("%llu \n",after_millis - after_millis);

}