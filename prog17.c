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
	int i;
	struct stat buf;
	char *ptr;
	for(i=1;i<argc;i++)
	{
		printf("%s", argv[i]);
		if(stat(argv[i],&buf)<0)
		{
			perror("stat error");
			continue;
		}
		if(buf.st_mode & S_IRUSR)
			printf(" user read enabled");
		else	
			printf(" user read disabled");
	}
	exit(0);
}
