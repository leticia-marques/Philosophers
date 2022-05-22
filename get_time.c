#include<sys/time.h>
#include<stdio.h>

long long get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("Sec:%ld\n", time.tv_sec * 1000);
	printf("USec:%ld\n", time.tv_usec);

	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int main(void)
{
	get_time();
	return (0);
}
