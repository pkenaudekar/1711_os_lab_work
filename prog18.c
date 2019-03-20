/*Author: Pratik Kenaudekar
Date Created: 17th January 2018
Date Modified: 17th January 2018
Program: WAP to display the user permision bits.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{
		if(argc !=2)
		{
			printf("usage: a.out <pathname>");
			exit(1);
		}
		if(access(argv[1],R_OK)<0)
			perror("access error");
		else
			printf("read access OK\n");
		if(access(argv[1],W_OK)<0)
			perror("access error");
		else
			printf("write access OK\n");
		exit(0);
}
