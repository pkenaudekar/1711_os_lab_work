/*Author: Pratik Kenaudekar
Date Created: 11th December 2017
Date Modified: 11th December 2017
Program: Write a Program to demonstrate that errno retains the last system call error code even after a
successful call is made 

*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>
#include<errno.h>

extern int errno;

int main()
{
	FILE *fp;
	fp=fopen("bbb.txt", "r");
	if(fp==NULL)
	{
		perror("Error");
		printf("Error no is:%d",errno);
	}
	fp=fopen("bbbb.txt", "r");
	if(fp==NULL)
	{
		perror("Error");
		
	}
	printf("\nError no after success is:%d",errno);
	fclose(fp);
	
	return 0;
}

