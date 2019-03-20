/*Author: Pratik Kenaudekar
Date Created: 20th February 2018
Date Modified: 20th February 2018
Program: WAP to use execlp
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <utime.h>
#include <sys/wait.h>
#include <sys/times.h>

void main()
{
	struct tms t;
	clock_t ct;
	int i,sum,status,tps;
	tps=sysconf(_SC_CLK_TCK);//number of clocks tics per sector
	ct=times(&t);
	printf("\nExecution ended at: %f\n",((double)ct)/tps);
	for(i=0;i<1000000000;i++)
		sum+=i;
	if(fork()==0)
	{
		for(i=0;i<1000000000;i++)
			sum+=i;
	}
	else
	{
		wait(&status);
		ct=times(&t);
		printf("\nExecution ended at: %f",((double)ct)/tps);
		printf("\nFor parent process\ntms_utime: %f",((double) t.tms_utime)/tps);
		printf("\ntms_stime : %f",((double)t.tms_stime)/tps);
		printf("\nFor child process\ntms_cutime: %f",((double) t.tms_cutime)/tps);
		printf("\ntms_cstime : %f",((double)t.tms_cstime)/tps);
	}    
}

