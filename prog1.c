/*Author: Pratik Kenaudekar
Date Created: 11th December 2017
Date Modified: 11th December 2017
Program:  Write a program to list out all the system call errors

*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>
#include<errno.h>

extern int errno;
extern int sys_nerr;

int main()
{
	int i;
	for (i = 0; i < sys_nerr; ++i)
	{
		fprintf(stdout, "Error %d : %s\n", i, strerror(i));
	}
	return 0;
}

