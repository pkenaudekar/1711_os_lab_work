/*Author: Pratik Kenaudekar
Date Created: 17th January 2018
Date Modified: 17th January 2018
Program: WAP to display whether the file name exists or not.

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
    if (access(file_name, F_OK) != -1) 
	{
		printf ("%s exists", file_name);
	}
	else
	{
		printf ("%s does not exists", file_name);
	}
    exit(0);
}
