/*Author: Pratik Kenaudekar
Date Created: 12th February 2018
Date Modified: 12th February 2018
Program: WAP to implement Cp
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
	int srcFD,destFD,nbread,nbwrite;
	char *buff[BUFF_SIZE];
	
	if(argc != 3)
	{
		printf("\nUsage:./prog37.exe source_file destination_file\n");
		exit(1);
	}
 
	/*Open source file*/
	srcFD = open(argv[1],O_RDONLY);
 
	if(srcFD == -1)
	{
		printf("\nError opening file %s errno = %d\n",argv[2],errno);
		exit(1);	
	}
	
	destFD = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
 
	if(destFD == -1)
	{
		printf("\nError opening file %s errno = %d\n",argv[2],errno);
		exit(1);
	}
 
	while((nbread = read(srcFD,buff,BUFF_SIZE)) > 0)
	{
		if(write(destFD,buff,nbread) != nbread)
			printf("\nError in writing data to %s\n",argv[2]);
	}
	
	if(nbread == -1)
		printf("\nError in reading data from %s\n",argv[1]);
	
	if(close(srcFD) == -1)
		printf("\nError in closing file %s\n",argv[1]);
 
	if(close(destFD) == -1)
		printf("\nError in closing file %s\n",argv[2]);
 
	exit(1);
}
