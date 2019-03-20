/*Author: Pratik Kenaudekar
Date Created: 12th February 2018
Date Modified: 12th February 2018
Program: WAP to remove a file or a directory with rename function
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>

void main()
{
	char path[50];
	if(mkdir("ABC",0777)!=0)
		perror("Error in mkdir");
	else
		printf("Directory Created\n");
	
	if(remove("ABC")!=0)
		perror("Error in remove");
	else
		printf("Deleted");
}
