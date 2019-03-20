/*Author: Pratik Kenaudekar
Date Created: 12th February 2018
Date Modified: 12th February 2018
Program: WAP to implement Ls(without -l option)
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>

void main(int argc, char *argv[])
{
	struct dirent **namelist;
	int n;
	if(argc < 1)
	{
		exit(1);
	}
	else if (argc == 1)
	{
		n=scandir(".",&namelist,NULL,alphasort);
	}
	else
	{
		n = scandir(argv[1], &namelist, NULL, alphasort);
	}
	if(n < 0)
	{
		perror("scandir");
		exit(1);
	}
	else
	{
		while (n--)
		{
			printf("%s\n",namelist[n]->d_name);
			free(namelist[n]);
		}
		free(namelist);
	}
	
}
