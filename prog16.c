/*Author: Pratik Kenaudekar
Date Created: 17th January 2018
Date Modified: 17th January 2018
Program: WAP to check the type of the file.

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
		if(S_ISREG(buf.st_mode))
			ptr=" regular";
		else if(S_ISDIR(buf.st_mode))
			ptr=" directory";
		else if(S_ISCHR(buf.st_mode))
			ptr=" character special";
		else if(S_ISBLK(buf.st_mode))
			ptr=" block special";
		else if(S_ISFIFO(buf.st_mode))
			ptr=" fifo";
		else if(S_ISLNK(buf.st_mode))
			ptr=" symbolic link";
		else if(S_ISSOCK(buf.st_mode))
			ptr=" socket";
		else
			ptr="**unknown mode**";
			printf("%s\n",ptr);
	}
	exit(0);
}
