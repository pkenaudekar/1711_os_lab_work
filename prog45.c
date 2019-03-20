/*Author: Pratik Kenaudekar
Date Created: 14th February 2018
Date Modified: 14th February 2018
Program: WAP to implement utime
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
    struct stat s;
	struct utimbuf t;
	char b[100];
	stat("a",&s);
	printf("last access time of file a is %ld\n",s.st_atime);
	printf("last access time of file a (formated) %s\n",ctime(&s.st_atime));
	printf("last access time of file a is %ld\n",s.st_atime);
	printf("last access time of file a (formated) %s\n",ctime(&s.st_atime));
	stat("b",&s);
	t.actime=s.st_atime;
	t.modtime=s.st_mtime;  
	if(utime("a",&t)<0)
		perror("error");
	else
	{
		stat("a",&s);
		printf("After using utime\n");
		printf("last access time of file a is %s\n",ctime(&s.st_atime));
		printf("last modified time of file a is %s\n",ctime(&s.st_mtime));
	}
}

