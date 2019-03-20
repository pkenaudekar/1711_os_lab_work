/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: WAP to count the frequency of a given word.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{
	int i=0,j,count = 0,word=0;
	ssize_t bytes_read;
	char buff[1000],temp[1000], *pch;
	if(argc !=3)
	{
		write(1,"\nInvalid no of arguments\nusage: ./prog15.exe filename1 serchfor",100);
		exit(-1);
	}
	int file1 = open(argv[1], O_RDONLY);
	if (file1 < 0) 
	{
		perror("error");
		exit(1);
	}
	bytes_read = read(file1, buff, sizeof(buff));
	while(1)
	{
		pch = strstr (buff,argv[2]);
		if(pch)
		{
			strncpy (pch,"$",1);
			word++;
		}
		else 
		{
			break;
		}		 
	}
	printf("\n'%s' has occured %d times",argv[2],word);
	close(file1);
	
	exit(0);
}
