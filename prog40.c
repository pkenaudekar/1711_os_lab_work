/*Author: Pratik Kenaudekar
Date Created: 12th February 2018
Date Modified: 12th February 2018
Program: WAP to implement mv
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>
#define BUFF_SIZE 100

void main(int argc, char* argv[])
{
	struct stat statbuf_src, statbuf_dest;
	char *src, *dest, *new_src, *new_dest;
	char *current_directory;

	if (argc != 3) 
	{
		fprintf(stderr, "usage: %s src dest\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	src = malloc(strlen(argv[1]) + 1);
	dest = malloc(strlen(argv[2]) + 1);
	strcpy(src, argv[1]);
	strcpy(dest, argv[2]);

	stat(src, &statbuf_src);
	stat(dest, &statbuf_dest);

	printf("\"%s\" is ", src);
	if (S_ISREG(statbuf_src.st_mode)) 
	{
		puts("a regular file");
	}
	if (S_ISDIR(statbuf_src.st_mode))
	{
		puts("a directory");
	}

	printf("\"%s\" is ", dest);
	if (S_ISREG(statbuf_dest.st_mode))
	{
		puts("a regular file");
	}
	if (S_ISDIR(statbuf_dest.st_mode))
	{
		puts("a directory");
	}

	current_directory = getenv("PWD");
	printf("current directory is \"%s\"\n", current_directory);

	new_src = malloc(strlen(src) + 1 + strlen(current_directory) + 1);
	strcpy(new_src,current_directory);
	strcat(new_src,"/");
	strcat(new_src,src);
	printf("new_src = %s\n",new_src);

	new_dest = malloc(strlen(dest) + 1 + strlen(current_directory) + 1 + strlen(src) + 1);
	strcpy(new_dest,current_directory);
	strcat(new_dest,"/");
	strcat(new_dest,dest);
	strcat(new_dest,"/");
	strcat(new_dest,src);
	printf("new_dest = %s\n",new_dest);

	if(rename(new_src,new_dest) != 0)
	{
		fprintf(stderr,"rename failed with error %s\n",strerror(errno));
	}

	free(new_src);
	free(new_dest);
	free(src);
	free(dest);

	exit(EXIT_SUCCESS);
}
