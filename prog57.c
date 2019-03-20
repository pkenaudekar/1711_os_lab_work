/*Author: Pratik Kenaudekar
Date Created: 19th February 2018
Date Modified: 19th February 2018
Program: WAP to implement fork1
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>
#include <sys/types.h>
#include <utime.h>

void main()
{
   pid_t p1;
   p1=fork();
   if(p1<0)
	   printf("Fork error\n");
   if(p1>0)
	   printf("\nParent process\n");
   else
	   printf("\nChild process\n");
}

