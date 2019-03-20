/*Author: Pratik Kenaudekar
Date Created: 17th January 2018
Date Modified: 17th January 2018
Program: WAP to display user and group user id for a given file.

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
	struct stat sb;
    const char * file_name;
    file_name = argv[1];
	stat(file_name, &sb);
    printf("original owner was %d and group was %d\n", sb.st_uid,
           sb.st_gid);
    exit(0);
}
